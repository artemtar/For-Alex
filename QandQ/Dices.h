#include <random>

#ifndef DICE
#define DICE

#include "ScoreSheet.h"
//**RandomDice**

struct RandomDice
{

    //functions

    static int getRandomFace();
};
//**Dice**
struct Dice
{
    //data
    const ScoreSheet::Color c;
    int face;
 
    //constructors
    Dice(ScoreSheet::Color); 


    //functions
    void roll();

 


//**RollOfDice**
struct RollOfDice
{
    //data
    vector<Dice> dices;
    //constructors
    RollOfDice(); //!!Warning!! might use two diffrent construct if needed to work with both games

    //functions

    void roll();
    RollOfDice pair(int, int);
    
};
// printing methods
string colToStr(ScoreSheet::Color);
ostream &operator<<(ostream &, const RollOfDice &);
ostream &operator<<(ostream &, const Dice &);

#endif //DICE