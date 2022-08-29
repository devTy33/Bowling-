include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;


int main()
{   // change the nameCheck variable to 1 after a name is 'pushback' into the name vector...so if nameCheck ==0 , no names were entered;
    int nameCheck = 0;
    int maxName = 0;
    int minName = 0;
    string playerName;
    vector<string> names;
    vector<int> totalScore;
    vector<int> rollValues;
    // A while loop is neccesary to have multiple players and to calculate there scores while the put in input.
    while (true)
    {   //Score storing vector needs to be cleared before a new player is added.
        rollValues.clear();

        cout << "Enter player's name (done for no more players) :" ;
        cin >> playerName;

        if  (playerName == "done") {
            if (nameCheck == 0){
                cout << "No players were entered" << endl;
            }

            break;
        }
        else
        {
            names.push_back(playerName);
            nameCheck = 1;

            int rollX, rollY, rollZ = 0;
            // for loop for frames 1-9 because the 10th (last frame) is different.
            for (int i = 0; i < 9; i++)
            {
                cout << "Enter score for frame" << i + 1 << ", roll 1: ";
                cin >> rollX;
                rollValues.push_back(rollX);
                // If rollX is a strike move to the next frame.
                if (rollX < 10)
                {
                    cout << "Enter score for frame" << i + 1 << ", roll 2: ";
                    cin >> rollY;
                    rollValues.push_back(rollY);
                }
                else
                {   // Pushback zeros to make a vector size of 21 which also makes the math funcitons easier.
                    rollValues.push_back(0);
                }
            }

            cout << "Enter score for frame 10, roll 1: ";
            cin >> rollX;
            rollValues.push_back(rollX);
           cout << "Enter score for frame 10, roll 2: ";
            cin >> rollY;
            rollValues.push_back(rollY);

            // you only get to roll a third time on the 10th frame if you get a spare or a strike
            if ((rollY+rollX) == 10 || (rollX == 10) )
            {
                cout << "Enter score for frame 10, roll 3: ";
                cin >> rollZ;
                rollValues.push_back(rollZ);
            }


        }

        int total = 0;
        // Iterate through the first 9 frames (iterator of +=2 so it goes through frames and not roles).
        for (int j = 0; j < 18; j+=2) {
            //if the first two roles in a frame aren't a strike or spare just add to total.
            if((rollValues[j]+rollValues[j+1]) < 10) {
                total+= rollValues[j] + rollValues[j+1];

            }
            // if the 2 roles add to 10 and the first roll isn't 10; add the 10 points from the first frame to the first role of the next frame.
            else if((rollValues[j]+rollValues[j+1])==10 && rollValues[j] != 10) {
                total += rollValues[j] + rollValues[j+1] + rollValues[j+2];

            }

            else if(rollValues[j] == 10 && rollValues[j+1] == 0 ){
                // if you roll consecutive strikes
                if (rollValues[j+2] == 10 && rollValues[j+3]==0) {
                    total += rollValues[j]+rollValues[j+2]+rollValues[j+4];
                }
                //if you roll one strike, add it to the total point value of the next frame.
                else{
                    total+= rollValues[j] + rollValues[j+2] + rollValues[j+3];
                }

            }

        }
        //Since 10th frame works differently, add the scores outside of the for loop.
        total = total + rollValues[18]+ rollValues[19] +rollValues[20];
        totalScore.push_back(total);

    }
  // if only 1 player is entered, you only need to print their total score once.
 if(names.size() == 1) {
            cout << names[0] << " " << "scored" << " " << totalScore[0] << endl<<".";
            cout << names[0] << " " << "did the worst by scoring" << " " << totalScore[0] << endl<<".";
            cout << names[0] << " " << "did the best by scoring" << " " << totalScore[0] << endl<<".";

        }
        else {
           int min = totalScore[0];
           int max = totalScore[0];
           // loop through the total score vector and if a values at the whatever i index is less than the values of the first index, than it is a minimum. 
           for(int i = 0; i < totalScore.size(); i++) {
               if(totalScore[i] < min) {
                   min = totalScore[i];
                  // Even though 'names' is a different vector, its' index corresponds with the player's total in 'totalScore'....so I can use 'i' for both.
                   minName = i;
               }
           }
            for(int i = 0; i < totalScore.size(); i++) {
               if(totalScore[i] > max) {
                   max = totalScore[i];
                   maxName = i;
               }
            }


           cout << names[maxName] << " " << "scored" << " " << max<<"."<< endl;
           cout << names[minName] << " " << "scored" << " " << min<<"."<<endl;

           cout << names[minName] << " " << "did the worst by scoring" << " " << min<<"."<<endl;
           cout << names[maxName] << " " << "won the game by scoring" << " " << max<<"."<<endl;
        }



return 0;

}



