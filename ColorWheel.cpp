#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    string dummy;
    getline(cin, dummy);


    for (int i = 0; i < testCases; i++){
        string color, colorOne, colorTwo;
        getline(cin, color);
        if (color == "red-violet" || color == "violet" || color == "blue-violet"){
            colorOne = "blue";
            colorTwo = "red";
        }
        else if (color == "blue-green" || color == "green" || color == "yellow-green"){
            colorOne = "blue";
            colorTwo = "yellow";
        }
        else if (color == "yellow-orange" || color == "orange" || color == "red-orange"){
            colorOne = "red";
            colorTwo = "yellow";
        }
        
        if (color == "blue" || color == "red" || color == "yellow"){
            cout << "No colors need to be mixed to make " << color << "." << "\n";
        }
        else{
            cout << "In order to make " << color << ", " << colorOne << " and " << colorTwo << " must be mixed." << "\n";
        }
    }
}
