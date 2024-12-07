#include <string>
#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int testCases;
        cin >> testCases;
        cin.ignore();

        for (int i = 0; i < testCases; i++){
                string input = "", x = "", y = "", z = "";
                int xI, yI, zI = 0;
                int k = 0;
                getline(cin, input);
                while(input.at(k) != ' '){
                        x += input.substr(k, k+1);
                        k++;
                }
                k++;
                while(input.at(k) != ' '){
                        y += input.substr(k, k+1);
                        k++;
                }
                k++;
                z = input.substr(k);
                xI = stoi(x);
                yI = stoi(y);
                zI = stoi(z);
                                     
                xI += 180;
                yI += 180;
                zI += 180;
                if (xI > 360){
                        xI -= 360;
                }
                if (yI > 360){
                        yI -= 360;
                }
                if (zI > 360){
                        zI -= 360;
                }
                cout << xI << " " << yI << " " << zI;
        }
        return 0;
}

