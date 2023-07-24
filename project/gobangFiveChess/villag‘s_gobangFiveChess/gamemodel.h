#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include<vector>



enum GameType
{
  person,
    bot
};



enum GameStatus
{
    playing,
    win,
    dead
};


const int kBoardSize=15;


class gamemodel
{
public:
    gamemodel();



    std::vector<std::vector<int>>gameMap;
    std::vector<std::vector<int>>scoreMap;
    bool playerFlag;
    GameType gameType;
    GameStatus gameStatus;


    void startGame(GameType type);
    void calculateScore();
    void actionByPerson(int row,int col);
    void actionByAi(int &row,int &col);
    void updateMap(int row,int col);
    bool isDeadGame();
    bool isWin(int row,int col);


};

#endif // GAMEMODEL_H
