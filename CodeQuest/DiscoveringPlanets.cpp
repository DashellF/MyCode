#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int q = 0; q < n; q++) {
            double temp;
            string water, surface;
            double circle;
            cin >> temp >> water >> surface >> circle;
            if (temp > 100){
                cout << "The planet is too hot.\n";
            }
            else if (temp < 0){
                cout << "The planet is too cold.\n";
            }
            else if (water == "false"){
                cout << "The planet has no water.\n";
            }
            else if (surface == "false"){
                cout << "The planet has no magnetic field.\n";
            }
            else if (circle > 0.6){
                cout << "The planet's orbit is not ideal.\n";
            }
            else {
                cout << "The planet is habitable.\n";
            }
        }

        return 0;
}