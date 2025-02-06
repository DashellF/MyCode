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
            double X1, Y1, X2, Y2, W, t;
            cin >> X1 >> Y1 >> X2 >> Y2 >> W >> t;
            for (int i = 0; i < t; i++){
                double x, y;
                cin >> x >> y;
                if (sqrt((pow(Y1 - y, 2) + pow(X1 - x, 2))) + sqrt((pow(Y2 - y, 2) + pow(X2 - x, 2))) < W){
                    cout << "1" << "\n";
                }
                else {
                    cout << "0" << "\n";
                }
            }
        }

        return 0;
}