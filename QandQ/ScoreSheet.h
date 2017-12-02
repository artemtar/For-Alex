#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Dices.h"
using namespace std;
#ifndef SCORESHEET
#define SCORESHEET

struct Dice;
struct RollOfDice;

//ostream &operator<<(ostream &, const QwintoRow<Color>&);
//ostream &operator<<(ostream &, const QwixxRow<Color>&);

//**Scoresheet**
//Parent class for all scoresheet classes 
//pure virtual
class ScoreSheet
{
<<<<<<< HEAD
=======
    
>>>>>>> f38edc1f8db56b361b1d9c698ffb1c33cfaf8545
  private:
  //data
    int overallScore;
    string name_player;
    bool ended;
    //!!Give the class ScoreSheet a print function that accepts an std::ostream and
  protected:
  //data

    int num_failed[4];
  //methods
    virtual bool validate(int) = 0;

  public:
  //data
    enum Color
    {
        RED,
        YELLOW,
        BLUE,
        GREEN,
        WHITE
    };

  //constructor
    ScoreSheet(string s = "");
  //functions
    void setTotal();
    virtual bool operator!();
    //virtual functions
    virtual bool score(RollOfDice&, ScoreSheet::Color, int pos = -1) = 0;
    virtual int calcTotal() = 0;

    virtual ostream& print(ostream &)const = 0;
    //frinds
     friend ostream &operator<<(ostream &, const ScoreSheet &);

     //to be done
     //call cout of children
    
    //!!!the rest is unknown land don't go there
    //void setTotal();
    
};
#endif //SCORESHEET
//hi there

#ifndef QWINTOROW
#define QWINTOROW
template <const ScoreSheet::Color C>
class QwintoRow 
{
  private:
  //data
    int row[10];
  //functions
    bool validate(int);
  public:
  //data
    bool isFull();
    int amountNums();
  //constructor
    QwintoRow();
  //functions
    int &operator[](int);
    //frinds
    friend ostream &operator<<(ostream &out, const QwintoRow<C> &qr)
    {
        for (auto i : qr.row)
        {
            out << i;
        }
        return out;
    }
};
//separate file to hold declaration of template
#include "Qwinto.hxx"
#endif //QWINTOROW

#ifndef QWIXROW
#define QWIXROW
template <class T, const ScoreSheet::Color C>
class QwixRow
{
  private:
  //data
    int row[11];
  //functions
    bool validate(int) override;
  public:
  //data
  //functions
    int &operator[](int);
    int &operator+=(RollOfDice &);
    bool checkAdd(int);
    //friends
    friend ostream &operator<<(ostream &out, const QwixRow<T, C> &qr)
    {
        for (auto i : qr.row)
        {
            out << i;
        }
        return out;
    }
};
#include "Qwix.hxx"
#endif //QWIXROW

#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET
class QwintoScoreSheet : public ScoreSheet
{
  private:
  //data
    QwintoRow<RED> red;
    QwintoRow<YELLOW> yellow;
    QwintoRow<BLUE> blue;
  public:
  //data
  //constructors
    QwintoScoreSheet(string, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>);
  //functions
    bool score(RollOfDice&, ScoreSheet::Color, int pos = -1) override;

    bool validate(int);
    int calcTotal() override;
    bool operator!() override;//!!what does it do!!
    ostream& print(ostream &) const override;
    //friends
    friend ostream &operator<<(ostream &, const QwintoScoreSheet &);
};
#endif //QWINTOSCORESHEET

//have torevise this class before implementing
#ifndef QWIXSCORESHEET
#define QWIXSCORESHEET
class QwixScoreSheet : public ScoreSheet//!!change to struct probably?!!
{
    //!!! why Commented!!!
    //vector red_yellow;
    // list blue_green;
    //!!!

  public:
  //data
  //constructor
    QwixScoreSheet(string, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>, QwintoRow<GREEN>);
<<<<<<< HEAD
  //functions
    bool score(RollOfDice&, ScoreSheet::Color, int pos = -1) override;
=======
    bool score(RollOfDice, ScoreSheet::Color, int pos = -1) override;
>>>>>>> f38edc1f8db56b361b1d9c698ffb1c33cfaf8545
    bool validate(int);
    int calcTotal() override;
    bool operator!() override;
    ostream& print(ostream &) const override;
    //frinds
    friend ostream &operator<<(ostream &, const QwixScoreSheet &);
};
#endif //QWIXSCORESHEET