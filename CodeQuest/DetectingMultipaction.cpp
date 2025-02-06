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
            string one, two;
            getline(cin, one);
            getline(cin, two);
            vector<double> lone;
            vector<double> ltwo;
            int pindex = 0;
            int tindex = 0;
            while (one.length() > tindex){
                if (!isdigit(one[tindex]) && one[tindex] != '.'){
                    lone.push_back(stod(one.substr(pindex, tindex-pindex)));
                    pindex = tindex+1;
                }
                tindex++;
            }
            lone.push_back(stod(one.substr(pindex)));
            pindex = 0;
            tindex = 0;
            while (two.length() > tindex){
                if (!isdigit(two[tindex]) && two[tindex] != '.'){
                    ltwo.push_back(stod(two.substr(pindex, tindex-pindex)));
                    pindex = tindex+1;
                }
                tindex++;
            }
            ltwo.push_back(stod(two.substr(pindex)));
            int occurences = 0;
            string indexes = "";
            for (int i = 0; i < lone.size(); i++){
                if (lone[i] >= 0.6 && lone[i] <= 0.85 && ltwo[i] >= 0.6 && ltwo[i] <= 0.85){
                    occurences++;
                    indexes += " " + to_string(i);
                }
            }
            if (occurences == 0){
                cout << "No multipaction events detected." << "\n";
            }
            else if (occurences == 1){
                cout << "A multipaction event was detected at time index" << indexes << ".\n";
            }
            else {
                cout << occurences <<  " multipaction events were detected at time indices:" << indexes << ".\n";
            }
        }

        return 0;
}