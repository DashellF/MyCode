#include <bits/stdc++.h>
using namespace std;

string isrecur(int goal, int num, int pastnum){
    int temp = num + pastnum;
    if (temp == goal){
        return "TRUE";
    }
    if (temp > goal){
        return "FALSE";
    }
    return isrecur(goal, temp, num);
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;

        for (int q = 0; q < n; q++) {
            double doub;
            cin >> doub;
            int num = round(doub);
            string ans;
            ans = isrecur(num, 1, 0);
            cout << ans << "\n";
        }
        return 0;
}
