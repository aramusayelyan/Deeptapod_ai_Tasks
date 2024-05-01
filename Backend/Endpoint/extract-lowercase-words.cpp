#include <iostream>
#include <regex>
#include <set>
#include <string>

std::set<std::string> extractUniqueLowercaseWords(const std::string& text) {
    std::regex wordRegex("\\b[a-z]\\w*\\b");
    std::set<std::string> uniqueLowercaseWords;
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), wordRegex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        uniqueLowercaseWords.insert(match.str());
    }
    return uniqueLowercaseWords;
}

int main() {
    std::string text = "This is a Sample text to Extract words starting with a lowercase letter. Text text";
    std::set<std::string> uniqueLowercaseWords = extractUniqueLowercaseWords(text);
    for (const auto& word : uniqueLowercaseWords) {
        std::cout << word << std::endl;
    }
    return 0;
}
