#include "Player.h"

Player::Player(const string &_name) : name{_name}
{
}

inline void Player::setStatusActive()
{
    status = true;
}
inline void Player::setStatusInactuve()
{
    status = false;
}
inline bool Player::getStatus()
{
    return status;
}


//initilizing qiwinto player

ScoreSheet::Color QwintoPlayer::choseColor(){
    cout << "Hey man, chose da cala:" << endl;
    cout << "1. Red" << endl;
    cout << "2. Yellow" << endl;
    cout << "3. Blue" << endl;
    ScoreSheet::Color c = WHITE;
    while(c == WHITE){
    cout << "intput: "
    cin >> c
    if(c == WHITE) cout << "Incorrect input";
    }
}

QwintoPlayer::QwintoPlayer(QwintoScoreSheet &qs, string _name) : Player(_name), sheet{qs} {}

void QwintoPlayer::inputBeforeRoll(RollOfDice &)
{
    if (getStatus())
    {

        rd.roll();
        ScoreSheet::Color c = choseColor();
        cout << "input or fail" << endl;
        int choice = -1;
        
        sheet.score(rd, c, pos);
        //or he can chose to use fail field

    }
    else
    {
    }
}
void QwintoPlayer::inputAfterRoll(RollOfDice &)
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
QwixPlayer::QwixPlayer(QwixScoreSheet &qs, string _name) : Player(_name), sheet{qs} {}
void QwixPlayer::inputBeforeRoll(RollOfDice &)
{
    if (getStatus())
    {
    }
    else
    {
    }
}
void QwixPlayer::inputAfterRoll(RollOfDice &)
{
    if (getStatus())
    {
    }
    else
    {
    }
}
//qwixpalyer ends
int main()
{
    //test
}