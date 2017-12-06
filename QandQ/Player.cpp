#include "Player.h"



Player::Player(ScoreSheet* s, const string &_name) : sheet{s}, name{_name} {}
//Player::Player(const Player& from):name{from.name},status{from.status},sheet{from.sheet}{}
Player::~Player(){}
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
ostream &operator<<(ostream &os, const Player &p)
{
    return os << *(p.sheet);
}
//initilizing qiwinto player
ScoreSheet::Color QwintoPlayer::choseColor()
{
    cout << "Please, chose the color:" << endl;
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
bool Player::operator <(const Player& p) {
         if(sheet->getScore() < p.sheet->getScore())
            return true;     
         }

//**Qwinto**

QwintoPlayer::QwintoPlayer(QwintoScoreSheet &qs, string _name) : Player(&qs, _name){}
//QwintoPlayer::QwintoPlayer(const QwintoPlayer &from):Player(&from.sheet,from.name){}
//some stuff to do before input
void QwintoPlayer::inputAfterRoll(RollOfDice &rd)
{
 int choice = -1;   
       // rd.roll();//need a colour vector now
        ScoreSheet::Color c = choseColor();
        cout << "Chose if you want to input score in a row or use fail field" << endl;
        cout << "1. Input" << endl;
        cout << "2. Fail" << endl; 
        choice = inputChecker(1, 2);    
    switch (choice)
    {
        //case where player chose position on the board
    case 1:
    {
        cout << "Choose color and position" << endl;
        ScoreSheet::Color c = choseColor();
        cout << "Position: " << endl;
        int pos = inputChecker(1, 10);
        //here should be try and catch if was not able to add into row
        //sheet->score(rd, c, pos);
    }
    break;

        //payer is using fail field
    case 2:
    {
        sheet->addFail();
    }
    break;
    }

    //or he can chose to use fail field
}
 std::vector<ScoreSheet::Color> QwintoPlayer::inputBeforeRoll(RollOfDice &rd, int numOfDices)
{
    std::vector<ScoreSheet::Color> colours;
    //get the colours from the user
    for (int i=0; i < numOfDices; i++){
        ScoreSheet::Color tempColour;
        std::cout<<"What is the colour of the dice number "<< i + 1 << endl;
        tempColour = choseColor();
        colours.push_back(tempColour);  
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
