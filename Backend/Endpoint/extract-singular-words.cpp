#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

bool isSingular(const std::string& word, const std::set<std::string>& givenWords, const std::vector<std::string>& ruler) {
    if (givenWords.find(word) != givenWords.end()) {
        return false; 
    }
    
    auto it = std::find(ruler.begin(), ruler.end(), word);
    return it == ruler.end();  
}

std::set<std::string> extractSingulars(const std::string& text, const std::set<std::string>& givenWords, const std::vector<std::string>& ruler) {
    std::set<std::string> singulars; 
    
    std::regex wordRegex("\\b\\w+\\b");
    std::sregex_iterator it(text.begin(), text.end(), wordRegex);
    std::sregex_iterator end;
    for (; it != end; ++it) {
        std::string word = it->str();
        if (isSingular(word, givenWords, ruler)) {
            singulars.insert(word); 
        }
    }
    
    return singulars;
}

int main() {
    std::set<std::string> givenWords = {
        "bus",
        "lens",
        "glass",
        "class",
        "process",
        "boss",
        "address",
        "emphasis",
        "gas",
        "loss",
        "its"
    };

    std::vector<std::string> ruler = {
        "Children",
        "Feet",
        "Teeth",
        "People",
        "Men",
        "Women",
        "Mice",
        "Geese",
        "Oxen",
        "Data"
    };

    std::string text = "Extracts singular forms of words like cars, dogs, and cats from the text.";

    std::set<std::string> singulars = extractSingulars(text, givenWords, ruler);

    std::cout << "Singular forms extracted from the text:" << std::endl;
    for (const auto& singular : singulars) {
        std::cout << singular << std::endl;
    }

    return 0;
}
