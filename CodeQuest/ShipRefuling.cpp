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
            double speed, x, y, k;
            cin >> speed >> x >> y >> k;
            vector<string, int, int, double, double, double> allied;
            vector<string, int, int, double, double, double> neutral;
            for (int i = 0; i < k; i++){
                string name, condition;
                int xx, yy;
                double f, fph, score;
                cin >> name >> condition >> xx >> yy >> f >> fph;
                if (condition == "Allied"){
                    allied.push_back(name, xx, yy, f, fph, 0);
                    score = sqrt(pow(x-xx,2) + pow(y-yy,2))

                }
                else if (condition == "Neutral"){
                    neutral.push_back(name, xx, yy, f, fph, 0);
                }
            }
            double score;
            for (int h = 0; h < allied.size(); h++){
                score = allied[i]
            }
        }

        return 0;
}