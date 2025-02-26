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
            int a;
            cin >> a;
            for (int i = 0; i < a; i++){
                for (int k = 0; k < a; k++){
                    cout << "#";
                    if (k == a-1){
                        cout << "\n";
                    }
                    else {
                        cout << " ";
                    }
                }
            }
        }

        return 0;
}