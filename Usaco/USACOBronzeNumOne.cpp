#include <bits/stdc++.h>
using namespace std;


int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            int num, counter = 0, Bessie, Elsie;
            cin >> num;
            cin.ignore();
            for (int j = 0; j < num; j++){
                int temp = j;
                int digits = (j > 0) ? int(log10(j)) + 1 : 1;
                int msd = j / pow(10, digits - 1); // Extract most significant digit
                Bessie = round(msd) * pow(10, digits - 1);
                Elsie = j;
                for (int k = 1; k < digits; k++){
                    if ((Elsie % int(pow(10, k))) > 5){
                        temp += pow(10, k);
                    }
                }
                
                if (Elsie != Bessie){
                    counter++;
                }
            }
            cout << counter << "\n";
        }
        return 0;
}

