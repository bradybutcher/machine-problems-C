/*
 * Brady Butcher
 * CPS 171 - 01
 * 3.29.2023
 *
 * Program Description:
 * This program will read in a file of words and check them against the first word in the line. It detects four types of errors: Character substitution, character transposition, character deletion, and character insertion. It will also detect if there is more than one error in a word.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

enum ErrorType
{
    CORRECT,
    SUBSTITUTION,
    TRANSPOSITION,
    DELETION,
    INSERTION,
    ERROR,
    NONE,
};

int correctWordCount = 0;
int substitutionCount = 0;
int transpositionCount = 0;
int deletionCount = 0;
int insertionCount = 0;
int errorCount = 0;

ErrorType checkError(std::string correctWord, std::string incorrectWord)
{
    if (correctWord.length() != incorrectWord.length())
    {
        return INSERTION; // Extra character inserted
    }

    int errorCount = 0;
    for (int i = 0; i < correctWord.length(); i++)
    {
        if (correctWord[i] != incorrectWord[i])
        {
            errorCount++;

            if (errorCount > 1)
            {
                return ERROR; // More than one error
            }

            if (i + 1 < correctWord.length() && correctWord[i] == incorrectWord[i + 1] && correctWord[i + 1] == incorrectWord[i])
            {
                return TRANSPOSITION; // Adjacent characters transposed
            }

            if (correctWord[i] == incorrectWord[i + 1])
            {
                return DELETION; // Character deleted
            }

            if (correctWord[i + 1] == incorrectWord[i + 1])
            {
                return SUBSTITUTION; // Character substituted
            }
        }
    }

    return NONE; // No error detected
}

int main()
{
    std::ifstream inputFile("mp7spelling.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open input file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::vector<std::string> words;
        std::istringstream iss(line);
        std::string word;

        while (iss >> word)
        {
            words.push_back(word);
        }

        std::string correctWord = words[0];
        std::cout << "The Word being checked is: " << correctWord << std::endl;
        for (int i = 1; i < words.size(); i++)
        {
            ErrorType error = checkError(correctWord, words[i]);

            switch (error)
            {
            case CORRECT:
                correctWordCount++;
                std::cout << "The word \"" << words[i] << "\" is spelled correctly.\n";
                break;
            case SUBSTITUTION:
                substitutionCount++;
                std::cout << "Character substitution error detected in word \"" << words[i] << "\".\n";
                break;
            case TRANSPOSITION:
                transpositionCount++;
                std::cout << "Character transposition error detected in word \"" << words[i] << "\".\n";
                break;
            case DELETION:
                deletionCount++;
                std::cout << "Character deletion error detected in word \"" << words[i] << "\".\n";
                break;
            case INSERTION:
                insertionCount++;
                std::cout << "Character insertion error detected in word \"" << words[i] << "\".\n";
                break;
            case ERROR:
                errorCount++;
                std::cout << "More than one error detected in word \"" << words[i] << "\".\n";
                break;
            case NONE:
                std::cout << "No spelling errors detected in word \"" << words[i] << "\".\n";
                break;
            default:
                std::cout << "Unknown error type.\n";
                break;
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Spelling Correction by Brady Butcher" << std::endl;
    std::cout << "Correct Word Count: " << correctWordCount << std::endl;
    std::cout << "Substitution Count: " << substitutionCount << std::endl;
    std::cout << "Transposition Count: " << transpositionCount << std::endl;
    std::cout << "Deletion Count: " << deletionCount << std::endl;
    std::cout << "Insertion Count: " << insertionCount << std::endl;
    std::cout << "Error Count: " << errorCount << std::endl;

    inputFile.close();
    return 0;
}
