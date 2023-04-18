#pragma once
#include <string>

class PlayerClass
{
private:
    std::string playerFName;
    std::string playerLName;
    std::string playerName;
    int playerNumber;
    int playerPoints;

public:
    void setPlayerFName(std::string f);
    void setPlayerLName(std::string l);
    void setPlayerName();
    void setPlayerNumber(int n);
    void setPlayerPoints(int p);
    std::string getPlayerName();
    int getPlayerNumber();
    int getPlayerPoints();
};