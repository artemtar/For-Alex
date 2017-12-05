
#include "ScoreSheet.h"
#include "Player.h"
#include "Dices.h"
#include <iostream>
#include <vector>

//using namespace std;

int main(){
   std:string gameVersion;

   //get version
   std::cout<<" Please input 0 if you want to play Quinto and 1 if you want to play Quixx : ";
   std::cin>>gameVersion;  

   //get Number Of Players
   int numOfPlayers;
   std::cout<<" Please input the number of player that you want to have : ";
   std::cin>>numOfPlayers;  
   std::vector<Player> players;  
    
   //create all required players and 
   for (int i = 0;i<numOfPlayers;i++){
       std::string currentName; 
       std::cout<<"What is the name of the player "<<i+1<<" : ";
       std::cin>> currentName;
       QwintoScoreSheet currentScoreSheet{currentName};
       QwintoPlayer currentPlayer{currentScoreSheet,currentName};

      // players.push_back(currentPlayer);  //need to add to the vector//copy constructors????

       std::cout<<"\n Player "<<i+1<<" with name : "<< currentName <<" is created.";
   }
  

    while(true){

        std::cout<<"Please input the number of dices do you want to roll as a number?";
        //ask if the player wants to roll 1,2 or 3 dices
        
        std::cout<<"What is the colour of the dices you want to roll?";
        //if wrong print all available colours
        
        //for all the players
            //if player can put it in his scoresheet
                std::cout<<" Do you want to use the score of this dices rolled?";
                //if yes
                    std::cout<<" What is the row that you want to put your score into?";
                    //if can
                        //if filled two rows
                           //game over
                           break;
            //else
                //if current player cannot put sccore in his board
                   //-5points from the final score of the player
                   // number of failed throws ++ //for this player??
                   // if failed Throws==4
                       //game over
                       break;
               
                   
          
    }
    //game over calculate the score
       //get the right score of the completed one



// int main(){
//     //test only
//     RollOfDice rd;
//     QwintoRow <ScoreSheet::RED>r;
//     QwintoRow <ScoreSheet::YELLOW>y;
//     QwintoRow <ScoreSheet::BLUE>b;
//     QwintoScoreSheet artemBoard("Artem", r, y, b);
//     QwintoPlayer artem (artemBoard, "Artem");
//     Player& p = artem;
//     p.setStatusActive();
//     p.inputBeforeRoll(rd);
}