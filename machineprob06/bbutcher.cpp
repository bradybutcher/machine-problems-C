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
#include <array>

using namespace std;

const int arrSize = 8;
char array[arrSize][arrSize];

string ifile_path("input.txt");
string ofile_path("output.txt");

ifstream inputFile;
ofstream outputFile;

void main()
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
}
