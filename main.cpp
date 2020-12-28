#include <iostream>
#include "Quiz.h"
#include "QuizFiles.h"
#include "ScoreKeeper.h"
#include <iostream>
using namespace std;

int main()
{
   /* string player1, player2;

    cout << "Welcome to The Quiz Game!!\n" << endl;
    cout << "Enter the player one name: ";
    cin >> player1;

    cout << "Enter the player two name: ";
    cin >> player2;


    Quiz playerOne;
    playerOne.StartQuiz();

    Quiz playerTwo;
    playerTwo.StartQuiz();

    cout << player1 << "'s score is " << playerOne.GetScore() << endl;
    cout << player2 << "'s score is " << playerTwo.GetScore() << endl;
*/
    QuizFiles obj;

    int userChoice = 0, numOfPlayer;
    char uI = 'Y';
    const string password = "Admin";
    string name[4];
    int score[4];
    score[0] = 150;
    score[1] = 50;
    score[2] = 145;
    score[3] = 20;

    cout << "Welcome to The Quiz Game!!" << endl;
    userChoice = obj.Menu();

    while(uI == 'Y' || uI == 'y')
    {
        if(userChoice == 1)
        {
            cout << "How many players(max 4 player): ";
            cin >> numOfPlayer;

            if(numOfPlayer > 1)
            {
                for(int i = 0; i < numOfPlayer; i++)
                {
                    ifstream quizFile("QuestionsFile.txt");

                    cout << "Enter the player " << i+1 << " name: ";
                    cin >> name[i];

                    score[i] = obj.PlayGame(quizFile);
                    quizFile.close();

                }
                ScoreKeeper obj2(score, numOfPlayer, name);
                obj2.DisplayPlayerInfo();
            }
            else
            {
                ifstream quizFile("QuestionsFile.txt");


                score[0] = obj.PlayGame(quizFile);
                quizFile.close();

                cout << "Your total Score is " << score[0] << endl;
            }
        }
        else if(userChoice == 2)
        {
            string temp;

            cout << "Enter the password to access this choice." << endl;
            cin >> temp;

            if(password.compare(temp) == 0)
            {
                ifstream quizFile("QuestionsFile.txt");
                obj.DisplayAll(quizFile);
                quizFile.close();

            }
            else
            {
                cout << "Invalid Password!" << endl;
                cout << "Access Denied!! You don't have permission"
                     <<" to access this option." << endl;
            }
        }
        else if(userChoice == 3)
        {
            string temp;

            cout << "Enter the password to access this choice." << endl;
            cin >> temp;

            if(password.compare(temp) == 0)
            {
                ofstream quizFile("QuestionsFile.txt");
                obj.AddQuestion(quizFile);
                quizFile.close();
            }
            else
            {
                cout << "Invalid Password!" << endl;
                cout << "Access Denied!! You don't have permission"
                     <<" to access this option." << endl;
            }

        }
        else if(userChoice == 4)
        {
            cout << "How many players(max 4 player): ";
            cin >> numOfPlayer;
            //ScoreKeeper obj2(score, numOfPlayer);
            //obj2.DisplayPlayerInfo();
        }

        cout << "Do you wanna continue: ";
        cin >> uI;
    }





    return 0;
}
