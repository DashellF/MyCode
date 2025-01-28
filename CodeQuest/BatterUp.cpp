#include <bits/stdc++.h>
using namespace std;


int main() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);

        int n;
        cin >> n;

        for (int u = 0; u < n; u++) {
            int bats = 0, singles = 0, doubles = 0, triples = 0, hr = 0;
            string input, name;
            getline(cin, input);
            name = input.substr(0,input.find(":"));
            while (input.find("1B") != string::npos){
                singles++;
                bats++;
                input = input.substr(0, input.find("1B")) + input.substr(input.find("1B")+2);
            }
            while (input.find("2B") != string::npos){
                doubles++;
                bats++;
                input = input.substr(0, input.find("2B")) + input.substr(input.find("2B")+2);
            }
            while (input.find("3B") != string::npos){
                triples++;
                bats++;
                input = input.substr(0, input.find("3B")) + input.substr(input.find("3B")+2);
            }
            while (input.find("HR") != string::npos){
                hr++;
                bats++;
                input = input.substr(0, input.find("HR")) + input.substr(input.find("HR")+2);
            }
            while (input.find("K") != string::npos){
                bats++;
                input = input.substr(0, input.find("K")) + input.substr(input.find("K")+1);
            }
            double output = (singles + 2*doubles + 3*triples + 4*hr);
            cout << fixed << setprecision(3) << name << "=" << (output/bats) << "\n";
        }
        return 0;
}