#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>

// Function to extract words starting with a lowercase letter
std::string extractLowercaseWords(const std::string &text) {
    std::istringstream iss(text);
    std::string word, result;
    while (iss >> word) {
        if (islower(word[0])) {
            result += word + " ";
        }
    }
    return result;
}

// Function to convert text to lowercase
std::string lowercaseText(const std::string &text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to extract phone numbers
std::string extractPhoneNumbers(const std::string &text) {
    std::string result;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        bool validPhoneNumber = true;
        for (char c : word) {
            if (!isdigit(c) && c != '-' && c != '(' && c != ')' && c != '.') {
                validPhoneNumber = false;
                break;
            }
        }
        if (validPhoneNumber) {
            result += word + " ";
        }
    }
    return result;
}

// Function to remove words with a specified length
std::string removeWordsByLength(const std::string &text, int length) {
    std::istringstream iss(text);
    std::string word, result;
    while (iss >> word) {
        if (word.length() != length) {
            result += word + " ";
        }
    }
    return result;
}

// Function to remove specific words or phrases
std::string removeSpecificWords(const std::string &text, const std::unordered_set<std::string> &wordsToRemove) {
    std::istringstream iss(text);
    std::string word, result;
    while (iss >> word) {
        if (wordsToRemove.find(word) == wordsToRemove.end()) {
            result += word + " ";
        }
    }
    return result;
}

// Function to extract word bigrams
std::string extractBigrams(const std::string &text) {
    std::istringstream iss(text);
    std::string word, prevWord, result;
    if (iss >> prevWord) {
        while (iss >> word) {
            result += prevWord + " " + word + " ";
            prevWord = word;
        }
    }
    return result;
}

// Function to extract plurals
std::string extractPlurals(const std::string &text) {
    std::istringstream iss(text);
    std::string word, result;
    while (iss >> word) {
        if (word.size() > 1 && word[word.size() - 1] == 's') {
            result += word + " ";
        }
    }
    return result;
}

// Function to extract singulars
std::string extractSingulars(const std::string &text) {
    std::istringstream iss(text);
    std::string word, result;
    while (iss >> word) {
        if (word.size() > 1 && word[word.size() - 1] != 's') {
            result += word + " ";
        }
    }
    return result;
}

// Function to remove singulars
std::string removeSingulars(const std::string &text) {
    std::istringstream iss(text);
    std::string word, result;
    while (iss >> word) {
        if (word.size() > 1 && word[word.size() - 1] == 's') {
            continue;
        }
        result += word + " ";
    }
    return result;
}

// Function to remove emojis
std::string removeEmojis(const std::string &text) {
    std::string result;
    for (char c : text) {
        if ((c >= 0x2100 && c <= 0x27BF) || (c >= 0x1F000 && c <= 0x1FAFF)) {
            continue; // Skip emojis
        }
        result += c;
    }
    return result;
}

// Function to remove duplicates
std::string removeDuplicates(const std::string &text) {
    std::istringstream iss(text);
    std::unordered_set<std::string> uniqueWords;
    std::string word, result;
    while (iss >> word) {
        if (uniqueWords.find(word) == uniqueWords.end()) {
            uniqueWords.insert(word);
            result += word + " ";
        }
    }
    return result;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string text = buffer.str();

    std::cout << "Original Text:" << std::endl;
    std::cout << text << std::endl << std::endl;

    std::string result;

    // Function calls
    result = extractLowercaseWords(text);
    std::cout << "Extracted Words Starting with Lowercase Letter:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = lowercaseText(text);
    std::cout << "Text after converting to Lowercase:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = extractPhoneNumbers(text);
    std::cout << "Extracted Phone Numbers:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = removeWordsByLength(text, 3);
    std::cout << "Text after removing words with length 3:" << std::endl;
    std::cout << result << std::endl << std::endl;

    std::unordered_set<std::string> wordsToRemove = {"Ara", "the", "is", "of", "and"};
    result = removeSpecificWords(text, wordsToRemove);
    std::cout << "Text after removing specific words:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = extractBigrams(text);
    std::cout << "Extracted Word Bigrams:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = extractPlurals(text);
    std::cout << "Extracted Plurals:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = extractSingulars(text);
    std::cout << "Extracted Singulars:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = removeSingulars(text);
    std::cout << "Text after removing Singulars:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = removeEmojis(text);
    std::cout << "Text after removing Emojis:" << std::endl;
    std::cout << result << std::endl << std::endl;

    result = removeDuplicates(text);
    std::cout << "Text after removing Duplicates:" << std::endl;
    std::cout << result << std::endl << std::endl;

    return 0;
}

