/*
 * Brady Butcher
 * 03.14.2023
 * CPS 171 - 01
 *
 * This program will read a table of characters from an input file, fill it into a 2-dimensional 8 by 8 array, and finds the words in the table using a word bank provided in the input file. The program will then output the words found in the table to an output file.
 */

/*#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

const int arrSize = 8;
char charArray[arrSize][arrSize];
string findWords();
bool checkWord(int i, int j, int di, int dj, const string &word);

string ifile_path("input.txt");
string ofile_path("output.txt");

ifstream inputFile;
ofstream outputFile;

int main()
{
    inputFile.open(ifile_path);
    if (!inputFile)
    { // file couldn't be opened
        std::cerr << "Error: Input file could not be opened" << endl;
        exit(1);
    }
    outputFile.open(ofile_path);
    if (!outputFile)
    { // file couldn't be opened
        std::cerr << "Error: Output file could not be opened" << endl;
        exit(1);
    }

    // Read in the table of characters
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            inputFile >> charArray[i][j];
        }
    }
}

bool checkWord(int i, int j, int di, int dj, const string &word)
{
    for (int k = 0; k < word.size(); k++)
    {
        int ni = i + k * di, nj = j + k * dj;
        if (ni < 0 || ni >= arrSize || nj < 0 || nj >= arrSize || charArray[ni][nj] != word[k])
            return false;
    }
    return true;
}

string findWords()
{
    string word;
    string wordFound;
    string wordBank;
    int wordCount = 0;

    // Read in the word bank
    while (inputFile >> word)
    {
        wordCount++;
        for (int i = 0; i < arrSize; i++)
        {
            for (int j = 0; j < arrSize; j++)
            {
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        if (di == 0 && dj == 0)
                            continue;
                        if (checkWord(i, j, di, dj, word))
                        {
                            wordFound += word + " ";
                            break;
                        }
                    }
                    if (!wordFound.empty())
                        break;
                }
                if (!wordFound.empty())
                    break;
            }
            if (!wordFound.empty())
                break;
        }
    }

    return wordFound;
}*/
#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

const int arrSize = 8;
char charArray[arrSize][arrSize];

void initialRead();
string wordBank();
string findWordsInArray();
bool checkWord(int i, int j, int di, int dj, const string &word);

string ifile_path("input.txt");
string ofile_path("output.txt");

ofstream outputFile(ofile_path);
ifstream inputFile(ifile_path);

int main()
{
    initialRead();
    string wordsFound = findWordsInArray();
    outputFile << wordsFound;
    return 0;
}

void initialRead()
{
    // Read in the table of characters
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            inputFile >> charArray[i][j];
        }
    }
}

string wordBank()
{
    string word;
    string wordBank;
    int wordCount = 0;

    // Read in the word bank
    while (inputFile >> word)
    {
        wordCount++;
        wordBank += word + " ";
    }
    return wordBank;
}

bool checkWord(int i, int j, int di, int dj, const string &word)
{
    for (int k = 0; k < word.size(); k++)
    {
        int ni = i + k * di, nj = j + k * dj;
        if (ni < 0 || ni >= arrSize || nj < 0 || nj >= arrSize || charArray[ni][nj] != word[k])
            return false;
    }
    return true;
}

string findWordsInArray()
{
    string wordList = wordBank();
    string wordFound;
    string word;
    int wordCount = 0;

    for (int i = 0; i < wordList.size(); i++)
    {
        if (wordList[i] == ' ')
        {
            wordCount++;
        }
    }

    for (int i = 0; i < wordCount; i++)
    {
        word = wordList.substr(0, wordList.find(' '));
        wordList = wordList.substr(wordList.find(' ') + 1);
        std::cout << word << endl;
    }

    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0)
                        continue;
                    if (checkWord(i, j, di, dj, word))
                    {
                        wordFound += word + " ";
                        break;
                    }
                }
                if (!wordFound.empty())
                    break;
            }
            if (!wordFound.empty())
                break;
        }
        if (!wordFound.empty())
            break;
    }

    return wordFound;
}