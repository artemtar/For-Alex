#include "Dices.h"
#include "ScoreSheet.h"
#include "Player.h"


int main(){
    //test only
    RollOfDice rd;
    QwintoRow <ScoreSheet::RED>r;
    QwintoRow <ScoreSheet::YELLOW>y;
    QwintoRow <ScoreSheet::BLUE>b;
    QwintoScoreSheet artemBoard("Artem", r, y, b);
    QwintoPlayer artem (artemBoard, "Artem");
    Player& p = artem;
    p.setStatusActive();
    p.inputBeforeRoll(rd);



    

}