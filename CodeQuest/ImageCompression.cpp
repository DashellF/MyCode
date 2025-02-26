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
            vector<double> nums;
            int s;
            cin >> s;
            cin.ignore();
            for (int i = 0; i < s; i++){
                double temp;
                cin >> temp;
                cin.ignore();
                nums.push_back(temp);
            }
            vector<double> willSort = nums;
            sort(willSort.begin(), willSort.end());
            for (int i = 0; i < nums.size(); i++){
                double output = ((nums[i] - willSort.front()) / (willSort.back() - willSort.front()))*255;
                cout << fixed << setprecision(0) << output << "\n";
            }
        }

        return 0;
}