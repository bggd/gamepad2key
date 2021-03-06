#pragma once

#include <map>
#include <string>
#include <SDL.h> // SDL2


std::map<std::string, int> g_btnmap = {
  {"A", SDL_CONTROLLER_BUTTON_A},
  {"B", SDL_CONTROLLER_BUTTON_B},
  {"X", SDL_CONTROLLER_BUTTON_X},
  {"Y", SDL_CONTROLLER_BUTTON_Y},
  {"Back", SDL_CONTROLLER_BUTTON_BACK},
  {"Guide", SDL_CONTROLLER_BUTTON_GUIDE},
  {"Start", SDL_CONTROLLER_BUTTON_START},
  {"LeftStick", SDL_CONTROLLER_BUTTON_LEFTSTICK},
  {"RightStick", SDL_CONTROLLER_BUTTON_RIGHTSTICK},
  {"LeftShoulder", SDL_CONTROLLER_BUTTON_LEFTSHOULDER},
  {"RightShoulder", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER},
  {"Up", SDL_CONTROLLER_BUTTON_DPAD_UP},
  {"Down", SDL_CONTROLLER_BUTTON_DPAD_DOWN},
  {"Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT},
  {"Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT}
};
