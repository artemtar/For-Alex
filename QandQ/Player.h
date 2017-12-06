#include "ScoreSheet.h"
#ifndef PLAYER
#define PLAYER

class Player
{
protected:
  bool status = false;
 

public:
  //data
  string name;
  ScoreSheet* sheet;
  //constructor

  Player(ScoreSheet*, const string &_name = "");
  Player(const Player&);
  virtual ~Player();

  ScoreSheet::Color choseColor();
  //set players status

  inline void setStatusActive(){status = true;}
  inline void setStatusInactuve(){status = false;}
  inline ScoreSheet* getScoreSheet(){return sheet;}
  virtual int inputChecker(int, int);
  virtual inline bool getStatus(){return status;}
  virtual  std::vector<ScoreSheet::Color> inputBeforeRoll(RollOfDice &,int) = 0;
  virtual void inputAfterRoll(RollOfDice &) = 0;
  //friend istream &operator>>(istream &, Player &);// most like likely do not need leave it for now
  bool operator <(const Player&);
  friend ostream &operator<<(ostream &, const Player &);
  
};

#endif //PLAYER

#ifndef QWINTOPLAYER
#define QWINTOPLAYER

class QwintoPlayer : public Player
{
public:
  //constructors
    QwintoPlayer(QwintoScoreSheet*, string _name);
    QwintoPlayer(const QwintoPlayer &from);
    ~QwintoPlayer();//for debuging
  //functions
   // ScoreSheet::Color choseColor() override;
    //virtual
     std::vector<ScoreSheet::Color> inputBeforeRoll(RollOfDice &,int) override;
    virtual void inputAfterRoll(RollOfDice &) override;
};

#endif //QWINTOPLAYER

#ifndef QWIXPLAYER
#define QWIXPLAYER

// class QwixPlayer : public Player
// {

// public:
//   ScoreSheet::Color choseColor() override;
//   //QwixPlayer(QwixScoreSheet &, string _name); // compile complain
//   virtual void inputBeforeRoll(RollOfDice &) override;
//   virtual void inputAfterRoll(RollOfDice &) override;
// };

#endif //QWIXPLAYER