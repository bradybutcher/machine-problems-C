#include <iostream>
#include <string>
#include <fstream>
#include "teams.h"
#include "player.h"

using namespace std;

ifstream infile;
ofstream outfile;

TeamClass team;
PlayerClass player;

int numPlayers = 11;

void setTeams();

int main()
{
    /* Open Files */
    infile.open("player.txt");
    if (!infile)
    {
        cout << "Error opening input file" << endl;
        return 1;
    }
    outfile.open("output.txt");
    if (!outfile)
    {
        cout << "Error opening output file" << endl;
        return 1;
    }

    /* Set vars */
    team.numPlayers = numPlayers;
    setTeams();
    return 0;
}

void setTeams()
{
    string tName, pFName, pLName;
    int pNum, pPoints;

    while (!infile.eof())
    {
        infile >> tName >> pNum >> pFName >> pLName >> pPoints;
        team.setTeamName(tName);
         //player.setPlayerNumber(pNum);
         //player.setPlayerFName(pFName);
         //player.setPlayerLName(pLName);
         //player.setPlayerPoints(pPoints);
    }
}