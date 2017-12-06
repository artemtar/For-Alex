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
    bool isEnabled;
 
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

    RollOfDice& roll(std::vector<ScoreSheet::Color>);
    
    //to implement for each loop in the RollOf Dices
    std::vector<Dice>::iterator begin();
    std::vector<Dice>::iterator end();

    RollOfDice pair(int, int);

    operator int();
    
};

inline std::vector<Dice>::iterator RollOfDice::begin(){return dices.begin();};
inline std::vector<Dice>::iterator RollOfDice::end(){return dices.end();}

// printing methods
string colToStr(ScoreSheet::Color);
ostream &operator<<(ostream &, const RollOfDice &);
ostream &operator<<(ostream &, const Dice &);

#endif //DICE