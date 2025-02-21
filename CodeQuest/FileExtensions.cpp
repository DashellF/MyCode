#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();
        map<string,int> thing;
        string things = "";

        for (int q = 0; q < n; q++) {
            string link;
            cin >> link;
            string temp;
            for (int i = link.length() - 1; i >= 0; i--) {
                if (link[i] == '.') {
                    break;
                }
                temp = link[i] + temp;
            }
            if (things.find("." + temp + " ") == string::npos){
                things += "." + temp + " ";
            }
            thing[temp] = thing[temp] + 1;
        }   
        int period;
        for (int i = 0; i < things.length(); i++){
            if (things[i] == '.'){
                period = i;
            }
            if (things[i] == ' '){
                cout << things.substr(period+1, i-period-1) << " " << thing[things.substr(period+1, i-period-1)] << "\n";
            }
        }
        return 0;
}