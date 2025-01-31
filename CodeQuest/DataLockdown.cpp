#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int q = 0; q < n; q++) {
            int y;
            cin >> y;
            cin.ignore();
            for (int k = 0; k < y; k++){
                string url;
                int num;
                cin >> url >> num;
                if (url.length() < 8 || url.substr(url.length()-9) != ".lmco.com" && num > 999){
                    cout << url << " " << num << "\n";
                }
            }
        }
}