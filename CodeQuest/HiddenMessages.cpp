#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        string key;
        cin >> key;
        cin.ignore();
        for (int q = 0; q < n-1; q++) {
            string line;
            getline(cin, line);
            int temp = 0;
            string decoded = "";
            for (int i = 0; i < line.length(); i++){
                if (line[i] == '-'){
                    decoded += key[stoi(line.substr(temp,i-temp))-1];
                    temp = i+1;
                }
                if (line[i] == ' '){
                    decoded += key[stoi(line.substr(temp,i-temp))-1];
                    temp = i+1;
                    decoded += " ";
                }
                if (i == line.length()-1){
                    decoded += key[stoi(line.substr(temp,i+1-temp))-1];
                }
            }
            cout << decoded << "\n";
        }

        return 0;
}