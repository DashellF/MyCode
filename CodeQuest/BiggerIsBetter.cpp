#include <bits/stdc++.h>
using namespace std;


int main() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();
        for (int u = 0; u < n; u++) {
            string input;
            getline(cin, input);
            int max = 0;
            for(int i = 0; i < input.length(); i++){
                string num = "";
                if (isdigit(input[i])){
                    num += input[i];
                    i++;
                    while(isdigit(input[i])){
                        num += input[i];
                        i++;
                    }
                    if (stoi(num) > max){
                        max = stoi(num);
                    }
                }
            }
            cout << max << "\n";
        }
        return 0;
}