#include "Player.h"



Player::Player(ScoreSheet* s, const string &_name) : sheet{s}, name{_name} {}
//Player::Player(const Player& from):name{from.name},status{from.status},sheet{from.sheet}{}
Player::~Player(){
    delete sheet;
}
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
ScoreSheet::Color Player::choseColor()
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
// bool Player::findWinner(Player* p1, Player* p2){
//     return *p1 < *p2;
// }

//**Qwinto**
QwintoPlayer::~QwintoPlayer(){cout << "Qwinto player destructor!!!" << endl;}

QwintoPlayer::QwintoPlayer(QwintoScoreSheet* qs, string _name) : Player(qs, _name){}
//QwintoPlayer::QwintoPlayer(const QwintoPlayer &from):Player(&from.sheet,from.name){}
//some stuff to do before input
void QwintoPlayer::inputAfterRoll(RollOfDice* rd)
{
                    while(true){
                        int chosenColourNum;
                        cout << name << ", what is the colour of the row you want to put the roll in? ";
                        ScoreSheet::Color chosenColour = choseColor();
                        
                        int chosenPosition;
                        cout<<name << ", what is the position in the row you want to put the roll in? ";
                        cin>>chosenPosition;

                        if (sheet->score(rd,chosenColour,chosenPosition)){
                            cout<< name <<", you put roll in your scoresheet"<<endl;
                            cout<< *sheet <<endl;
                            break;
                        }
                        else{
                            cout << "Incorrect input, plaese repeat. " << endl;
                            cout << "If you changed your mind and want to skip the turn input 42. ";
                            string fortytwo;
                            cin >> fortytwo;
                            if(fortytwo == "42") break;
                        }
                    }
}
 std::vector<ScoreSheet::Color> QwintoPlayer::inputBeforeRoll(RollOfDice &rd, int numOfDices)
{
    std::vector<ScoreSheet::Color> colours{};
    //get the colours from the user
    for (int i=0; i < numOfDices; i++){
        ScoreSheet::Color receivedColour;
        std::cout<<"What is the colour of the dice number "<< i + 1 << endl;
        receivedColour = choseColor();
        for(auto colour:colours){
            if (colour==receivedColour){
                std::cout<<"You already chosen this colour. Please choose another one";
                receivedColour=choseColor();
            }
        }
        colours.push_back(receivedColour);  
    }
    return colours;
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
