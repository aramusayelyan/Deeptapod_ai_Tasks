#include <iostream>
#include <string>

void remove_specific_words(std::string& text, const std::string& word_to_remove) {
    size_t pos = 0;

    while ((pos = text.find(word_to_remove, pos)) != -1) {
        text.erase(pos, word_to_remove.length());
    }
}

int main() {
    std::string text = "Remove specific words or phrases from this text.";
    std::string word_to_remove;

    std::cout << "Enter the word or phrase to remove: ";
    std::getline(std::cin, word_to_remove);
    
    remove_specific_words(text, word_to_remove);
    
    std::cout << "Text with \"" << word_to_remove << "\" removed: " << text << std::endl;
    
    return 0;
}
