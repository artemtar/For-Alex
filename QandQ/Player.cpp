#include "Player.h"

Player::Player(const string &_name) : name{_name}
{
}
//initilizing qiwinto player

ScoreSheet::Color QwintoPlayer::choseColor()
{
    cout << "Hey man, chose da cala:" << endl;
    cout << "1. Red" << endl;
    cout << "2. Yellow" << endl;
    cout << "3. Blue" << endl;
    ScoreSheet::Color c; 
    int choiceOfC = -1;
    while (choiceOfC < 1 && choiceOfC > 3)
    {
        bool flag = false;
        if (flag)
        {
            cout << "Incorrect input!" << endl; //just output for player to say that he is stupid
        }
        try
        {
            cout << "intput: ";
            cin >> choiceOfC;
        }
        catch (...)
        {
            cerr << "Incorrect input" << endl;
        }
        flag = true;
    }
    if (choiceOfC == 1) c = ScoreSheet::Color::RED;
    if (choiceOfC == 2) c = ScoreSheet::Color::YELLOW;
    if (choiceOfC == 3) c = ScoreSheet::Color::BLUE;
}

QwintoPlayer::QwintoPlayer(QwintoScoreSheet &qs, string _name) : Player(_name), sheet{qs} {}
//some stuff to do before input
void QwintoPlayer::inputBeforeRoll(RollOfDice &rd)
{
    int choice = -1;
    if (getStatus())
    {

        rd.roll();
        ScoreSheet::Color c = choseColor();
        cout << "input or fail" << endl;
        while (choice == -1)
        {
            cout << "1. Input" << endl;
            cout << "2. Or using fail field" << endl;
            cout << "intput: ";
            try
            {
                cin >> choice;
            }
            catch (...)
            {
                cerr << "Incorrect input" << endl;
            }
        }
    }
    else
    {
    }
    switch (choice)
    {
        //case where player chose positon on the board
    case 1:
    {
        cout << "Chose color and position" << endl;
        ScoreSheet::Color c = choseColor();
        cout << "Position: " << endl;
        int pos = -1;
        while (pos == -1)
        // rest checking is done inside row class
        {
            try
            {
                cin >> pos;
            }
            catch (...)
            {
                cerr << "Incorrect input" << endl;
            }
        }
        sheet.score(rd, c, pos);
    }
    break;

        //payer is using fail field
    case 2:
    {
        sheet.addFail();       
    }
     break;
    }

    //or he can chose to use fail field
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

int main()
{
    QwintoRow<ScoreSheet::Color::RED> qr;
    QwintoRow<ScoreSheet::Color::YELLOW> qy;
    QwintoRow<ScoreSheet::Color::BLUE> qb;
    RollOfDice r;
    cout << r << "roled" << endl;
    qr[2] = r;
    QwintoScoreSheet qs("Artem", qr, qy, qb);
    ScoreSheet &parent = qs;
    cout << parent;
    r.roll();
    parent.score(r, ScoreSheet::Color::RED, 5);
    cout << parent;
   // QwintoPlayer Artem("Artem", qr, qy, qb);
}
