/*
 * Brady Butcher
 * 03.14.2023
 * CPS 171 - 01
 *
 * This program will read a table of characters from an input file, fill it into a 2-dimensional 8 by 8 array, and finds the words in the table using a word bank provided in the input file. The program will then output the words found in the table to an output file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int ROWS = 8;
const int COLS = 8;

// Define directions as integer offsets
const int HORIZONTAL[2] = {0, 1};
const int VERTICAL[2] = {1, 0};
const int DIAGONAL[2] = {1, 1};
const int DIAGONAL_INVERSE[2] = {-1, 1};

// Function to check if a word can be found in a given direction
bool checkDirection(char table[ROWS][COLS], int row, int col, string word, const int *direction)
{
    int wordLength = word.length();
    for (int i = 0; i < wordLength; i++)
    {
        int currentRow = row + i * direction[0];
        int currentCol = col + i * direction[1];
        if (currentRow < 0 || currentRow >= ROWS || currentCol < 0 || currentCol >= COLS || table[currentRow][currentCol] != word[i])
        {
            return false;
        }
    }
    return true;
}

// Function to find a word in the table
vector<int> findWord(char table[ROWS][COLS], string word)
{
    vector<int> result;
    int wordLength = word.length();
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            // Check horizontal direction
            if (checkDirection(table, row, col, word, HORIZONTAL))
            {
                result.push_back(row);
                result.push_back(col);
                result.push_back(0); // 0 for horizontal
                return result;
            }
            // Check vertical direction
            if (checkDirection(table, row, col, word, VERTICAL))
            {
                result.push_back(row);
                result.push_back(col);
                result.push_back(1); // 1 for vertical
                return result;
            }
            // Check diagonal direction
            if (checkDirection(table, row, col, word, DIAGONAL))
            {
                result.push_back(row);
                result.push_back(col);
                result.push_back(2); // 2 for diagonal
                return result;
            }
            // Check diagonal inverse direction
            if (checkDirection(table, row, col, word, DIAGONAL_INVERSE))
            {
                result.push_back(row);
                result.push_back(col);
                result.push_back(3); // 3 for diagonal inverse
                return result;
            }
        }
    }
    // Word not found
    return result;
}

int main()
{
    // Open input file
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: input file could not be opened." << endl;
        return 1;
    }
    ofstream outputFile("output.txt");
    if (!outputFile)
    {
        cerr << "Error: output file could not be opened." << endl;
        return 1;
    }

    // Read table from input file into 2D array
    char table[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            inputFile >> table[row][col];
        }
    }

    // Read words from input file and find them in the table
    int col1 = 15;
    int col2 = 15;
    int col3 = 15;
    int col4 = 15;
    outputFile << left << setfill(' ') << setw(col1) << "Word" << setw(col2) << "Row" << setw(col3) << "Column" << setw(col4) << "Direction" << endl;
    outputFile << left << setfill('-') << setw(col1 + col2 + col3 + col4) << "" << endl;
    string word;
    while (inputFile >> word)
    {
        vector<int> result = findWord(table, word);
        outputFile << left << setfill(' ') << setw(col1) << word;
        // Print location and direction of word if found, or indicate that the word could not be found
        if (result.empty())
        {
            outputFile << left << setfill(' ') << setw(col2 + col3) << " " << setw(col4) << "Not found" << endl;
        }
        else
        {
            outputFile << left << setfill(' ') << setw(col2) << result[0] + 1 << left << setw(col3) << result[1] + 1;
            switch (result[2])
            {
            case 0:
                outputFile << left << setw(col4) << "Horizontal" << endl;
                break;
            case 1:
                outputFile << left << setw(col4) << "Vertical" << endl;
                break;
            case 2:
                outputFile << left << setw(col4) << "Diagonal" << endl;
                break;
            case 3:
                outputFile << left << setw(col4) << "Diagonal inverse" << endl;
                break;
            }
        }
    }

    // Close input file
    inputFile.close();
    outputFile.close();

    return 0;
}
