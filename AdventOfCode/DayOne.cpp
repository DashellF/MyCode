#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    vector<int> arrT;
    ifstream input("./DayOne.txt");
    if (!input) cerr << "error file\n";
    string inputS;
    while (getline(input, inputS)){
        int one, two;
        istringstream line(inputS);
        if (line >> one >> two){
            arr.push_back(one);
            arrT.push_back(two);
            //cout << arr << "\n";
            //cout << arrT << "\n";
        }
    }
    /*
    cout << arr[0];
    int sub;
    for (int i = 0; i < arr.size(); i++){
        for (int k = 0; k < arr.size(); k++){
            if (arr[k] > arr[k+1]){
                sub = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = sub;
            }
            if (arrT[k] > arrT[k+1]){
                sub = arrT[k];
                arrT[k] = arr[k+1];
                arrT[k+1] = sub;
            }
        }
    }
    */

    sort(arr.begin(), arr.end());
    sort(arrT.begin(), arrT.end());

    cout << "sorted!" << "\n";
    int output = 0;
    for (int i = 0; i < arr.size(); i++){
        output += abs(arr[i] - arrT[i]);
    }
    cout << output << "\n";
}