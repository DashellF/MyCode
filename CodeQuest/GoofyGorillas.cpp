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
            string one, two;
            cin >> one >> two;
            if (one == two){
                cout << "true\n";
            }
            else {
                cout << "false\n";
            }
        }

        return 0;
}