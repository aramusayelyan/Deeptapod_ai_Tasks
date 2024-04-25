#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> extract_word_bigrams(const std::string& text) {
    std::vector<std::string> bigrams;
    std::stringstream ss(text);
    std::string prev_word, current_word;
        ss >> prev_word;
    while (ss >> current_word) {
        std::string bigram = prev_word + " " + current_word;
        bigrams.push_back(bigram);
        
        prev_word = current_word;
    }
    
    return bigrams;
}

int main() {
    std::string text = "Extracts pairs of consecutive words (bigrams) from the text.";
    
    std::vector<std::string> bigrams = extract_word_bigrams(text);
    
    std::cout << "Bigrams extracted from the text:" << std::endl;
    for (const auto& bigram : bigrams) {
        std::cout << bigram << std::endl;
    }
    
    return 0;
}
