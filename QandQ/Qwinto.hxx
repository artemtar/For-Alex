static int DEFAULT_ELEMENT = -1;
template <const ScoreSheet::Color C>
QwintoRow<C>::QwintoRow()
{
    for (int i = 0; i < 10; ++i)
    {
        row[i] = -1;
    }
}

template <const ScoreSheet::Color C>
bool QwintoRow<C>::validate(int index,int value)
{
    
    //conditions for wrong place 
    if (row[index]!=-1){return false;}//position teken

       for (int i=index-1;(i<index)&&(i>=0);i--){//
           if (row[i]>value){return false;}
       }
       for (int i=index+1;i<10;i++){
           if ((row[i]!=-1)&&(row[i]<value)){return false;}
       }
    //set the 
    row[index]=value;
    return true;   
}
//have to decide how to return nothing if not passing validate
template <const ScoreSheet::Color C>
int &QwintoRow<C>::operator[](int index)
{
    //
   // if (validate(index))
        return row[index];//guy said no throwing here
    //if cannot insert return -1 for error check
   // else
        //throw;//not sure if correct, check latter

}
//returns true if row is full
template <const ScoreSheet::Color C>
bool QwintoRow<C>::isFull()
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (row[i] != -1)
            ++count;
    }
    if (count == 9)
        return true;
    else
        return false;
}
//counts how many numbers in row
template <const ScoreSheet::Color C>
int QwintoRow<C>::amountNums()
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (row[i] != -1)
            ++count;
    }
    return count;
}
// template <const ScoreSheet::Color C>
// ostream &operator<<(ostream& out, const QwintoRow<C>& qr){
//     for (auto i : qr.row){
//         out << i;
//     }
//     return out;
// }
//#endif //QWINTOROW
