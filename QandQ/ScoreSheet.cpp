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
ScoreSheet::ScoreSheet(const ScoreSheet& from):name_player(from.name_player),overallScore(from.overallScore),ended(from.ended){

   for (int i = 0; i < 4; ++i)//don't like it
    {
        num_failed[i] = from.num_failed[i];
    }
}

//to add fail into num_fail
void ScoreSheet::addFail(){
    for(auto i = 0; i < 3; i++){
         if(num_failed[i] == -1){
             num_failed[i] = i + 1;
             break;
         } 
    }
}
//if fails is 4, stop the game
bool ScoreSheet::operator!()
{
    if (num_failed[3] == 4)
        return true;
    else
        return false;
}

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
QwintoScoreSheet::QwintoScoreSheet(const QwintoScoreSheet &from):ScoreSheet(),red(from.red),yellow(from.yellow),blue(from.blue){}//need to give a name

bool QwintoScoreSheet::validate(int index){}
//to return the score
bool QwintoScoreSheet::score(RollOfDice rd, Color c, int pos)
{
    //more code is requered
    switch (c)
    {
    case ScoreSheet::Color::RED:
        red[pos] = rd; //do something, have to finish validation
        break;
    case ScoreSheet::Color::YELLOW:
        yellow[pos] = rd; //do something
        break;
    case ScoreSheet::Color::BLUE:
        blue[pos] = rd; //do something
        break;
    }
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
    if (red[0] != -1 && yellow[1] != -1 && blue[3] != -1)
        colTotal += blue[3];
    if (red[1] != -1 && yellow[2] != -1 && blue[4] != -1)
        colTotal += red[1];
    if (red[5] != -1 && yellow[6] != -1 && blue[7] != -1)
        colTotal += red[5];
    if (red[6] != -1 && yellow[7] != -1 && blue[8] != -1)
        colTotal += yellow[7];
    if (red[7] != -1 && yellow[8] != -1 && blue[9] != -1)
        colTotal += blue[9];

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
    ScoreSheet &parent = *this;
    if (!parent)
        return false;
    //checking if two rows are full
    int check = red.isFull() + yellow.isFull() + blue.isFull();
    if (check < 2)
        return false;
    else
        return true;
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
    out << "    -------------------------" << endl;
    out << "    " << red << endl;
    out << "  -------------------------" << endl;
    out << "  " << yellow << endl;
    out << "-------------------------" << endl;
    out << "" << blue << endl
        << endl;
    out << "Failed: ";
    //for (int i = 0; i < 4; ++i)
    // {
    //     if (*(parent->getFails() + i) != 100) //for debuging change 100 to -1 when finished
    //         cout << *(parent->getFails() + i) << " ";
    // }
    cout << endl;
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
//     QwintoRow<ScoreSheet::Color::RED> qr;
//     QwintoRow<ScoreSheet::Color::YELLOW> qy;
//     QwintoRow<ScoreSheet::Color::BLUE> qb;
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