#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    cin.ignore();
    for(int testcase = 0; testcase < testCases; testcase++){
        string text;
        getline(cin, text);
        cout << text << '\n';
    }
}
