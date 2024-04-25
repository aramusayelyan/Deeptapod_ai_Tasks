#include <iostream>
#include <string>
#include <sstream>

void remove_words_by_length(std::string& text, int length_to_remove) {
    std::stringstream ss(text);
    std::string word;
    std::string new_text;

    while (ss >> word) {
        if (word.length() != length_to_remove) {
            new_text += word + " ";
        }
    }

    if (!new_text.empty()) {
        new_text.pop_back();
    }

    text = new_text;
}

int main() {
    std::string text = "Remove words with a specified length from this text.";
    int length_to_remove;

    std::cout << "Enter the length of the words to remove: ";
    std::cin >> length_to_remove;
    
    remove_words_by_length(text, length_to_remove);
    
    std::cout << "Text with words of length " << length_to_remove << " removed: " << text << std::endl;
    
    return 0;
}
