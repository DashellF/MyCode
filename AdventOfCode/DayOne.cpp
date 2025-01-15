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

    sort(arr.begin(), arr.end());
    sort(arrT.begin(), arrT.end());

    cout << "sorted!" << "\n";
    int output = 0;
    for (int i = 0; i < arr.size(); i++){
        output += abs(arr[i] - arrT[i]);
    }
    cout << output << "\n";
}