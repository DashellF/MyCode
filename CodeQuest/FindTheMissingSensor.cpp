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
            getOutput;
        }

        return 0;
}

void getOutput(){
            int useless;
            cin >> useless;
            cin.ignore();

            string line;
            getline(cin, line);

            stringstream thing(line);
            vector<int> arr;
            int num;
            while (thing >> num){
                arr.push_back(num);
            }

            sort(arr.begin(), arr.end());
            
            for (int i = 0; i < arr.size(); i++){
                if (arr[i] != (i + 1)){
                    cout << i+1 << "\n";
                    break;
                }
            }
}