#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    string dummy;
    getline(cin, dummy);

    for (int i = 0; i < testCases; i++){
        string sentence;
        getline(cin, sentence);
        int counter = 0;
        for (int k = 0; k < sentence.length(); k++){
            if (tolower(sentence.at(k)) == 'a' || tolower(sentence.at(k)) == 'e' || tolower(sentence.at(k)) == 'i' || tolower(sentence.at(k)) == 'o' || tolower(sentence.at(k)) == 'u'){
                counter++;
            }
        }
        cout << counter << '\n';
    }
    return 0;
}
