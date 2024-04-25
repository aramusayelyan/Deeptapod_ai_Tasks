#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function to retrieve words that begin with a lowercase letter
vector<string> extractLowercaseWords(const string& text) {
    vector<string> lowercaseWords;
    istringstream iss(text);
    string word;
    while (iss >> word) {
        if (islower(word[0])) {
            lowercaseWords.push_back(word);
        }
    }
    return lowercaseWords;
}

// Function to convert text to lowercase
string toLowercase(const string& text) {
    string lowercaseText = text;
    transform(lowercaseText.begin(), lowercaseText.end(), lowercaseText.begin(), ::tolower);
    return lowercaseText;
}

// Function to extract phone numbers from the text
vector<string> extractPhoneNumbers(const string& text) {
    regex phoneRegex("\\b\\d{3}[-.]?\\d{3}[-.]?\\d{4}\\b");
    vector<string> phoneNumbers;
    smatch match;
    string::const_iterator searchStart(text.cbegin());
    while (regex_search(searchStart, text.cend(), match, phoneRegex)) {
        phoneNumbers.push_back(match.str());
        searchStart = match.suffix().first;
    }
    return phoneNumbers;
}

// Function to remove words with a specified length from the text
string removeWordsByLength(const string& text, int length) {
    istringstream iss(text);
    ostringstream oss;
    string word;
    while (iss >> word) {
        if (word.length() != length) {
            oss << word << " ";
        }
    }
    return oss.str();
}

// Function to remove specific words or phrases from the text
string removeSpecificWords(const string& text, const unordered_set<string>& wordsToRemove) {
    string result = text;
    for (const string& word : wordsToRemove) {
        size_t pos = 0;
        while ((pos = result.find(word, pos)) != string::npos) {
            result.erase(pos, word.length());
        }
    }
    return result;
}

// Function to extract pairs of consecutive words (bigrams) from the text
vector<string> extractBigrams(const string& text) {
    vector<string> bigrams;
    istringstream iss(text);
    string prevWord, currentWord;
    if (!(iss >> prevWord)) {
        return bigrams;
    }
    while (iss >> currentWord) {
        bigrams.push_back(prevWord + " " + currentWord);
        prevWord = currentWord;
    }
    return bigrams;
}

// Function to extract plural forms of words from the text
vector<string> extractPlurals(const string& text) {
    regex pluralRegex("\\b\\w+s\\b");
    vector<string> plurals;
    smatch match;
    string::const_iterator searchStart(text.cbegin());
    while (regex_search(searchStart, text.cend(), match, pluralRegex)) {
        plurals.push_back(match.str());
        searchStart = match.suffix().first;
    }
    return plurals;
}

// Function to extract singular forms of words from the text
vector<string> extractSingulars(const string& text) {
    regex singularRegex("\\b\\w+(?<!s)\\b");
    vector<string> singulars;
    smatch match;
    string::const_iterator searchStart(text.cbegin());
    while (regex_search(searchStart, text.cend(), match, singularRegex)) {
        singulars.push_back(match.str());
        searchStart = match.suffix().first;
    }
    return singulars;
}

// Function to remove singular forms of words from the text
string removeSingulars(const string& text) {
    regex singularRegex("\\b\\w+(?<!s)\\b");
    return regex_replace(text, singularRegex, "");
}

// Function to remove emojis from the text
string removeEmojis(const string& text) {
    regex emojiRegex("[\\x{1F600}-\\x{1F64F}\\x{1F300}-\\x{1F5FF}\\x{1F680}-\\x{1F6FF}\\x{2600}-\\x{26FF}\\x{2700}-\\x{27BF}]+");
    return regex_replace(text, emojiRegex, "");
}

// Function to remove duplicate lines or sentences from the text
string removeDuplicates(const string& text) {
    istringstream iss(text);
    unordered_set<string> uniqueLines;
    ostringstream oss;
    string line;
    while (getline(iss, line)) {
        if (uniqueLines.insert(line).second) {
            oss << line << endl;
        }
    }
    return oss.str();
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string text = buffer.str();

    // Call all functions with the provided text
    auto lowercaseWords = extractLowercaseWords(text);
    auto lowercaseText = toLowercase(text);
    auto phoneNumbers = extractPhoneNumbers(text);
    auto removedWordsByLength = removeWordsByLength(text, 5);
    unordered_set<string> wordsToRemove = {"Ara"};
    auto removedSpecificWords = removeSpecificWords(text, wordsToRemove);
    auto bigrams = extractBigrams(text);
    auto plurals = extractPlurals(text);
    auto singulars = extractSingulars(text);
    auto removedSingulars = removeSingulars(text);
    auto removedEmojis = removeEmojis(text);
    auto removedDuplicates = removeDuplicates(text);

    // Output results
    cout << "Extracted Lowercase Words:" << endl;
    for (const auto& word : lowercaseWords) {
        cout << word << endl;
    }
    cout << endl;

    cout << "Lowercase Text:" << endl;
    cout << lowercaseText << endl << endl;

    cout << "Extracted Phone Numbers:" << endl;
    for (const auto& number : phoneNumbers) {
        cout << number << endl;
    }
    cout << endl;

    cout << "Text after removing words with length 5:" << endl;
    cout << removedWordsByLength << endl << endl;

    cout << "Text after removing specific words:" << endl;
    cout << removedSpecificWords << endl << endl;

    cout << "Extracted Bigrams:" << endl;
    for (const auto& bigram : bigrams) {
        cout << bigram << endl;
    }
    cout << endl;

    cout << "Extracted Plurals:" << endl;
    for (const auto& plural : plurals) {
        cout << plural << endl;
    }
    cout << endl;

    cout << "Extracted Singulars:" << endl;
    for (const auto& singular : singulars) {
        cout << singular << endl;
    }
    cout << endl;

    cout << "Text after removing singulars:" << endl;
    cout << removedSingulars << endl << endl;

    cout << "Text after removing emojis:" << endl;
    cout << removedEmojis << endl << endl;

    cout << "Text after removing duplicates:" << endl;
    cout << removedDuplicates << endl << endl;

    return 0;
}

