#pragma once

#include <functional>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <set>


typedef std::function<bool(void* user, const std::string& section, const std::string& key, const std::string& value, int line, const std::string& filename)> ini_callback_t;

bool is_comment(const std::string& line)
{
  if (line.find(';') == 0) return true;
  return false;
}

bool is_section(const std::string& line, std::string& section)
{
  if (line.find('[') == 0) {
    std::string::size_type pos = line.find(']');
    if (pos == std::string::npos) return false;
    section = line.substr(1, pos-1);
    return true;
  }
  else return false;
}

bool is_key_value(const std::string& line, std::string& key, std::string& value)
{
  std::string::size_type pos = line.find('=');
  if (pos == std::string::npos) return false;
  key = line.substr(0, pos);
  value = line.substr(pos+1);
  return true;
}

bool ini_parse(const std::string& name, ini_callback_t ini_callback, void* user)
{
  std::ifstream f(name, std::ifstream::in);

  if (f.is_open()) {
    std::string line;
    std::set<std::string> ini;
    int line_num = 0;
    std::string current_section;
    bool error = false;

    while (std::getline(f, line)) {
      std::string section, key, value;
      ++line_num;
      std::string line_num_str = name + "(" + std::to_string(line_num) + "): ";
      if (line == "") continue;
      if (is_comment(line)) continue;
      if (is_section(line, section)) {
        if (section == "") {
          std::cerr << line_num_str << "SECTION is empty\n";
          error = true;
        }
        else if (ini.find(section) == ini.end()) {
          current_section = section;
          ini.insert(section);
        }
        else {
          std::cerr << name << line_num_str << section << " is duplicated\n";
          error = true;
        }
      }
      else if (is_key_value(line, key, value)) {
        if (current_section == "") {
          std::cerr << line_num_str << "require SECTION\n";
          error = true;
        }
        else if (key == "") {
          std::cerr << line_num_str << "KEY isn't define\n";
          error = true;
        }
        else if (value == "") {
          std::cerr << line_num_str << "VALUE isn't define\n";
          error = true;
        }
        else {
          if (!ini_callback(user, current_section, key, value, line_num, name)) error = true;
        }
      }
      else {
        std::cerr << line_num_str << "invalid line\n";
        error = true;
      }
    }

    f.close();

    return (error ? false : true);
  }
  else {
    std::cerr << "[Argument Error] '" << name << "' is not exist.\n";
    return false;
  }

}
