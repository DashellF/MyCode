#include <bits/stdc++.h>
using namespace std;

int main(){
    int cows, interactions;
    string cowInfection;
    cin >> cows >> interactions;
    cin >> cowInfection;
    int interact[interactions][3];
    int t, x, y;
    //get them all into an array
    for(int i = 0; i < interactions; i++){
        cin >> t >> x >> y;
        interact[i][0] = t;
        interact[i][1] = x;
        interact[i][2] = y;
    }
    // cout << "unsorted array: " << "\n";
    // for (int i = 0; i < interactions; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << interact[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    //sort this array from low time to high time
    for (int i = 0; i < interactions - 1; i++){
        for (int k = 0; k < interactions - 1; k++){
            if (interact[i][0] > interact[i+1][0]){
                // cout << "replacing interaction " << i << " with action " << i+1 << "\n";
                t = interact[i][0];
                x = interact[i][1];
                y = interact[i][2];
                interact[i][0] = interact[i+1][0];
                interact[i][1] = interact[i+1][1];
                interact[i][2] = interact[i+1][2];
                interact[i+1][0] = t;
                interact[i+1][1] = x;
                interact[i+1][2] = y;
                //print new array
                // for (int i = 0; i < interactions; i++) {
                //     for (int j = 0; j < 3; j++) {
                //         cout << interact[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
            }
        }
    }
    // cout << "sorted array:" << "\n";
    // for (int i = 0; i < interactions; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << interact[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    //the logic
    int possibleZero = 0;
    int max = 0;
    for (int i = 0; i < cows; i++){
        int numInfected[cows] = {0}; //number of times each cow passes along the infection
        //create starting string
        string possibleInfection = "";
        for (int k = 0; k < i; k++){
            possibleInfection += "0";
        }
        possibleInfection += "1";
        for (int k = 0; k < cows-i-1; k++){
            possibleInfection += "0";
        }
        
        for (int l = 0; l < interactions; l++){
            if (possibleInfection[interact[l][1]-1] == '1'){
                possibleInfection[interact[l][2]-1] = '1';
                numInfected[interact[l][1]-1] = numInfected[interact[l][1]-1] + 1;
            }
        }
        if (possibleInfection == cowInfection){
            possibleZero++;
            //finds min number of times necessary to pass on the infection
            max = 0;
            for (int i = 0; i < cows; i++){
                if (numInfected[i] > max){
                    max = numInfected[i];
                }
            }
        }
    }
    string z = "Infinity";
    cout << possibleZero << " " << max << " " << z << "\n";
}
