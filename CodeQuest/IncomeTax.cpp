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
            int income;
            cin >> income;
            double tax;
            if (income <= 11000){
                tax = income * 0.10;
            }
            else if (income <= 44725){
                tax = income * 0.12;
            }
            else if (income <= 95375){
                tax = income * 0.22;
            }
            else if (income <= 182100){
                tax = income * 0.24;
            }
            else if (income <= 231250){
                tax = income * 0.32;
            }
            else if (income <= 578125){
                tax = income * 0.35;
            }
            else {
                tax = income * 0.37;
            }
            cout << round(tax) << "\n";
        }

        return 0;
}