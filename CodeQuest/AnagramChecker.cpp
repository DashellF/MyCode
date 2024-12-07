#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    cin.ignore();
    
    for (int i = 0; i < testCases; i++){
        string sentence;
        getline(cin, sentence);
        string tempOne;
        string tempTwo;
        int space = sentence.find("|");
        tempOne = sentence.substr(0,space);
        tempTwo = sentence.substr(space+1);
        if (tempOne == tempTwo){
            cout <<  sentence  << " = NOT AN ANAGRAM" << "\n";
        }
        else{
            while (tempOne != "" ){
                if (tempTwo.find(tempOne.at(0)) == -1){
                    cout <<  sentence  << " = NOT AN ANAGRAM" << "\n";
                    break;
                }
                tempTwo = tempTwo.substr(0,tempTwo.find(tempOne.substr(0,1))) + tempTwo.substr(tempTwo.find(tempOne.substr(0,1)) + 1);
                tempOne = tempOne.substr(1);
            }
        }
        if (tempOne == "" & tempTwo == ""){
            cout << sentence << " = ANAGRAM" << "\n" ;
        }
    }
}
