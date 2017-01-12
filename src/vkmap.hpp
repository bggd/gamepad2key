#pragma once

#include <windows.h>
#include <map>
#include <string>


std::map<std::string, WORD> g_vkmap = {
  {"lbutton", VK_LBUTTON},
  {"rbutton", VK_RBUTTON},
  {"cancel", VK_CANCEL},
  {"mbutton", VK_MBUTTON},
  {"xbutton1", VK_XBUTTON1},
  {"xbutton2", VK_XBUTTON2},
  {"back", VK_BACK},
  {"tab", VK_TAB},
  {"clear", VK_CLEAR},
  {"return", VK_RETURN},
  {"shift", VK_SHIFT},
  {"control", VK_CONTROL},
  {"menu", VK_MENU},
  {"pause", VK_PAUSE},
  {"capital", VK_CAPITAL},
  {"kana", VK_KANA},
  {"hangul", VK_HANGUL},
  {"junja", VK_JUNJA},
  {"final", VK_FINAL},
  {"hanja", VK_HANJA},
  {"kanji", VK_KANJI},
  {"escape", VK_ESCAPE},
  {"convert", VK_CONVERT},
  {"nonconvert", VK_NONCONVERT},
  {"accept", VK_ACCEPT},
  {"modechange", VK_MODECHANGE},
  {"space", VK_SPACE},
  {"prior", VK_PRIOR},
  {"next", VK_NEXT},
  {"end", VK_END},
  {"home", VK_HOME},
  {"left", VK_LEFT},
  {"up", VK_UP},
  {"right", VK_RIGHT},
  {"down", VK_DOWN},
  {"select", VK_SELECT},
  {"print", VK_PRINT},
  {"execute", VK_EXECUTE},
  {"snapshot", VK_SNAPSHOT},
  {"insert", VK_INSERT},
  {"delete", VK_DELETE},
  {"help", VK_HELP},
  {"0", '0'},
  {"1", '1'},
  {"2", '2'},
  {"3", '3'},
  {"4", '4'},
  {"5", '5'},
  {"6", '6'},
  {"7", '7'},
  {"8", '8'},
  {"9", '9'},
  {"a", 'A'},
  {"b", 'B'},
  {"c", 'C'},
  {"d", 'D'},
  {"e", 'E'},
  {"f", 'F'},
  {"g", 'G'},
  {"h", 'H'},
  {"i", 'I'},
  {"j", 'J'},
  {"k", 'K'},
  {"l", 'L'},
  {"m", 'M'},
  {"n", 'N'},
  {"o", 'O'},
  {"p", 'P'},
  {"q", 'Q'},
  {"r", 'R'},
  {"s", 'S'},
  {"t", 'T'},
  {"u", 'U'},
  {"v", 'V'},
  {"w", 'W'},
  {"x", 'X'},
  {"y", 'Y'},
  {"z", 'Z'},
  {"lwin", VK_LWIN},
  {"rwin", VK_RWIN},
  {"apps", VK_APPS},
  {"sleep", VK_SLEEP},
  {"numpad0", VK_NUMPAD0},
  {"numpad1", VK_NUMPAD1},
  {"numpad2", VK_NUMPAD2},
  {"numpad3", VK_NUMPAD3},
  {"numpad4", VK_NUMPAD4},
  {"numpad5", VK_NUMPAD5},
  {"numpad6", VK_NUMPAD6},
  {"numpad7", VK_NUMPAD7},
  {"numpad8", VK_NUMPAD8},
  {"numpad9", VK_NUMPAD9},
  {"multiply", VK_MULTIPLY},
  {"add", VK_ADD},
  {"separator", VK_SEPARATOR},
  {"subtract", VK_SUBTRACT},
  {"decimal", VK_DECIMAL},
  {"divide", VK_DIVIDE},
  {"f1", VK_F1},
  {"f2", VK_F2},
  {"f3", VK_F3},
  {"f4", VK_F4},
  {"f5", VK_F5},
  {"f6", VK_F6},
  {"f7", VK_F7},
  {"f8", VK_F8},
  {"f9", VK_F9},
  {"f10", VK_F10},
  {"f11", VK_F11},
  {"f12", VK_F12},
  {"f13", VK_F13},
  {"f14", VK_F14},
  {"f15", VK_F15},
  {"f16", VK_F16},
  {"f17", VK_F17},
  {"f18", VK_F18},
  {"f19", VK_F19},
  {"f20", VK_F20},
  {"f21", VK_F21},
  {"f22", VK_F22},
  {"f23", VK_F23},
  {"f24", VK_F24},
  {"numlock", VK_NUMLOCK},
  {"scroll", VK_SCROLL},
  {"scroll", VK_SCROLL},
  {"lshift", VK_LSHIFT},
  {"rshift", VK_RSHIFT},
  {"lcontrol", VK_LCONTROL},
  {"rcontrol", VK_RCONTROL},
  {"lmenu", VK_LMENU},
  {"rmenu", VK_RMENU},
  {"browser_back", VK_BROWSER_BACK},
  {"browser_forward", VK_BROWSER_FORWARD},
  {"browser_refresh", VK_BROWSER_REFRESH},
  {"browser_stop", VK_BROWSER_STOP},
  {"browser_search", VK_BROWSER_SEARCH},
  {"browser_favorites", VK_BROWSER_FAVORITES},
  {"browser_home", VK_BROWSER_HOME},
  {"volume_mute", VK_VOLUME_MUTE},
  {"volume_down", VK_VOLUME_DOWN},
  {"volume_up", VK_VOLUME_UP},
  {"media_next_track", VK_MEDIA_NEXT_TRACK},
  {"media_prev_track", VK_MEDIA_PREV_TRACK},
  {"media_stop", VK_MEDIA_STOP},
  {"media_play_pause", VK_MEDIA_PLAY_PAUSE},
  {"launch_mail", VK_LAUNCH_MAIL},
  {"launch_media_slect", VK_LAUNCH_MEDIA_SELECT},
  {"launch_app1", VK_LAUNCH_APP1},
  {"launch_app2", VK_LAUNCH_APP2},
  {"oem_1", VK_OEM_1},
  {"oem_plus", VK_OEM_PLUS},
  {"oem_comma", VK_OEM_COMMA},
  {"oem_minus", VK_OEM_MINUS},
  {"oem_period", VK_OEM_PERIOD},
  {"oem_2", VK_OEM_2},
  {"oem_3", VK_OEM_3},
  {"oem_4", VK_OEM_4},
  {"oem_5", VK_OEM_5},
  {"oem_6", VK_OEM_6},
  {"oem_7", VK_OEM_7},
  {"oem_8", VK_OEM_8},
  {"oem_102", VK_OEM_102},
  {"processkey", VK_PROCESSKEY},
  {"packet", VK_PACKET},
  {"attn", VK_ATTN},
  {"crsel", VK_CRSEL},
  {"exsel", VK_EXSEL},
  {"ereof", VK_EREOF},
  {"play", VK_PLAY},
  {"zoom", VK_ZOOM},
  {"noname", VK_NONAME},
  {"pa1", VK_PA1},
  {"oem_clear", VK_OEM_CLEAR}
};
