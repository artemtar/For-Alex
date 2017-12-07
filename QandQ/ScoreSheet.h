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
    //Give the class ScoreSheet a print function that accepts an std::ostream and
  protected:
  //data
  string name_player;
  int num_failed[4];
  //functions
  virtual bool validate(int,ScoreSheet*,RollOfDice) = 0; 
    

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
  //constructor//
    ScoreSheet(string s = "");
    ScoreSheet(const ScoreSheet &from);
    virtual ~ScoreSheet();
  //functions

    
    void addFail();
    virtual bool operator!();
    friend ostream &operator<<(ostream &, const ScoreSheet &);
    virtual bool score(RollOfDice*, ScoreSheet::Color&, int pos = -1) = 0;
    virtual ostream& print(ostream &)const = 0;
    int setTotal();
    virtual int calcTotal() = 0;    
    inline int getScore(){return overallScore;}
   
};
#endif //SCORESHEET

#ifndef QWINTOROW
#define QWINTOROW

template <const ScoreSheet::Color C>
class QwintoRow 
{
  private:
    int row[10];
    

  public:
    bool validate(int,int);
    bool chosen=false;
    QwintoRow();
    int &operator[](int);
    bool isFull();
    int amountNums();
    friend ostream &operator<<(ostream &out, const QwintoRow<C> &qr)
    {
      if(C == ScoreSheet::Color::RED){
        for (auto i : qr.row)
        {
           // out << "|" << lazyLine(i);
        }
        return out;}
      if(C == ScoreSheet::Color::YELLOW){
        for (auto i : qr.row)
        {
            out << "|" << i;
        }
        return out;}
      if(C == ScoreSheet::Color::BLUE){
        for (auto i : qr.row)
        {
            out << "|" << i;
        }
        return out;}
    }
    // template <const ScoreSheet::Color C>
    // string lazyLine(int i){
    // if(i == -1) return  "  "; 
    // if(i > 0 && i < 10) return " " + to_string(i);
    // else return to_String(i);
// }
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
    int calcLine(int, int, int, int);
  public:
  //constructors
    QwintoScoreSheet(string name);//moved inside initializetion list//, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>);
    QwintoScoreSheet(const QwintoScoreSheet &from);//Aleks made copy constructor
  //methods
    bool score(RollOfDice*, ScoreSheet::Color&, int pos = -1) override;

    bool validate(int,ScoreSheet*,RollOfDice);

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
    bool score(RollOfDice*, ScoreSheet::Color&, int pos = -1) override;
    virtual bool validate(int,ScoreSheet*,RollOfDice);
    int calcTotal() override;
    bool operator!() override;
    ostream& print(ostream &) const override;
    //friends
    friend ostream &operator<<(ostream &, const QwixScoreSheet &);
};
#endif //QWIXSCORESHEET