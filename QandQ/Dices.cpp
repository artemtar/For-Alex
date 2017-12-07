#include "Dices.h"

//**RandomDice**

// generate random value for the Dice
int RandomDice::getRandomFace()
{
    std::uniform_int_distribution<> dis(1, 6);
    static std::random_device rd;
    std::mt19937 gen(rd());
    dis(gen);
}

//**Dice**
//constructor
Dice::Dice(ScoreSheet::Color col) : c(col),isEnabled(false) { roll(); }//allsdices disabled by default
//Dice::Dice(const Dice &from): c(from.c),isEnabled(from.isEnabled),face(from.face){}
// create a dice with random face from 
void Dice::roll(){face = RandomDice::getRandomFace();}

//**RollOfDice**
//constructors
RollOfDice::RollOfDice()
{
    dices.reserve(6);//different size for qwix and qwinto
    Dice red(ScoreSheet::Color::RED);
    Dice yellow(ScoreSheet::Color::YELLOW);
    Dice blue(ScoreSheet::Color::BLUE);
    dices.push_back(red);
    dices.push_back(yellow);
    dices.push_back(blue);
}
RollOfDice::RollOfDice(const RollOfDice &from){

    for (int i=0;i<from.dices.size();i++){
        cout<<from.dices[i].isEnabled;
        dices.push_back(from.dices[i]);
    }
}//copy construct

//to convert to integer !!!!probably change to constructor that takes one integer
RollOfDice::operator int()
{
    int sum = 0;
    for (auto& d : dices)
        if (d.isEnabled){
           // cout<<d.face;//testing random roll
            sum += d.face;
            d.isEnabled=false;
            }
    return sum;
}


RollOfDice* RollOfDice::roll(std::vector<ScoreSheet::Color> selectedColours)
{
    vector<Dice> out;
    for (Dice& d : *this){
        for (ScoreSheet::Color &colour: selectedColours){
            if (colour==d.c){
                d.roll();
                d.isEnabled=true;
            }
            //else if {d.isEnabled=false;}
       }
    }
    
    return this;
}
//qwixx staff
RollOfDice RollOfDice::pair(int d1, int d2) {}

//** methods to print out **
ostream &operator<<(ostream &_os, const Dice &d)
{
    _os << colToStr(d.c) << " dice rolled :" << d.face << endl;
    return _os;
}
ostream &operator<<(ostream &_os, const RollOfDice &set)
{
    for (const Dice &d : set.dices)
    {
        _os << d;
    }
    return _os;
}
string colToStr(ScoreSheet::Color c)
{
    return (const char *[]){
        "Red",
        "Yellow",
        "Blue",
        "Green",
        "White",
    }[c];
}




//**testingOfDices**
// int main()
// {
//     //run test
//     cout << "ROLL:" << endl;
//     RollOfDice r;
//     int i = r;
//     cout << r;
//     cout << "total is:";
//     cout << i << endl;
//     cout << "REROLL:" << endl;
//     r.roll();
//     i = r;
//     cout << r;
//     cout << "total is:";
//     cout << i << endl;
// }