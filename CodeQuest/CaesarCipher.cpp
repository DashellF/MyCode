#include <bits/stdc++.h>
using namespace std;


int main() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        string alphabet = "abcdefghijklmnopqrstuvwxyz";

        int n;
        cin >> n;

        for (int u = 0; u < n; u++) {
            int shift;
            string sentence, answer;
            cin >> shift;
            cin.ignore();
            getline(cin, sentence);
            cin.ignore();
            for (int i = 0; i < sentence.length(); i++){
                if (sentence[i] == ' '){
                    answer += ' ';
                }
                else{
                    answer += alphabet[(alphabet.find(sentence[i])+shift) % 26];
                }
            }
            cout << answer << "\n";
        }
        return 0;
}