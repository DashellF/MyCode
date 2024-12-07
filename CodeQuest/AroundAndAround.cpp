#include <bits/stdc++.h>
using namespace std;


int main() {
        // ios_base::sync_with_stdio(false); 
        // cin.tie(NULL);

        int n;
        cin >> n;

        for (int u = 0; u < n; u++) {
            double dRadius;
            cin >> dRadius;
            cout << fixed << setprecision(1) << (40075 + dRadius * 2 * M_PI)<< "\n";
        }
        return 0;
}