#include <iostream>
#include <fstream>
#include <array>

using namespace std;

const int arrSize = 8;

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