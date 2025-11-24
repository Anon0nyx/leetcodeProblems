#include <iostream>
#include <string>

int main() {
    std::string firstString, secondString;
    std::cin >> firstString >> secondString;

    for (size_t index = 0; index < firstString.size(); ++index) {
        char firstChar = firstString[index];
        char secondChar = secondString[index];

        if (firstChar >= 'A' && firstChar <= 'Z') {
            firstChar = firstChar - 'A' + 'a';
        }
        if (secondChar >= 'A' && secondChar <= 'Z') {
            secondChar = secondChar - 'A' + 'a';
        }

        if (firstChar < secondChar) {
            std::cout << -1 << std::endl;
            return 0;
        }
        if (firstChar > secondChar) {
            std::cout << 1 << std::endl;
            return 0;
        }
    }

    std::cout << 0 << std::endl;
    return 0;
}
