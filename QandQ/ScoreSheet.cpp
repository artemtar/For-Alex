#include "ScoreSheet.h"

//**ScoreSheet**

//constructor
ScoreSheet::ScoreSheet(string name) : name_player(name)
{
    for (int i = 0; i < 4; ++i)//don't like it!!
    {
        num_failed[i] = -1;
    }
}
//same as always, not sure if you need it, you just defining default constructor
ScoreSheet::ScoreSheet(const ScoreSheet& from):name_player(from.name_player),overallScore(from.overallScore){
   for (int i = 0; i < 4; ++i)//don't like it
    {
        num_failed[i] = from.num_failed[i];
    }
}
ScoreSheet::~ScoreSheet(){}

//to add fail into num_fail
void ScoreSheet::addFail(){
    for(auto i = 0; i < 3; i++){
         if(num_failed[i] == -1){
             num_failed[i] = i + 1;
             break;
         } 
    }
}
int ScoreSheet::setTotal(){
    overallScore = calcTotal();
    return overallScore;
}
//if fails is 4, stop the game
bool ScoreSheet::operator!()
{cout << "this line should not appeatr";}

//not used dnow

// void ScoreSheet::print(ostream &os){
//     os << name_player;
//     return os;
// }

//to print out ScoreSheet
ostream &operator<<(ostream &out, const ScoreSheet &s)
{
    out << s.name_player;
    s.print(out);
    for (auto i : s.num_failed)
    {
        out << i << " ";
    }
    return out << endl;
}
//-----End of Scoresheet

//-----Initialization of QwintoScoresheet
//constructor
QwintoScoreSheet::QwintoScoreSheet(string name)
            : ScoreSheet(name), red( QwintoRow<RED>{}), yellow(QwintoRow<YELLOW>{}), blue( QwintoRow<BLUE>{}) {}// Aleks moved row to be created inside initializetion list
QwintoScoreSheet::QwintoScoreSheet(const QwintoScoreSheet &from):ScoreSheet(from.name_player),red(from.red),yellow(from.yellow),blue(from.blue){}//need to give a name
//template<class T>
bool QwintoScoreSheet::validate(int index,ScoreSheet* sheet,RollOfDice rollOfDices){ 
    bool out =false;

    QwintoScoreSheet* qwintoSheet=dynamic_cast<QwintoScoreSheet*> (sheet);

    if ((*qwintoSheet).red.chosen){out = (*qwintoSheet).red.validate(index,rollOfDices);}
    else if ((*qwintoSheet).yellow.chosen){out = (*qwintoSheet).yellow.validate(index,rollOfDices);}
    else if((*qwintoSheet).blue.chosen){out = (*qwintoSheet).blue.validate(index,rollOfDices);}
    return true;
}


//to check if can put in the position
bool QwintoScoreSheet::score(RollOfDice* rd, Color& c, int pos)
{
    bool colourCondition = false;
    bool positionCondition =false;

    for (Dice& d:*rd){
        if ((c==d.c)&&(d.isEnabled)){
            cout<<"hiTherw";
            colourCondition=true;}
    }
      //mark the chosen colour
    switch (c){
       case RED: {(*this).red.chosen=true;break;}
       case YELLOW :{(*this).yellow.chosen=true;break;}
       case BLUE :{(*this).blue.chosen=true;break;}
    }

      //check if position is ok
    positionCondition = validate(pos,this,*rd);
    //cout<<(colourCondition==true)<<"hi"<<(positionCondition==true)<<endl;
    if (colourCondition&&positionCondition){return true;}
    else{return false;}
    
}
int QwintoScoreSheet::calcLine(int a, int b, int c, int val){
    if(a != -1 && b != -1, c != -1) return val;
    else return 0;
}
//get the toral
int QwintoScoreSheet::calcTotal()
{
    //calculating rows
    int rowsTotal = 0;
    if (red.isFull())
        rowsTotal += red[9];
    else
        rowsTotal = red.amountNums();
    if (yellow.isFull())
        rowsTotal += yellow[9];
    else
        rowsTotal = yellow.amountNums();
    if (red.isFull())
        rowsTotal += blue[9];
    else
        rowsTotal = blue.amountNums();
    //calculating columns
    int colTotal = 0;
    colTotal += calcLine(red[0], yellow[1], blue[3], blue[3]);
    colTotal += calcLine(red[1], yellow[2], blue[4], red[1]);
    colTotal += calcLine(red[5], yellow[6], blue[7], red[5]);
    colTotal += calcLine(red[6], yellow[7], blue[8], yellow[7]);
    colTotal += calcLine(red[7], yellow[8], blue[9], blue[9]);
    int fails = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (num_failed[i] != -1)
            fails += 1;
    }

    return rowsTotal + colTotal - 5 * fails;
}
//have to be polimorphic
bool QwintoScoreSheet::operator!()
{
    if (num_failed[3] != 4)
        return true;
    //checking if two rows are full
    int check = red.isFull() + yellow.isFull() + blue.isFull();
    if (check < 2)
        return true;
    else
        return false;
}
//to put on the stream
ostream &operator<<(ostream &os, const QwintoScoreSheet &qss)
{
    return qss.print(os);
}
//chenge design
ostream &QwintoScoreSheet::print(ostream &out) const
{

    //ScoreSheet::print(out);
    // out << *parent << endl;
    // out << "        -------------------------------" << endl;
    // out << "Red         ";

    // out << "    " << red << endl;
    // out << "  -------------------------" << endl;
    // out << "  " << yellow << endl;
    // out << "-------------------------" << endl;
    // out << "" << blue << endl
    //     << endl;
    // out << "Failed: ";
    //for (int i = 0; i < 4; ++i)
    // {
    //     if (*(parent->getFails() + i) != 100) //for debuging change 100 to -1 when finished
    //         cout << *(parent->getFails() + i) << " ";
    // }
    cout << "Lets imagine that board is printed"<< endl;
    return out;
}
//-----End of QwixScoreSheet

//-----Initialization of QwixScoreSheet

//to put on the stream
ostream &operator<<(ostream &os, const QwixScoreSheet &qss)
{
    return qss.print(os);
}

//
ostream &QwixScoreSheet::print(ostream &out) const
{
}
//-----End of QwintoScoreSheet
// int main()
// {
//     //testing

//     RollOfDice r;
//     cout << r << "roled" << endl;
//     qr[2] = r;
//     QwintoScoreSheet qs("Artem", qr, qy, qb);
//     ScoreSheet& parent = qs;
//     cout << parent;
//     r.roll();
//     parent.score(r, ScoreSheet::Color::RED, 5);
//     cout << parent;
// }