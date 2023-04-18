#include "teams.h"

using namespace std;

void TeamClass::setTeamName(string name)
{
    teamName = name;
}

void TeamClass::setTeamPoints(int points)
{
    teamPoints = points;
}

string TeamClass::getTeamName()
{
    return teamName;
}

int TeamClass::getTeamPoints()
{
    return teamPoints;
}

PlayerClass TeamClass::setPlayer(PlayerClass p, int i)
{
    Player[i] = p;
    return Player[i];
}

PlayerClass TeamClass::getPlayer(int i)
{
    return Player[i];
}
