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

  virtual bool validate(int,ScoreSheet*,RollOfDice*) = 0; 
    


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
  virtual bool score(RollOfDice*, ScoreSheet::Color, int pos = -1) = 0;
  virtual bool checkForFail(RollOfDice*,ScoreSheet*)=0;
  virtual ostream &print(ostream &) const = 0;
  int setTotal();
  virtual int calcTotal() = 0;
  inline int getScore() { return overallScore; }

};
#endif //SCORESHEET

#ifndef QWINTOROW
#define QWINTOROW
string lazyLine(int i);
template <const ScoreSheet::Color C>
class QwintoRow
{
private:
  int row[10];

public:
  bool validate(int, int);
  bool chosen = false;
  QwintoRow();
  int &operator[](int);
  bool isFull();
  int amountNums();
  //should i make it inline? :D
  friend ostream &operator<<(ostream &out, const QwintoRow<C> &qr)
  {
    //please do not read this, I was drunk
    if (C == ScoreSheet::Color::RED)
    {
      int i = 0;
      cout << "|";
      for (auto j : qr.row)
      {

        string num = "";
        if (i == 3)
          num = "XX";
        else
        {
          if (j == -1)
            num = "  ";
          else
          {
            if (i > 0 && i < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          }
        }

        out << num;

        if (i == 0 || i == 1 || i == 4 || i == 5)
          cout << "%";
        else
          out << "|";
        i += 1;
      }
      return out;
    }

    if (C == ScoreSheet::Color::YELLOW)
    {
      int i = 0;
      cout << "|";
      for (auto j : qr.row)
      {

        string num = "";
        if (i == 5)
          num = "XX";
        else
        {
          if (j == -1)
            num = "  ";
          else
          {
            if (i > 0 && i < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          }
        }

        out << num;

        if  (i == 6 || i == 7)
          cout << "%";
        else
          out << "|";
        i += 1;
      }
      return out;
    }

    if (C == ScoreSheet::Color::BLUE)
    {
      int i = 0;
      cout << "|";
      for (auto j : qr.row)
      {

        string num = "";
        if (i == 4)
          num = "XX";
        else
        {
          if (j == -1)
            num = "  ";
          else
          {
            if (i > 0 && i < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          }
        }

        out << num;

        if (i == 1 || i == 2 || i == 8 || i == 9)
          cout << "%";
        else
          out << "|";
        i += 1;
      }
      return out;
    }
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
  T row[11];
  //functions
  bool validate(T) override;
  

public:
  //functions
  int &operator[](T);
  int &operator+=(RollOfDice &);
  bool checkAdd(T);
  friend ostream &operator<<(ostream &out, const QwixRow<T, C> &qr)
  {
    for (auto i : qr.row)
    {
      out << i;
    }
    return out;
  }
};
//#include "Qwix.hxx"
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

  QwintoScoreSheet(string name);                  //moved inside initializetion list//, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>);
  QwintoScoreSheet(const QwintoScoreSheet &from); //Aleks made copy constructor
                                                  //methods
  bool score(RollOfDice*, ScoreSheet::Color, int pos = -1) override;
  bool validate(int, ScoreSheet*, RollOfDice*)override;
  bool checkForFail(RollOfDice*,ScoreSheet*);

  int calcTotal() override;
  bool operator!() override;
  ostream &print(ostream &) const override;
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
//template <class T, const ScoreSheet::Color C>
// vector<QwintoRow<Color::C> > red_yellow;
  //list blue_green;
  int locks [4] = {1,1,1,1};

public:
  //constructors
  QwixScoreSheet(string, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>, QwintoRow<GREEN>);
  //functions

  bool score(RollOfDice*, ScoreSheet::Color, int pos = -1) override;
  bool checkForFail(RollOfDice*,ScoreSheet*) override;
  virtual bool validate(int, ScoreSheet *, RollOfDice*);
  int calcHelper(int);
  int calcTotal() override;
  bool operator!() override;
  ostream &print(ostream &) const override;
  //friends
  friend ostream &operator<<(ostream &, const QwixScoreSheet &);

};
#endif //QWIXSCORESHEE