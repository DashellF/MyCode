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
            string sentence;
            getline(cin, sentence);
            int word = 1;
            for (int i = 0; i < sentence.length()-4; i++){
                if (sentence.substr(i,4) == "Nimo"){
                    break;
                }
                if (sentence[i] == ' '){
                    word++;
                }
            }
            cout << word << "\n";
        }

        return 0;
}