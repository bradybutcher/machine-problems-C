#include "player.h"


using namespace std;

void PlayerClass::setPlayerFName(string f)
{
    playerFName = f;
}

void PlayerClass::setPlayerLName(string l)
{
    playerLName = l;
}

void PlayerClass::setPlayerNumber(int n)
{
    playerNumber = n;
}

void PlayerClass::setPlayerPoints(int p)
{
    playerPoints = p;
}

void PlayerClass::setPlayerName()
{
    playerName = playerFName + " " + playerLName;
}