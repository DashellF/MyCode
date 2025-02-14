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
            int x, y;
            cin >> x >> y;
            int arr[20][20] = {0};
            for (int i = 0; i < 20; i++){
                for (int k = 0; k < 20; k++){
                    arr[i][k] = 10;
                }
            }

            for (int i = x-2; i < x+3; i++){
                if (i >= 0 && i < 20 && y - 2 >= 0 && y - 2 < 20){
                    arr[i][y-2] = 25;
                }
            }
            for (int i = x-2; i < x+3; i++){
                if (i >= 0 && i < 20 && y + 2 >= 0 && y + 2 < 20){
                    arr[i][y+2] = 25;
                }
            }
            for (int i = y-1; i < y+2; i++){
                if (i >= 0 && i < 20 && x - 2 >= 0 && x - 2 < 20){
                    arr[x-2][i] = 25;
                }
            }
            for (int i = y-1; i < y+2; i++){
                if (i >= 0 && i < 20 && x + 2 >= 0 && x + 2 < 20){
                    arr[x+2][i] = 25;
                }
            }


            for (int i = x-1; i < x+2; i++){
                if (i >= 0 && i < 20 && y - 1 >= 0 && y - 1 < 20){
                    arr[i][y-1] = 50;
                }
            }
            for (int i = x-1; i < x+2; i++){
                if (i >= 0 && i < 20 && y + 1 >= 0 && y + 1 < 20){
                    arr[i][y+1] = 50;
                }
            }

            if (x-1 >= 0 && x-1 < 20 && y >= 0 && y < 20){
                    arr[x-1][y] = 50;
            }
            if (x+1 >= 0 && x+1 < 20 && y >= 0 && y < 20){
                    arr[x+1][y] = 50;
            }
            arr[x][y] = 100;


            for (int i = 0; i < 20; i++){
                for (int k = 0; k < 20; k++){
                    cout << arr[i][k];
                    if (k != 19){
                        cout << " ";
                    }
                    else {
                        cout << "\n";
                    }
                }
            }
            
        }

        return 0;
}