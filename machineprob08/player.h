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
    int numPlayers[11];

public:
    void setPlayerFName(std::string f);
    void setPlayerLName(std::string l);
    void setPlayerName();
    void setPlayerNumber(int n);
    void setPlayerPoints(int p);
    std::string getPlayerFName();
    std::string getPlayerLName();
    std::string getPlayerNumber();
    std::string getPlayerPoints();
};