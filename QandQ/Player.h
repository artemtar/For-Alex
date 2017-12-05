#include "ScoreSheet.h"
#ifndef PLAYER
#define PLAYER

class Player
{
protected:
  string name;
  bool status = false;
  //ScoreSheet board;

public:
  Player(const string &_name = "");
  virtual ScoreSheet::Color choseColor() = 0;
  //set players status
  inline void setStatusActive(){status = true;}
  inline void setStatusInactuve(){status = false;}
  virtual int inputChecker(int, int);
  virtual inline bool getStatus(){return status;}
  virtual void inputBeforeRoll(RollOfDice &) = 0;
  virtual void inputAfterRoll(RollOfDice &) = 0;
  friend istream &operator>>(istream &, Player &);
  friend ostream &operator<<(ostream &, const Player &);

};

#endif //PLAYER

#ifndef QWINTOPLAYER
#define QWINTOPLAYER

class QwintoPlayer : public Player
{
  QwintoScoreSheet sheet;

public:
  ScoreSheet::Color choseColor() override;
  QwintoPlayer(QwintoScoreSheet &, string _name);
  virtual void inputBeforeRoll(RollOfDice &) override;
  virtual void inputAfterRoll(RollOfDice &) override;
};

#endif //QWINTOPLAYER

#ifndef QWIXPLAYER
#define QWIXPLAYER

// class QwixPlayer : public Player
// {
//   //QwixScoreSheet sheet;// comile coimplain

// public:
//   ScoreSheet::Color choseColor() override;
//   //QwixPlayer(QwixScoreSheet &, string _name); // compile complain
//   virtual void inputBeforeRoll(RollOfDice &) override;
//   virtual void inputAfterRoll(RollOfDice &) override;
// };

#endif //QWIXPLAYER