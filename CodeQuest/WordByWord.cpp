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
            int g;
            cin >> g;
            cin.ignore();
            map<int,int> data;
            int words = 0;
            int totalLength = 0;
            int minLength = INT_MAX;
            int maxLength = -1;
            for (int w = 0; w < g; w++){
                string line;
                getline(cin, line);
                stringstream h(line);
                string word;
                while (h >> word){
                    string temp = "";
                    for (int i = 0; i < word.length(); i++){
                        if (isalpha(word[i])){
                            temp += word[i];
                        }
                    }
                    data[temp.length()] = data[temp.length()]+1;
                    totalLength += temp.length();
                    words++;
                    if (temp.length() < minLength){
                        minLength = temp.length();
                    }
                    if (temp.length() > maxLength){
                        maxLength = temp.length();
                    }
                }

            }
            double mean = double(totalLength) / double(words);
            cout << "Average: " << fixed << setprecision(1) << mean << "\n";
            string modes = "";
            int modeNum = 0;
            double median;
            int other = 0;
            bool thing = true;
            for (int i = minLength; i < maxLength+1; i++){
                other += data[i];
                if (data[i] > modeNum){
                    modeNum = data[i];
                    modes = to_string(i) + ",";
                }
                else if (data[i] == modeNum){
                    modes += (to_string(i) + ",");
                }
                if (other > words/2 && thing == true){
                    if (words % 2 == 1){
                        median = i;
                        thing = false;
                    }
                    else {
                        median = (data[i] + data[i+1])/2;
                        thing = false;
                    }
                }
            }
            cout << "Median: " << fixed << setprecision(1) << median << "\n"
                 << "Modes: " << modes.substr(0,modes.length()-1) << "\n"
                 << "Range: " << maxLength - minLength << "\n";
            for (int i = minLength; i < maxLength+1; i++){
                cout << i << "|";
                for (int s = 0; s < data[i]; s++){
                    cout << "x";
                }
                cout << "\n";
            }
        }

        return 0;
}