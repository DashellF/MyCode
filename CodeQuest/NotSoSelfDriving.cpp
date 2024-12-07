#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    string dummy;
    getline(cin, dummy);

    for (int i = 0; i < testCases; i++){
        string thing, v, x;
        cin >> thing;
        int colonIndex = thing.find(":");
        v = thing.substr(0, colonIndex);
        x = thing.substr(colonIndex+1);
        double vD = stod(v);
        double xD = stod(x);
        if (vD == 0){
            cout << "SAFE" << "\n";
        }
        else if (xD/vD <= 1){
            cout << "SWERVE" << "\n";
        }
        else if (xD/vD <= 5){
            cout << "BRAKE" << "\n";
        }
        else {
            cout << "SAFE" << "\n";
        }
    }
}
