#pragma once
#include <string>
#include "player.h"

using namespace std;

class TeamClass
{
private:
    std::string teamName;
    int teamPoints;
    PlayerClass Player[11];

public:
    void setTeamName(std::string n);
    void setTeamPoints(int points);
    string getTeamName();
    int getTeamPoints();
    PlayerClass setPlayer(PlayerClass p, int i);
    PlayerClass getPlayer(int i);

};