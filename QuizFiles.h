#ifndef QUIZFILES_H
#define QUIZFILES_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class QuizFiles
{
    public:
        int Menu();
        void AddQuestion(ofstream &quizFile);//fstream quizFile);
        int PlayGame(ifstream &quizFile);
        //ifstream &quizFile, int userInput, int count);
        int GetScore();
        void DisplayAll(ifstream &quizFile);
        void MultiPlayers(int numOfPlayer);

    protected:

    private:
        struct Records
        {
            string question;
            string answer;
            string option1;
            string option2;
            string option3;
            string option4;
        };
        int score = 50;
        string playerName[4];
        void AnswerChecker(Records data, int userInput);
};

#endif // QUIZFILES_H
