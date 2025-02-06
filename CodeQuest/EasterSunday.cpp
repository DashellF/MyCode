#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int z = 0; z < n; z++) {
            int year, a, b, c, k, p, q, m, n, d, e, f;
            cin >> year;
            a = year%19;
            b = year%4;
            c = year%7;
            k = year/100;
            p = (13 + 8*k)/25;
            q = k/4;
            m = (15 - p + k - q) % 30;
            n = (4 + k - q) % 7;
            d = (19 * a + m) % 30;
            e = (2*b + 4*c + 6*d + n)%7;
            f = (11*m + 11)%30;

            int day = 22 + d + e;
            string month = "03";
            if (day > 31){
                day -= 31;
                month = "04";
            }


            if (d == 28 && e == 6 && f < 19){
                day -= 7;
            }
            if (d == 29 && e == 6){
                day -= 7;
            }

            string dayS = to_string(day);
            if (dayS.length() == 1){
                dayS = "0" + dayS;
            }

            cout << year << "/" << month << "/" << dayS << "\n";

        }

        return 0;
}