#include "Player.h"

Player::Player(const string &_name) : name{_name}
{
}
//checks input according to boundaries and if it is integer
int Player::inputChecker(int boundA, int boundB){

    int choice = -1;        
        while (42)
    {
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
        }
        if (!(choice < boundA) && !(choice > boundB)) break;
        else cout << "Invalid input. Try again: ";
    }
    return choice;
}
//initilizing qiwinto player
ScoreSheet::Color QwintoPlayer::choseColor()
{
    cout << "Hey man, chose da cala:" << endl;
    cout << "1. Red" << endl;
    cout << "2. Yellow" << endl;
    cout << "3. Blue" << endl;
    cout << "Input: ";
    ScoreSheet::Color c;
    int choiceOfC = inputChecker(1, 3);
    if (choiceOfC == 1)
        c = ScoreSheet::Color::RED;
    if (choiceOfC == 2)
        c = ScoreSheet::Color::YELLOW;
    if (choiceOfC == 3)
        c = ScoreSheet::Color::BLUE;
    return c;
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
        cout << "Chose if you want to input score in a row or use fail field" << endl;
        cout << "1. Input" << endl;
        cout << "2. Fail" << endl; 
        choice = inputChecker(1, 2);
    }
    else
    //nonactive player
    {
    }
    switch (choice)
    {
        //case where player chose position on the board
    case 1:
    {
        cout << "Chose color and position" << endl;
        ScoreSheet::Color c = choseColor();
        cout << "Position: " << endl;
        int pos = inputChecker(1, 10);
        //here should be try and catch if was not able to add into row
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

// int main()
// {
//     QwintoRow<ScoreSheet::Color::RED> qr;
//     QwintoRow<ScoreSheet::Color::YELLOW> qy;
//     QwintoRow<ScoreSheet::Color::BLUE> qb;
//     RollOfDice r;
//     cout << r << "roled" << endl;
//     qr[2] = r;
//     QwintoScoreSheet qs("Artem", qr, qy, qb);
//     ScoreSheet &parent = qs;
//     cout << parent;
//     r.roll();
//     parent.score(r, ScoreSheet::Color::RED, 5);
//     cout << parent;
//     QwintoPlayer Artem(qs,"Artem");
// }
