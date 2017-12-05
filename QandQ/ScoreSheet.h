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
class ScoreSheet
{
    
  private:
  //data
    int overallScore;
    string name_player;
    bool ended;
    //Give the class ScoreSheet a print function that accepts an std::ostream and
  protected:
  //data
  int num_failed[4];
  //functions
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
  //constructors
    ScoreSheet(string s = "");
  //functions
    void addFail();
    void setTotal();
    virtual bool operator!();
    friend ostream &operator<<(ostream &, const ScoreSheet &);
    //virtual
    virtual bool score(RollOfDice, ScoreSheet::Color, int pos = -1) = 0;
     //void setTotal();
    virtual ostream& print(ostream &)const = 0;
    virtual int calcTotal() = 0;    
   
};
#endif //SCORESHEET

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
  //constructors
    QwintoRow();
  //functions
    int &operator[](int);
    bool isFull();
    int amountNums();
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
  //functions
    int &operator[](int);
    int &operator+=(RollOfDice &);
    bool checkAdd(int);
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
  //constructors
    QwintoScoreSheet(string, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>);
  //methods
    bool score(RollOfDice, ScoreSheet::Color, int pos = -1) override;
    bool validate(int);
    int calcTotal() override;
    bool operator!() override;
    ostream& print(ostream &) const override;
    //friends
    friend ostream &operator<<(ostream &, const QwintoScoreSheet &);
};
#endif //QWINTOSCORESHEET

//have torevise this class before implementing
#ifndef QWIXSCORESHEET
#define QWIXSCORESHEET
class QwixScoreSheet : public ScoreSheet
{
    //not used  now

    //vector red_yellow;
    //list blue_green;

  public:
  //constructors
    QwixScoreSheet(string, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>, QwintoRow<GREEN>);
  //functions
    bool score(RollOfDice, ScoreSheet::Color, int pos = -1) override;
    bool validate(int);
    int calcTotal() override;
    bool operator!() override;
    ostream& print(ostream &) const override;
    //friends
    friend ostream &operator<<(ostream &, const QwixScoreSheet &);
};
#endif //QWIXSCORESHEET