#include <iostream>
#include <string>
#include <regex>

std::string remove_emojis(const std::string& text) {
    std::regex emoji_regex(R"([\u0080-\uFFFF])");
        return std::regex_replace(text, emoji_regex, "");
}

int main() {
    std::string text = "I love coding! 💻 Programming is so much fun. Let's build amazing projects together! 🚀🌟";
    
    std::string cleaned_text = remove_emojis(text);
    
    std::cout << "Text after removing emojis:\n" << cleaned_text << std::endl;
    
    return 0;
}
