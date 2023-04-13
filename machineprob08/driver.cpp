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

int openFiles();
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
    openFiles();
    setTeams();
    outputToTeamsFile();
    return 0;
}

int openFiles()
{
    /* Open Files */
    infile.open("player.txt");
    if (!infile)
    {
        cout << "Error opening input file" << endl;
        return 1;
    }
    outfileTeam.open("teams.txt");
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



        if (tName == "Argentina")
        {
            PlayerCount[argentine]++;
        }
        else if (tName == "Brazil")
        {
            PlayerCount[brazil]++;
        }
        else if (tName == "France")
        {
            PlayerCount[france]++;
        }
        else if (tName == "Portugal")
        {
            PlayerCount[portugal]++;
        }
    }
}

void outputToTeamsFile()
{
    outfileTeam << "Argentine: " << PlayerCount[argentine] << endl;
    outfileTeam << "Brazil: " << PlayerCount[brazil] << endl;
    outfileTeam << "France: " << PlayerCount[france] << endl;
    outfileTeam << "Portugal: " << PlayerCount[portugal] << endl;
}