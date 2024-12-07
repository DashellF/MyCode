#include <bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;
    cin.ignore();
    for(int testcase = 0; testcase < testCases; testcase++){
        double d, r, t;
        cin >> d >> r;
        t = round(d/r * 1000000 * 60 * 60);
        int seconds = (int)t % 60;
        t /= 60;
        int minutes = (int)t % 60;
        t /= 60;
        int hours = (int)t % 24;
        t /= 24;
        int days = t;
        cout << "Time to Mars: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << "\n";
    }
}

