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

            string phrase;
            getline(cin, phrase);

            //count how many times certain letters appear
            map<char,int> abcs = {};
            sort(map.begin(), map.end(), [](const &int a, const &int b) { return a < b; });
            for (int i = 0; i < phrase.length(); i++){
                if (phrase[i] != ' '){
                    abcs[phrase[i]]++;
                }
            }
            

            //find max num of letters
            int max = 0;
            for (int i = 0; i < phrase.length(); i++){
                if (abcs[phrase[i]] > max){
                    max = abcs[phrase[i]];
                }
            }

            cout << max << "\n";
        }
}