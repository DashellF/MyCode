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
            unsigned long long total = 0;
            int a;
            cin >> a;
            cin.ignore();
            for (int i = 0; i < a; i++){
                unsigned long long f;
                cin >> f;
                total += f;
            }
            cout << total << "\n";
        }
        return 0;
}