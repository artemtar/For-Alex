#include <random>

#ifndef DICE
#define DICE

#include "ScoreSheet.h"
//**RandomDice**

struct RandomDice
{
    //methods
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

    //methods
    void roll(); 
};

//Alex doesit
struct RollOfDice
{
    //data
    vector<Dice> dices;
    //constructors
    RollOfDice(); //!!Warning!! might use two diffrent construct if needed to work with both games
    //methods

    void roll(std::vector<ScoreSheet::Color>);
    
    //to implement for each loop in the RollOf Dices
    inline auto begin(){return dices.front();};
    inline auto end(){return dices.back();};

    RollOfDice pair(int, int);

    operator int();
    
};
// printing methods
string colToStr(ScoreSheet::Color);
ostream &operator<<(ostream &, const RollOfDice &);
ostream &operator<<(ostream &, const Dice &);

#endif //DICE