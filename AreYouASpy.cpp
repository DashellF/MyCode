#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();

    for (int i = 0; i < testCases; i++) {
        string input, sentenceOne, sentenceTwo;
        bool isSpy = true;
        
        getline(cin, input);
        sentenceOne = input.substr(0, input.find("|"));
        sentenceTwo = input.substr(input.find("|") + 1);

        transform(sentenceOne.begin(), sentenceOne.end(), sentenceOne.begin(), ::tolower);
        transform(sentenceTwo.begin(), sentenceTwo.end(), sentenceTwo.begin(), ::tolower);
        // cout << sentenceOne + "|" + sentenceTwo + "\n";

        for (int k = 0; k < sentenceTwo.length(); k++) {
            if (isalpha(sentenceTwo.at(k))){  
                if (sentenceOne.find(sentenceTwo.at(k)) == string::npos) {
                    // cout << "failed at character " << sentenceTwo.at(k) << "\n";
                    isSpy = false;
                    break; 
                }
            }
        }

        if (isSpy) {
            cout << "That's my secret contact!" << "\n";
        } else {
            cout << "You're not a secret agent!" << "\n";
        }
    }

    return 0;
}
