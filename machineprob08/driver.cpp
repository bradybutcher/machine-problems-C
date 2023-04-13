#include <iostream>
#include <string>
#include <fstream>
#include "teams.h"
#include "player.h"

using namespace std;

ifstream infile;
ofstream outfileTeam;
ofstream outfile;

TeamClass thisTeam;
PlayerClass thisPlayer;

int PlayerCount[4] = {0};

void setTeams();
void outputToTeamsFile();

enum teams
{
    argentine,
    brazil,
    france,
    portugal,
    invalid
};

int main()
{
    /* Open Files */
    infile.open("player.txt");
    if (!infile)
    {
        cout << "Error opening input file" << endl;
        return 1;
    }
    outfileTeam.open("output.txt");
    if (!outfileTeam)
    {
        cout << "Error opening teams output file" << endl;
        return 1;
    }
    outfile.open("output.txt");
    if (!outfile)
    {
        cout << "Error opening output file" << endl;
        return 1;
    }

    setTeams();
    // outputToTeamsFile();
    return 0;
}

void setTeams()
{
    string tName, pFName, pLName;
    int pNum, pPoints;

    while (infile >> tName >> pNum >> pFName >> pLName >> pPoints)
    {
        thisTeam.setTeamName(tName);
        thisPlayer.setPlayerNumber(pNum);
        thisPlayer.setPlayerFName(pFName);
        thisPlayer.setPlayerLName(pLName);
        thisPlayer.setPlayerPoints(pPoints);
    }
}

void outputToTeamsFile()
{
}