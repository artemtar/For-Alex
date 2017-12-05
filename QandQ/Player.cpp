#include "Player.h"

Player::Player(const string &_name) : name{_name}{}

//moved to the header
//inline void Player::setStatusActive(){}
//inline void Player::setStatusInactuve(){}
//inline bool Player::getStatus(){}

//initilizing qiwinto player

ScoreSheet::Color QwintoPlayer::choseColor()
{
    cout << "Hey man, chose da cala:" << endl;
    cout << "1. Red" << endl;
    cout << "2. Yellow" << endl;
    cout << "3. Blue" << endl;
    ScoreSheet::Color c = ScoreSheet::Color::WHITE;//default color for now
    while (c == ScoreSheet::Color::WHITE)
    {
        cout << "intput: ";
     //   cin >> c; //compiler complain will check latter
        if (c == ScoreSheet::Color::WHITE)
            cout << "Incorrect input";
    }
}

QwintoPlayer::QwintoPlayer(QwintoScoreSheet &qs, string _name) : Player(_name), sheet{qs} {}
QwintoPlayer::QwintoPlayer(const QwintoPlayer &from):Player(from.name),sheet(from.sheet){}//: Player(""){}
//some stuff to do before input
void QwintoPlayer::inputBeforeRoll(RollOfDice &rd)
{
    if (getStatus())
    {

        rd.roll();
        ScoreSheet::Color c = choseColor();
        cout << "input or fail" << endl;
        int choice = -1;
        while (choice == -1)
        {
            cout << "1. Input" << endl;
            cout << "2. Fail" << endl;
            cin >> choice;
            if (choice == -1)
                cout << "Ivalid input" << endl;
        }
        // switch (choice)
        // {
        //     //case where player chose positon on the board
        // case 1:
        //     cout << "Chose color and position" << endl;
        //     ScoreSheet::Color c = choseColor();
        //     cout << "Position: " << endl;
        //     int pos = -1;
        //     cin >> pos;
        //     sheet.score(rd, c, pos);
        //     break;
        //     //payer choise to fail field
        // case 2:
        // cout<<"hello";
        // break;
        // }

        //or he can chose to use fail field

    }
    else
    {
    }
}
void QwintoPlayer::inputAfterRoll(RollOfDice &rd)
{
    if (getStatus())
    {
    }
    else
    {
    }
}

//qwinto player ends

//qwixplayer intitialization
//QwixPlayer::QwixPlayer(QwixScoreSheet &qs, string _name) : Player(_name), sheet{qs} {}
// void QwixPlayer::inputBeforeRoll(RollOfDice &rd)
// {
//     if (getStatus())
//     {
//     }
//     else
//     {
//     }
// }
// void QwixPlayer::inputAfterRoll(RollOfDice &rd)
// {
//     if (getStatus())
//     {
//     }
//     else
//     {
//     }
// }
//qwixpalyer ends
/*
int main()
{
    //test
}
*/