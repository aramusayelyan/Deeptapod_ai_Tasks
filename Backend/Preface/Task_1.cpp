#include <iostream>
#include <fstream>
#include <string>

// The half of the task is nicely done. The implementation of checkUpper, end_letter, etc.. by hand is appreciated. 
// Choose one exact coding style for you (CamelCase - ex: checkUpper, snake_case - ex: check_upper, etc.), don't mix them.

bool checkUpper(std::string word)
{
    if (word[0] >= 65 && word[0] <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }

    // avoid excessive "if-else", just type "return word[0] >= 65 && word[0] <= 90"
}

bool end_letter(std::string word) 
// Pass std::string by reference, so that the whole object isn't copied. check out "pass by reference vs pass by copy".
{
    int size = word.size();
    if ((word[size - 1] >= 97 && word[size - 1] <= 122) || (word[size - 1] >= 65 && word[size - 1] <= 90))
    {
        return true;
    }
    else
    {
        return false;
    }

    // the same issue here
}

std::string size_1(std::string word)
{
    return word.substr(0, word.length() - 1);
}

int main()
{
    int index = 0;
    std::string db[2000]; // Հայկը ասելա նավսյակի շատ վերցրեք եթե չգիտեք հաստատ չափը 😂
    // :D 
    std::ifstream file("input.txt");
    std::ofstream ofile("output.txt");
    std::ifstream dbfile("db.txt");
    std::string word;
    if (!file.is_open())
    {
        std::cout << "Error in open file";
    }
    if (!ofile.is_open())
    {
        std::cout << "Error in open file";
    }

    while (dbfile >> db[index])
    {
        ++index;
    }

    while (file >> word)
    {
        if (checkUpper(word))
        {
            if (!end_letter(word))
            {
                word = size_1(word);
                std::cout << word << std::endl;
            }
            for (int i = 0; i < index; ++i)
            {
                if (word == db[i])
                {
                    word = "X";
                }
            }
        }
        ofile << word << ' ';
    }

 
    ofile.close();
    file.close();
    dbfile.close();
    return 0;
}
