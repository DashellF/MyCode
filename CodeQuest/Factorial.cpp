#include <bits/stdc++.h>
using namespace std;


int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int q = 0; q < n; q++) {
            double f, total = 1;
            cin >> f;
            for (int i = 2; i < f+1; i++){
                total *= i;
            }
            cout << fixed << setprecision(0) << total << "\n";
        }

        return 0;
}