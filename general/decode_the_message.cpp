#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string  decode_message(std::string key, std::string message) {
  int curr_val = int('a');
  std::unordered_map<char, char> new_alphabet;

  for (auto character : key) {
    if (character == ' ') continue;
    if (new_alphabet[character] == '\0') {
      new_alphabet[character] = char(curr_val);
      curr_val++;
    }
  }

  std::string new_message = "";
  for (auto letter : message) {
    if (letter == ' ') {
      new_message += ' ';
    } else {
      new_message += new_alphabet[letter];
    }
  }
  return new_message;
}

int main() {
  std::string key = "the quick brown fox jumps over the lazy dog";
  std::string message = "vkbs bs t suepuv";

  std::cout << decode_message(key, message) << std::endl;
  
  return 0;
}
