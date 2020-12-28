#ifndef SCOREKEEPER_H
#define SCOREKEEPER_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class ScoreKeeper
{
    public:
        ScoreKeeper(int score[], int numOfPlayer, string name[]);
        void DisplayPlayerInfo();

    protected:

    private:
        int score[4];
        string name[4];
        int playerNum = 0;
        int highestScore;
        string playerName;
        void StoreScore();

};

#endif // SCOREKEEPER_H
