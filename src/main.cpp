#include <SDL.h> // SDL2
#include <windows.h>
#include "vkmap.hpp"
#include "btnmap.hpp"
#include "ini.hpp"
#include <iostream>
#include <stdlib.h>


void send_key(WORD vk, bool is_press)
{
  static HKL hkl = GetKeyboardLayout(0);

  INPUT ip;
  ip.type = INPUT_KEYBOARD;
  ip.ki.wVk = vk;
  ip.ki.wScan = MapVirtualKeyEx(vk, 0, hkl);
  ip.ki.time = 0;
  ip.ki.dwExtraInfo = 0;
  ip.ki.dwFlags = is_press ? 0 : KEYEVENTF_KEYUP;

  SendInput(1, &ip, sizeof(INPUT));
}

bool load_config(void* user, const std::string& section, const std::string& key, const std::string& value, int line, const std::string& filename)
{
  WORD* btn2vk = static_cast<WORD*>(user);

  std::string line_num_str = filename + "(" + std::to_string(line) + "): ";

  if (std::string(section) == "button") {

    auto btn = g_btnmap.find(key);
    if (btn == g_btnmap.end()) {
      std::cerr << line_num_str << "'" << key << "' is invalid name for gamepad's button\n";
      return false;
    }

    auto vk = g_vkmap.find(value);
    if (vk == g_vkmap.end()) {
      std::cerr << line_num_str << "'" << key << "=" << value << "' is invalid name for key\n";
      return false;
    }
    btn2vk[btn->second] = vk->second;
  }
  else {
    std::cerr << line_num_str << "Unknown SECTION: '" << section << "'\n";
    return false;
  }

  return true;
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    std::cerr << "gamepad2key.exe require .ini file\n";
    std::cerr << "Usage: gamepad2key.exe [your.ini]\n";
    return -1;
  }

  if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0) {
    std::cerr << SDL_GetError() << std::endl;
    return -1;
  }

  atexit(SDL_Quit);

  WORD btn2vk[32];
  memset(btn2vk, 0, sizeof(btn2vk));

  if (ini_parse(argv[1], load_config, btn2vk) == false) {
    std::cerr << "\n*** Failed to launch gamepad2key.exe ***\n";
    goto game_over;
  }

  SDL_GameController* pad = NULL;

  for (;;) {

    SDL_Event ev;
    SDL_WaitEvent(&ev);

    if(ev.type == SDL_CONTROLLERDEVICEADDED) {
      if (SDL_IsGameController(ev.cdevice.which)) {
        SDL_GameController* c = SDL_GameControllerOpen(ev.cdevice.which);
        if (c) {
          pad = c;
          std::cout << "Added: " << SDL_GameControllerName(c) << std::endl;
        }
      }
      else {
        std::cerr << "'" << SDL_JoystickNameForIndex(ev.cdevice.which) << "' is not supported gamepad\n";
      }
    }
    else if(ev.type == SDL_CONTROLLERDEVICEREMOVED) {
      if (pad == SDL_GameControllerFromInstanceID(ev.cdevice.which)) pad = NULL;
    }
    else if(ev.type == SDL_CONTROLLERBUTTONDOWN) {
      if (pad == SDL_GameControllerFromInstanceID(ev.cbutton.which)) {
        send_key(btn2vk[ev.cbutton.button], true);
      }
    }
    else if(ev.type == SDL_CONTROLLERBUTTONUP) {
      if (pad == SDL_GameControllerFromInstanceID(ev.cbutton.which)) {
        send_key(btn2vk[ev.cbutton.button], false);
      }
    }

  }

game_over:
  return 0;
}
