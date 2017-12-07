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

//to print out ScoreSheet
ostream &operator<<(ostream &out, const ScoreSheet &s)
{
    out << endl;
    out << "\tPlayer's Name: " << s.name_player << endl;
    s.print(out);
    cout << endl;
    cout << "\tFails: "; 
    int count = 1;
    for (auto i : s.num_failed)
    {
        if (i == -1) break;
        else out << count << " ";
        ++count;
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
bool QwintoScoreSheet::score(RollOfDice rd, Color c, int pos)
{
    bool colourCondition = false;
    bool positionCondition =false;

    for (auto& d:rd){
        if ((d.isEnabled)&&(c==d.c)){colourCondition=true;}
    }
      //mark the chosen colour
    switch (c){
       case RED: {(*this).red.chosen=true;break;}
       case YELLOW :{(*this).yellow.chosen=true;break;}
       case BLUE :{(*this).blue.chosen=true;break;}
    }

      //check if position is ok
    positionCondition = validate(pos,this,rd);

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
ostream &QwintoScoreSheet::print(ostream &out) const
{


cout << endl;
    out << "\t\t\t-------------------------------" << endl;
    out << "\tRed";
    out << "\t\t" << red << endl;
    out << "\t\t     -------------------------------" << endl;
    out << "\tYellow";
    out << "       " << yellow << endl;
    out << "\t\t    -------------------------------" << endl;
    out << "\tBlue";
    out << "      " << blue << endl;
    out << "\t\t  -------------------------------" << endl;   
    return out;
}
//-----End of QwintoScoreSheet


//-----Initialization of QwixScoreSheet














int QwixScoreSheet::calcHelper(int i){
    if (i == 1){
    return 1;
    }
    else{
    int result = 0;
    result += calcHelper(i - 1) + i;
    //cout << result;
    return result;
    }
}

int QwixScoreSheet::calcTotal()
{

int total = 0;
    //if rows are filled count
    int fails = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (num_failed[i] != -1)
            fails += 1;
    }

    return total - 5 * fails;
}
bool QwixScoreSheet::operator!()
{
    if (num_failed[3] != 4)
        return true;
    int lock = 0;
    for (int a : locks){
        lock += a;
    }
    if(lock < 3) return true;
    //checking if two rows are full
        
    else
        return false;
}
//to put on the stream
ostream &operator<<(ostream &os, const QwixScoreSheet &qss)
{
    return qss.print(os);
}

//
ostream &QwixScoreSheet::print(ostream &out) const
{
    
cout << endl;
    out << "\t\t-------------------------------" << endl;
    out << "\tRed";
   // out << "\t\t" << red << endl;
    out << "\t\t-------------------------------" << endl;
    out << "\tYellow";
     // out << "\t\t" << red << endl;
    out << "\t\t-------------------------------" << endl;
    out << "\tGreen";
 //   out << "       " << yellow << endl;
    out << "\t\t-------------------------------" << endl;
    out << "\tBlue";
  //  out << "      " << blue << endl;
    out << "\t\t-------------------------------" << endl;   
    return out;
}

//-----End of QwixScoreSheet

int main()
{
    //testing

QwintoScoreSheet q("Name");
ScoreSheet& p = q;
cout << p;
}