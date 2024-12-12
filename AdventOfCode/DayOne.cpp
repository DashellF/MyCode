#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[1000];
    int arrT[1000];
    ifstream input("AdventOfCode/DayOne.txt");
    string inputS;
    while (getline(input, inputS)){
        int one, two, i = 0;
        istringstream line(inputS);
        if (line >> one >> two){
            arr[i] = one;
            arrT[i] = two;
            cout << arr[i] << "\n";
            cout << arrT[i] << "\n";
            i++;
        }
    }
    int sub;
    for (int i = 0; i < 1000 - 1; i++){
        for (int k = 0; k < 1000 - 1; k++){
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
    cout << "sorted!" << "\n";
    int output = 0;
    for (int i = 0; i < 1000; i++){
        output += abs(arr[i] - arrT[i]);
    }
    cout << output << "\n";
}