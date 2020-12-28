#include "QuizFiles.h"

int QuizFiles::Menu()
{
    int userInput = 0;
    cout << "1. Play" <<endl;
    cout << "2. Display All The Questions, Answers, And " <<
    "Options(Requires Password To Acess)." << endl;
    cout << "3. Add Question." <<endl;
    cout << "4. Delete Question." << endl;
    cout << "5. Edit Question." << endl;
    cin >> userInput;

    return userInput;
}

void QuizFiles::AddQuestion(ofstream &quizFile)//fstream quizFile)
{
    Records data;

    if(quizFile)
    {
        cin.ignore();
        cout << "Enter the Question: " << endl;
        getline(cin, data.question);

        cout << "Enter the Answer: " << endl;
        getline(cin, data.answer);

        cout << "Enter the options number 1: " << endl;
        getline(cin, data.option1);
        cout << "Enter the options number 2: " << endl;
        getline(cin, data.option2);
        cout << "Enter the options number 3: " << endl;
        getline(cin, data.option3);
        cout << "Enter the options number 4: " << endl;
        getline(cin, data.option4);

        quizFile << data.question << ' ' << data.answer << ' '
        << data.option1 << ' ' << data.option2 << ' ' << data.option3
        << ' ' << data.option4 << endl;



    }
    else
    {
        cout << "File did not open!" << endl;
    }
}

int QuizFiles::PlayGame(ifstream &quizFile)
{
    Records data;
    int count = 0, userInput;


    if(quizFile)
    {

        while(!quizFile.eof())//quizFile >> data.question >> data.answer >> data.option1
               //         >> data.option2 >> data.option3 >> data.option4)
        {

            getline(quizFile, data.question, '?');
            getline(quizFile, data.answer, '.');
            getline(quizFile, data.option1, '.');
            getline(quizFile, data.option2, '.');
            getline(quizFile, data.option3, '.');
            getline(quizFile, data.option4, '.');

            count++;


            cout << "\nQustion number: " << count
            << data.question << "?" << endl;


            cout << "1." << data.option1 << "\t\t" << "2." << data.option2 << endl;
            cout << "3." << data.option3 << "\t\t" << "4." << data.option4 << endl;
            cin >> userInput;

             AnswerChecker(data, userInput);
        }

    }
    else
    {
        cout << "File did not open!" << endl;
    }

    return score;
}

void QuizFiles::AnswerChecker(Records data, int userInput)//ifstream &quizFile, int userInput, int counter)
{
    if(userInput == 1)
    {
        if(data.answer == data.option1)
        {
            score += 10;
            cout << "Correct Answer!" << endl;
            cout << "Your current score is " << score << endl;
        }
        else
        {
            score -= 5;
            cout << "Wrong Answer!!" << endl;
            cout << "Your current score is " << score << endl;
        }
    }
    else if(userInput == 2)
    {
        if(data.answer == data.option2)
        {
            score += 10;
            cout << "Correct Answer!" << endl;
            cout << "Your current score is " << score << endl;
        }
        else
        {
            score -= 5;
            cout << "Wrong Answer!!" << endl;
            cout << "Your current score is " << score << endl;
        }
    }
    else if(userInput == 3)
    {
        if(data.answer == data.option3)
        {
            score += 10;
            cout << "Correct Answer!" << endl;
            cout << "Your current score is " << score << endl;
        }
        else
        {
            score -= 5;
            cout << "Wrong Answer!!" << endl;
            cout << "Your current score is " << score << endl;
        }
    }
    else if(userInput == 4)
    {
        if(data.answer == data.option4)
        {
            score += 10;
            cout << "Correct Answer!" << endl;
            cout << "Your current score is " << score << endl;
        }
        else
        {
            score -= 5;
            cout << "Wrong Answer!!" << endl;
            cout << "Your current score is " << score << endl;
        }
    }
}

void QuizFiles::MultiPlayers(int numOfPlayer)
{
    for(int i = 0; i < numOfPlayer; i++)
    {
        cout << "Enter the player number " << i << "name: ";
        cin >> playerName[i];
    }
}

void QuizFiles::DisplayAll(ifstream &quizFile)
{
    Records data;
    int count = 0;


    if(quizFile)
    {

        while(!quizFile.eof())//quizFile >> data.question >> data.answer >> data.option1
               //         >> data.option2 >> data.option3 >> data.option4)
        {
            getline(quizFile, data.question, '?');
            getline(quizFile, data.answer, '.');
            getline(quizFile, data.option1, '.');
            getline(quizFile, data.option2, '.');
            getline(quizFile, data.option3, '.');
            getline(quizFile, data.option4, '.');


            count++;
            cout << "\nQustion number: " << count;
            cout << data.question << "?" << endl;


            cout << "1." << data.option1 << "\t\t" << "2." << data.option2 << endl;
            cout << "3." << data.option3 << "\t\t" << "4." << data.option4 << endl;
            cout << "Correct Answer: " << data.answer << endl;

        }

    }
    else
    {
        cout << "File did not open!" << endl;
    }

}


int QuizFiles::GetScore()
{
    return score;
}


