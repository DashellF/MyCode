#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();

    for (int i = 0; i < testCases; i++) {
        int d, w;
        string dd, ww;
        string input;
        string word;
        getline(cin, input);
        dd = input.substr(0,input.find(" "));
        ww = input.substr(input.find(" ")+1);
        d = stoi(dd);
        w = stoi(ww);
        string dictionary[d];
        for (int k = 0; k < d; k++){ //get amd fill dictionary
            getline(cin, word);
            dictionary[k] = word;
        }
        for (int j = 0; j < w; j++){ // get mispelled words
            getline(cin, word);
            int counter = 0;
            int minCounter = 10000;
            int minDictIndex = -1;
            for (int u = 0; u < d; u++){ //go through dictionary of words
                if (word.length() == dictionary[u].length()){
                    for(int l = 0; l < word.length(); l++){ //go through each letter of word
                        if (word.at(l) != dictionary[u].at(l)){
                            counter++;
                        }
                    }
                    if (counter < minCounter){
                        minCounter = counter;
                        minDictIndex = u;
                    }
                }
                counter = 0;
            }
            cout << dictionary[minDictIndex] << "\n";
        }
    }
}
