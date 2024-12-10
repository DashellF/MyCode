#include <string>
#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int testCases;
        cin >> testCases;
        cin.ignore();

        for (int i = 0; i < testCases; i++){
                double x, y, z;
                cin >> x >> y >> z;
                cin.ignore();
                x += 180;
                y += 180;
                z += 180;
                if (x > 360){
                        x -= 360;
                }
                if (y > 360){
                        y -= 360;
                }
                if (z > 360){
                        z -= 360;
                }
                cout << x << " " << y << " " << z << "\n";
        }
        return 0;
}

