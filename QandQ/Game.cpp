
#include "ScoreSheet.h"
#include "Player.h"
#include "Dices.h"
#include <iostream>
#include <vector>
#include <algorithm> 

int inputCheckerForMain(int boundA, int boundB)
{
    int choice = -1;
    while (42)
    {
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
        }
        if (!(choice < boundA) && !(choice > boundB))
            break;
        else
            cout << "Invalid input. Try again: ";
    }
    return choice;
}

int main()
{
    int gameVersion = -1;

    //get Number Of Players
    int numOfPlayers = -1;
    std::cout << " Please input the number of player that you want to have, minimum requerment is 2 : ";
    numOfPlayers = inputCheckerForMain(2, 6); //i think 6 is max
    cout << endl;
    vector<Player *> players; //to keep the players

    std::cout << " Please input 1 if you want to play Quinto and 2 if you want to play Quixx : ";
    gameVersion = inputCheckerForMain(1, 2);
    //poolimorphic part  is here, depending on game vertion,
    //we are having different players, after switch statement
    //the game should look the same for both game types
    switch (gameVersion)
    {
    case 1:
    {
        //create all required players and
        int count = 0;
        for (int i = 0; i < numOfPlayers; i++)
        {
            std::string tempName;

            std::cout << "What is the name of the player " << i + 1 << ": ";
            std::cin >> tempName;
            cout << endl;
            QwintoScoreSheet* tempScoreSheet = new QwintoScoreSheet {tempName};
            Player* tempPlayer = new QwintoPlayer{tempScoreSheet, tempName};
            // took me an hour to get here, every time you have been out of loop it was destroing the object.
            // we have to use new a lot, and now we actually need virtual destructors
            players.push_back(tempPlayer);
            std::cout << "Player " << i + 1 << " with name : " << tempName << " is created." << endl;
        ++count; 
        }
         cout << "out of loop " << count << endl; //this line, and custom distructor helped me to find the bag
    }
    break;

    case 2:
    {
        //creating qwixx players
    }

    break;
    }

    RollOfDice currentRoll{};
    //virtual functions work, but does some wierd shit with dices,
    // too lazy to understand how you wanna to implement it, so uncoment line 88 and do your staff
    while (true)
    {
       for ( auto p : players) {
            std::cout << "Please input the number of dices do you want to roll?(1,2 or 3) : ";
            //ask if the player wants to roll 1,2 or 3 dices
            int currentRollNumOfDices = -1;
            currentRollNumOfDices = inputCheckerForMain(1, 3);
            //get the colours of the dices from the user and roll the dices with the selected collour
            //p->inputBeforeRoll(currentRoll, currentRollNumOfDices);
        }
        // std::cout<<currentScore
        break;//for artem, can remove
    }
    //if wrong print all available colours

    //         //for all the players
    //             //if player can put it in his scoresheet
    //                 std::cout<<" Do you want to use the score of this dices rolled?";
    //                 //if yes
    //                     std::cout<<" What is the row that you want to put your score into?";
    //                     //if can
    //                         //if filled two rows
    //                            //game over
    //                            break;
    //             //else
    //                 //if current player cannot put sccore in his board
    //                    //-5points from the final score of the player
    //                    // number of failed throws ++ //for this player??
    //                    // if failed Throws==4
    //                        //game over
    //                        break;
    //     }
    //game over calculate the score
    //get the right score of the completed one

//artem staff
//for_each(players.begin(), players.end(), [](auto p){ScoreSheet s =p->getScoreSheet; s.setTotal;});

}
