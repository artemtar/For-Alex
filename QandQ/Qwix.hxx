template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
QwixRow<C, Container>::QwixRow(){
    for(int i = 2; i < 13; ++i){
        row.push_back(i);
    }    
}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
bool QwixRow<C, Container>::validate(int index)
{
    // //out of range
    // if (index > 11 || index < 0)
    //     return false;
    // //has input already
    // else if (row[index] != -1)
    //     return false;
    // else
         return true;
}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
int &QwixRow<C, Container>::operator[](int index)
{
    if (validate())
    return row[index];
    else return false;
}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
int &QwixRow<C, Container>::operator+=(RollOfDice &) {

}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
bool QwixRow<C, Container>::checkAdd(int) {

}

