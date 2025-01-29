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
            string line;
            string v1, m1, v2, m2;
            cin >> line;
            int num = 0;
            for (int i = 0; i < line.length(); i++){
                if(num == 0 && (isdigit(line[i]) || line[i] == '.')){
                    v1 += line[i];
                }
                else if(num == 1 && (isdigit(line[i]) || line[i] == '.')){
                    m1 += line[i];
                }
                else if(num == 2 && (isdigit(line[i]) || line[i] == '.')){
                    v2 += line[i];
                }
                else if(num == 3 && (isdigit(line[i]) || line[i] == '.')){
                    m2 += line[i];
                }
                else {
                    num++;
                }
            }
            cout << fixed << setprecision(2) << ((stod(v1)*stod(m1) + stod(v2)*stod(m2))/(stod(m1) + stod(m2))) << "\n";
        }

        return 0;
}