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
            int us, them;
            cin >> us >> them;
            int diff = us - them;
            if (diff == -15 || diff == -13 || diff == -11 || diff == -10 || diff == -8 || diff == -5 || diff == -4 || 
            diff == -2 || diff == 1 || diff == 5 || diff == 12){ 
            cout << "2" << "\n";
            }
            else {
                cout << "1" << "\n";
            }
        }

        return 0;
}