#include "ScoreKeeper.h"

ScoreKeeper::ScoreKeeper(int score[], int numOfPlayer, string name[])
{
    playerNum = numOfPlayer;
    for(int i = 0; i < numOfPlayer; i++)
    {
        this->score[i] = score[i];
        this->name[i] = name[i];
    }
    //void DisplayPlayerInfo();
}

void ScoreKeeper::StoreScore()
{
    ofstream scoreFile("ScoreFile.txt");

    for(int i = 0; i < playerNum; i++)
    {
        if(highestScore < score[i])
        {
            highestScore = score[i];
            playerName = name[i];
        }
    }

    scoreFile << playerName << ' ' << highestScore << endl;

}

void ScoreKeeper::DisplayPlayerInfo()
{
    int temp = 0;
    string tempName;
    //ifstream scoreFile("ScoreFile.txt");
    for(int i = 0; i < (playerNum); i++)
    {
        for(int j = 0; j < playerNum; j++)
        {
            if(score[i] > score[j])
            {
                temp = score[j];
                score[j] = score[i];
                score[i] = temp;

                tempName = name[j];
                name[j] = score[i];
                name[i] = tempName;
            }
        }
    }

    cout << "Name\t" << "Score" << endl;

    for(int i = 0; i < playerNum; i++)
    {
        cout << name[i] << "\t" << score[i] << endl;
    }
}
