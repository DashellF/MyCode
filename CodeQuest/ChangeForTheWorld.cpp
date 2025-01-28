#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    for (int q = 0; q < n; q++) {
        double money;
        string line;
        getline(cin, line);
        money = stod(line.substr(1));
        int quar = 0, dime = 0, nick = 0, pen = 0, temp;

        money = round(money * 100) / 100;  // Round to avoid precision issues

        if (money >= 0.25) {
            temp = money / 0.25;
            quar += temp;
            money -= 0.25 * temp;
            money = round(money * 100) / 100;
        }
        if (money >= 0.10) {
            temp = money / 0.10;
            dime += temp;
            money -= 0.10 * temp;
            money = round(money * 100) / 100;
        }
        if (money >= 0.05) {
            temp = money / 0.05;
            nick += temp;
            money -= 0.05 * temp;
            money = round(money * 100) / 100;
        }
        if (money >= 0.01) {
            temp = money / 0.01;
            pen += temp;
            money -= 0.01 * temp;
            money = round(money * 100) / 100;
        }

        cout << line << "\n"
             << "Quarters=" << quar << "\n"
             << "Dimes=" << dime << "\n"
             << "Nickels=" << nick << "\n"
             << "Pennies=" << pen << "\n";
    }
    return 0;
}