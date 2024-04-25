#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

std::string& toLowercase(std::string& text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return text;
}

int main() {
    std::string text = "Converts ALL Text to LOWERCASE.";
    std::string lowercaseText = toLowercase(text);
    std::cout << lowercaseText << std::endl;
    return 0;
}
