#include <iostream>
#include <string>
#include <sstream>
#include <set>

std::set<std::string> remove_duplicates(const std::string& text) {
    std::stringstream ss(text); 
    std::set<std::string> unique_lines;
    std::string line;
    while (std::getline(ss, line)) {
        unique_lines.insert(line);
    }
    return unique_lines;
}

int main() {
    std::string text = "This is the first line.\n"
                       "This is the second line.\n"
                       "This is the first line.\n"
                       "This is the third line.\n"
                       "This is the second line.\n";

    std::set<std::string> unique_lines = remove_duplicates(text);
    std::cout << "Unique lines:\n";
    for (const auto& line : unique_lines) {
        std::cout << line << '\n';
    }

    return 0;
}
