#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <regex>

std::string extract_plurals(const std::string& text) {
    std::vector<std::string> ruler = {
        "Children", "Feet", "Teeth", "People", "Men", 
        "Women", "Mice", "Geese", "Oxen", "Data"
    };
    
    std::set<std::string> words = {
        "bus", "lens", "glass", "class", "process",
        "boss", "address", "emphasis", "gas", "loss"
    };

    std::string plurals;

    std::regex plural_regex("\\b(\\w+)(?:'s|es|s)\\b", std::regex_constants::icase);

    std::sregex_iterator iter(text.begin(), text.end(), plural_regex);
    std::sregex_iterator end;

    while (iter != end) {
        std::string word = (*iter)[0];
        if (std::find(ruler.begin(), ruler.end(), word) != ruler.end()) {
            plurals += word + " ";
        }
        else if (words.find(word) == words.end()) {
            plurals += word + " ";
        }
        ++iter;
    }

    return plurals;
}

int main() {
    std::string text = "Children's toys are on the floor. Cats chase mice and dogs. bus ";
    std::string plurals = extract_plurals(text);
    std::cout << "extracted plurals: " << plurals << std::endl;
    return 0;
}
