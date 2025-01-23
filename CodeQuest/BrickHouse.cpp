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
            int small, big, goal;
            cin >> small >> big >> goal;
            int reached = 0;
            while (true){
                if (goal-reached >= 5 && big > 0){
                    big--;
                    reached += 5;
                }
                else if (goal-reached >= 1 && small > 0){
                    small--;
                    reached++;
                }
                else {
                    break;
                }
            }
            if (goal == reached){
                cout << "true" << "\n";
            }
            else {
                cout << "false" << "\n";
            }
        }
        return 0;
}