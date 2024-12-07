#include <bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    cin.ignore();
    for(int testcase = 0; testcase < testCases; testcase++){
        int c, l, diff;
        cin >> c >> l;
        diff = c - l;
        if (diff > 0){
            cout << "Cassowary Craft sold " << diff << " more aircraft" << "\n";
        }
        else if (diff < 0){
            diff *= -1;
            cout << "Lead Balloons Ltd sold " << diff << " more aircraft" << "\n";
        }
        else {
            cout << "Cassowary Craft and Lead Balloons Ltd sold the same number of aircraft" << "\n";
        }
    }
}

