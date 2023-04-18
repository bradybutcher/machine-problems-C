/*
 * Author: Brady Butcher
 * Date: 4/18/2023
 * Description: Driver file for the soccer team program which takes in a file of players and their stats and outputs the players to their respective teams, collecting information about each player to compare team and player points. The teams and players from the input file are cleaned up and outputted to the teams.txt file.
 * Input: player.txt
 * Output: output.txt, teams.txt
 * User Created Header Files: teams.h, player.h
 * Assumptions: The input file is formatted correctly and the output files are created.
 * Pseudocode:
 * 1. Open the files
 * 2. Create a player and team global object
 * 3. Create an array of team objects, player objects, and player counts
 * 4. Create a while loop to read in the input file
 * 5. Set player information and team information based on team name
 * 6. Increment the player count for the team
 * 7. Create a for loop to output the teams to the teams output file
 * 8. Create a for loop to output the players and information to the teams output file
 * 9. Create a for loop to output the teams to the output file
 * 10. Create a for loop to output the player with the most points on each team
 * 11. Set the player with the most points and output to output file
 * 12. Output the top two teams with the most points
 * 13. Close the input and output files
 * 
 * GitHub Repository: https://github.com/bradybutcher/machine-problems-C/tree/main/machineprob08
 */

#include <iostream>
#include <string>
#include <fstream>
#include "teams.h"
#include "player.h"

using namespace std;

ifstream infile;
ofstream outfileTeam;
ofstream outfile;

int PlayerCount[4] = {0};

int openFiles();
void setTeams();
void outputToTeamsFile();
void output();

PlayerClass thisPlayer;
TeamClass thisTeam[4];

enum teams
{
    argentine,
    brazil,
    france,
    portugal,
};

int main()
{
    openFiles();
    setTeams();
    outputToTeamsFile();
    output();
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

        thisPlayer.setPlayerNumber(pNum);
        thisPlayer.setPlayerFName(pFName);
        thisPlayer.setPlayerLName(pLName);
        thisPlayer.setPlayerName();
        thisPlayer.setPlayerPoints(pPoints);

        if (tName == "ARGENTINE" || tName == "argentine" || tName == "Argentina" || tName == "argentina")
        {
            thisTeam[argentine].setPlayer(thisPlayer, PlayerCount[argentine]);
            thisTeam[argentine].setTeamName(tName);
            thisTeam[argentine].setTeamPoints(thisTeam[argentine].getTeamPoints() + thisPlayer.getPlayerPoints());
            PlayerCount[argentine]++;
        }
        else if (tName == "BRAZIL" || tName == "brazil" || tName == "Brazil")
        {
            thisTeam[brazil].setPlayer(thisPlayer, PlayerCount[brazil]);
            thisTeam[brazil].setTeamName(tName);
            thisTeam[brazil].setTeamPoints(thisTeam[brazil].getTeamPoints() + thisPlayer.getPlayerPoints());
            PlayerCount[brazil]++;
        }
        else if (tName == "FRANCE" || tName == "france" || tName == "France")
        {
            thisTeam[france].setPlayer(thisPlayer, PlayerCount[france]);
            thisTeam[france].setTeamName(tName);
            thisTeam[france].setTeamPoints(thisTeam[france].getTeamPoints() + thisPlayer.getPlayerPoints());
            PlayerCount[france]++;
        }
        else if (tName == "PORTUGAL" || tName == "portugal" || tName == "Portugal")
        {
            thisTeam[portugal].setPlayer(thisPlayer, PlayerCount[portugal]);
            thisTeam[portugal].setTeamName(tName);
            thisTeam[portugal].setTeamPoints(thisTeam[portugal].getTeamPoints() + thisPlayer.getPlayerPoints());
            PlayerCount[portugal]++;
        }
    }
}

void outputToTeamsFile()
{
    for (int i = argentine; i <= portugal; i++)
    {
        TeamClass team;
        PlayerClass player;
        if (i == argentine)
        {
            team.setTeamName("ARGENTINE");
            outfileTeam << team.getTeamName() << endl;
            for (int j = 0; j < PlayerCount[argentine]; j++)
            {
                player = thisTeam[argentine].getPlayer(j);
                outfileTeam << player.getPlayerNumber() << " " << player.getPlayerName() << " " << player.getPlayerPoints() << endl;
            }
            outfileTeam << endl;
        }
        else if (i == brazil)
        {
            team.setTeamName("BRAZIL");
            outfileTeam << team.getTeamName() << endl;
            for (int j = 0; j < PlayerCount[brazil]; j++)
            {
                player = thisTeam[brazil].getPlayer(j);
                outfileTeam << player.getPlayerNumber() << " " << player.getPlayerName() << " " << player.getPlayerPoints() << endl;
            }
            outfileTeam << endl;
        }
        else if (i == france)
        {
            team.setTeamName("FRANCE");
            outfileTeam << team.getTeamName() << endl;
            for (int j = 0; j < PlayerCount[france]; j++)
            {
                player = thisTeam[france].getPlayer(j);
                outfileTeam << player.getPlayerNumber() << " " << player.getPlayerName() << " " << player.getPlayerPoints() << endl;
            }
            outfileTeam << endl;
        }
        else if (i == portugal)
        {
            team.setTeamName("PORTUGAL");
            outfileTeam << team.getTeamName() << endl;
            for (int j = 0; j < PlayerCount[portugal]; j++)
            {
                player = thisTeam[portugal].getPlayer(j);
                outfileTeam << player.getPlayerNumber() << " " << player.getPlayerName() << " " << player.getPlayerPoints() << endl;
            }
            outfileTeam << endl;
        }
    }
}

void output()
{
    int col1 = 20;
    int col2 = 15;
    int col3 = 15;
    for (int i = 1; i <= 4; i++)
    {
        outfile << "TEAM #" << i << endl;
        outfile << "Team's Name: " << thisTeam[i - 1].getTeamName() << endl;
        outfile << "Team's Total Points: " << thisTeam[i - 1].getTeamPoints() << endl;
        outfile << endl;
        outfile << "Players of Team #" << i << ": " << thisTeam[i - 1].getTeamName() << endl;
        outfile << endl;
        outfile << setw(col1) << left << "Player Name"
                << setw(col2) << setfill(' ') << "Player Number"
                << setw(col3) << setfill(' ') << "Player Points" << endl;
        outfile << setw(col1 + col2 + col3) << setfill('*') << "" << endl;
        for (int j = 0; j < PlayerCount[i - 1]; j++)
        {
            PlayerClass thisPlayer = thisTeam[i - 1].getPlayer(j);
            outfile << setw(col1) << left << setfill(' ') << thisPlayer.getPlayerName() << setw(col2) << thisPlayer.getPlayerNumber() << setw(col3) << thisPlayer.getPlayerPoints() << endl;
        }
        outfile << endl;
    }
    for (int i = 1; i <= 4; i++)
    {
        int highestPoints = 0;
        PlayerClass thisPlayer;
        for (int j = 0; j < PlayerCount[i - 1]; j++)
        {
            if (thisTeam[i - 1].getPlayer(j).getPlayerPoints() > highestPoints)
            {
                highestPoints = thisTeam[i - 1].getPlayer(j).getPlayerPoints();
                thisPlayer = thisTeam[i - 1].getPlayer(j);
            }
        }
        outfile << "The player with the most points on Team #" << i << " is " << thisPlayer.getPlayerName() << endl;
    }
    outfile << endl;
    outfile << "The top two teams with the most points are:" << endl;
    int highestPoints = 0;
    int secondHighestPoints = 0;
    TeamClass thisTeam1;
    TeamClass thisTeam2;
    for (int i = 0; i < 4; i++)
    {
        if (thisTeam[i].getTeamPoints() > highestPoints)
        {
            highestPoints = thisTeam[i].getTeamPoints();
            thisTeam1 = thisTeam[i];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (thisTeam[i].getTeamPoints() > secondHighestPoints && thisTeam[i].getTeamPoints() < highestPoints)
        {
            secondHighestPoints = thisTeam[i].getTeamPoints();
            thisTeam2 = thisTeam[i];
        }
    }
    outfile << thisTeam1.getTeamName() << " with " << thisTeam1.getTeamPoints() << " points" << endl;
    outfile << thisTeam2.getTeamName() << " with " << thisTeam2.getTeamPoints() << " points" << endl;
}