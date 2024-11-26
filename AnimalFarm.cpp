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
        string animals = "", turkey = "", goats = "", horses = "";
        int turkeyI, goatsI, horsesI = 0;
        int k = 0;
        getline(cin, animals);
        while(animals.at(k) != ' '){
            turkey += animals.substr(k, k+1);
            k++;
        }
        k++;
        while(animals.at(k) != ' '){
            goats += animals.substr(k, k+1);
            k++;
        }
        k++;
        horses = animals.substr(k);
        turkeyI = stoi(turkey);
        goatsI = stoi(goats);
        horsesI = stoi(horses);
        cout << turkeyI*2 + goatsI*4 + horsesI*4 << "\n";
    }
}
