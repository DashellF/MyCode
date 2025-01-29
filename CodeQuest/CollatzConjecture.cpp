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
            int start, num, length = 1;
            cin >> start;
            num = start;

            while(num != 1){
                if (num % 2 == 0){
                    num /= 2;
                }
                else {
                    num = (num*3) + 1;
                }
                length++;
            }
            cout << start << ":" << length << "\n";
        }

        return 0;
}