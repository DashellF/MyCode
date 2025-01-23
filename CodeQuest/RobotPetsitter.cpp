#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            int horiz = 0, vert = 0;
            string directions;
            cin >> directions;
            for (int k = 0; k < directions.length(); k++){
                if (directions[k] == 'L'){
                    horiz--;
                }
                else if (directions[k] =='R'){
                    horiz++; 
                }
                else if (directions[k] == 'D'){
                    vert--;
                }
                else if (directions[k] == 'U'){
                    vert++;
                }
            }
            if (vert == 0 && horiz == 0){
                cout << "TRUE" << "\n";
            }
            else {
                cout << "FALSE" << "\n";
            }
        }

        return 0;
}
