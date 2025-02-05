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
            string line1, line2;
            cin >> line1 >> line2;
            int start;
            vector<string> arr1;
            vector<string> arr2;
            for (int i = 0; i < line1.length(); i++){
                string temp = "";
                while (isalpha(line1[i]) && i < line1.length()){
                    temp += line1[i];
                    i++;
                }
                arr1.push_back(temp);
            }
            for (int i = 0; i < line2.length(); i++){
                string temp = "";
                while (isalpha(line2[i]) && i < line2.length()){
                    temp += line2[i];
                    i++;
                }
                arr2.push_back(temp);
            }
            vector<string> arrF;
            vector<string> arrL;
            vector<string> arrB;
            for (int i = 0; i < arr1.size(); i++){
                if (count(arr2.begin(), arr2.end(), arr1[i]) > 0){
                    arrB.push_back(arr1[i]);
                }
                else {
                    arrF.push_back(arr1[i]);
                }
            }
            for (int i = 0; i < arr2.size(); i++){
                if (count(arrB.begin(), arrB.end(), arr2[i]) == 0){
                    arrL.push_back(arr2[i]);
                }
            }
            sort(arrF.begin(), arrF.end());
            sort(arrB.begin(), arrB.end());
            sort(arrL.begin(), arrL.end());
            for (int i = 0; i < arrF.size(); i++){
                cout << arrF[i];
                if (i != arrF.size()-1){
                    cout << ",";
                }
                else {
                    cout << "\n";
                }
            }
            for (int i = 0; i < arrB.size(); i++){
                cout << arrB[i];
                if (i != arrB.size()-1){
                    cout << ",";
                }
                else {
                    cout << "\n";
                }
            }
            for (int i = 0; i < arrL.size(); i++){
                cout << arrL[i];
                if (i != arrL.size()-1){
                    cout << ",";
                }
                else {
                    cout << "\n";
                }
            }
        }

        return 0;
}