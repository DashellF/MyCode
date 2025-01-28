#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();
        
        map<char, string> code = {
        {'a', "Alpha"}, {'b', "Bravo"}, {'c', "Charlie"}, {'d', "Delta"},
        {'e', "Echo"}, {'f', "Foxtrot"}, {'g', "Golf"}, {'h', "Hotel"},
        {'i', "India"}, {'j', "Juliet"}, {'k', "Kilo"}, {'l', "Lima"},
        {'m', "Mike"}, {'n', "November"}, {'o', "Oscar"}, {'p', "Papa"},
        {'q', "Quebec"}, {'r', "Romeo"}, {'s', "Sierra"}, {'t', "Tango"},
        {'u', "Uniform"}, {'v', "Victor"}, {'w', "Whiskey"}, {'x', "Xray"},
        {'y', "Yankee"}, {'z', "Zulu"}
        };

        for (int q = 0; q < n; q++) {
            int u;
            cin >> u;
            cin.ignore();
            for (int h = 0; h < u; h++){
                string sentence, complete = "";
                getline(cin, sentence);
                for (int i = 0; i < sentence.length(); i++){
                    if (sentence[i] == ' '){
                        complete.pop_back();
                        complete += " ";
                    }
                    else {
                        complete += code[tolower(sentence[i])] + "-"; 
                    }
                }
                complete.pop_back();
                cout << complete << "\n";
            }
        }
        return 0;
}