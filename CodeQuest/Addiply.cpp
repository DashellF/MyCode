#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    string dummy;
    getline(cin, dummy);

    for (int i = 0; i < testCases; i++){
        int numOne,numTwo, space;
        string input, strOne, strTwo;
        getline(cin, input);
        space = input.find(" ");
        strOne = input.substr(0, space);
        strTwo = input.substr(space + 1);
        numOne = stoi(strOne);
        numTwo = stoi(strTwo);
        cout << numOne + numTwo << " " << numOne * numTwo << "\n";
    }
}
