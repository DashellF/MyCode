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
            int l, cc, nd;
            int c = 0, d = 0;
            int temp = 0;
            int nested = 0;
            cin >> l >> cc >> nd;
            cin.ignore();
            for (int i = 0; i < l; i++){
                string line;
                getline(cin, line);
                if (line.substr(0,3) == "If "){
                    if (nested == 1){
                        c--;
                    }
                    nested = 1;
                    c+=2;
                }
                if (line.substr(0,4) == "Else"){
                    nested = 0;
                }
                if (line == "{"){
                    temp++;
                }
                if (line == "}"){
                    if (temp > d){
                        d = temp;
                    }
                    temp = 0;
                }
            }
            bool thing = (c <= cc && d <= nd);
            string output;
            if (thing){
                output = "PASS";
            }
            else {
                output = "FAIL";
            }
            cout << c << " " << d << " " << output << "\n";
        }

        return 0;
}