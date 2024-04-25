#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> extractPhoneNumbers(const std::string& text) {
    std::regex phoneRegex(R"(\b(?:[\+]?[(]?\d{1,3}[)]?[-\s\.]?)?(?:\d{3}[-\s\.]?)?\d{3}[-\s\.]?\d{4}(?:\d{2})?\b)");
    std::vector<std::string> phoneNumbers;
    
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), phoneRegex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        phoneNumbers.push_back(match.str());
    }
    
    return phoneNumbers;
}

int main() {
    std::string text = "Here are some phone numbers: 123-456-7890, (123) 456-7890, 123.456.7890, +37491551544, +1 (123) 456-7890, 123 456 7890, 1234567890";
    std::vector<std::string> extractedNumbers = extractPhoneNumbers(text);
        for(const auto& number : extractedNumbers) {
        std::cout << number << std::endl;
    }
    
    return 0;
}
