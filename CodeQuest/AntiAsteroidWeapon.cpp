#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int u = 0; u < n; u++) {
            int num;
            cin >> num;
            cin.ignore();
            int arr[num][2];
            for (int i = 0; i < num; i++){
                int x, y;
                cin >> x >> y;
                cin.ignore();
                arr[i][0] = x;
                arr[i][1] = y;
            }
            //sort array
            int tempX, tempY;
            for (int t = 0; t < num-1; t++){
                for (int j = 0; j < num-1; j++){         
                    if (sqrt(pow(arr[j][0], 2) + pow(arr[j][1], 2)) > sqrt(pow(arr[j+1][0], 2) + pow(arr[j+1][1], 2))){
                        tempX = arr[j][0];
                        tempY = arr[j][1];
                        arr[j][0] = arr[j+1][0];
                        arr[j][1] = arr[j+1][1];
                        arr[j+1][0] = tempX;
                        arr[j+1][1] = tempY;
                    }
                }
            }
            // output array:
            for (int i = 0; i < num; i++) {
                cout << arr[i][0] << " " << arr[i][1] << "\n";
            }
        }
        return 0;
}