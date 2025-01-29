#include <bits/stdc++.h>
using namespace std;


int main() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int u = 0; u < n; u++) {
            int bats = 0, singles = 0, doubles = 0, triples = 0, hr = 0;
            string input, name;
            getline(cin, input);
            name = input.substr(0,input.find(":"));
            input = input.substr(input.find(":") + 1);


            stringstream ss(input);
            string token;

            while (getline(ss, token, ',')) {
                if (token == "1B") {
                    singles++;
                    bats++;
                } else if (token == "2B") {
                    doubles++;
                    bats++;
                } else if (token == "3B") {
                    triples++;
                    bats++;
                } else if (token == "HR") {
                    hr++;
                    bats++;
                } else if (token == "K") {
                    bats++;
                }
            }
            double output = (singles + 2 * doubles + 3 * triples + 4 * hr);
            double result = output / bats;
            cout << fixed << setprecision(3) << name << "=" << result << "\n";

        }
        return 0;
}