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
            string str;
            cin >> str;
            int index = 0;
            int temp = 0;
            for (int i = 0; i < 9; i++){
                int digit;
                if (isdigit(str.at(i))){
                    digit = (str.at(i) - '0');
                }
                
                else {
                    digit = 10;
                }
                temp += digit * (10-index);
                index++;
            }
            int check;
            if (isdigit(str.at(9))){
                check = (str.at(9) - '0');
            }
            else {
                check = 10;
            }
            if ((11 - (temp % 11)) % 11 == check){
                cout << "VALID" << "\n";
            }
            else {
                cout << "INVALID" << "\n";
            }
        }

        return 0;
}