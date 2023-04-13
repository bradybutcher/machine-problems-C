#include <string>

class PlayerClass
{
public:
    std::string playerFName;
    std::string playerLName;
    std::string playerName;
    int playerNumber;
    int playerPoints;
    void setPlayerFName(std::string f);
    void setPlayerLName(std::string l);
    void setPlayerName();
    void setPlayerNumber(int n);
    void setPlayerPoints(int p);
};