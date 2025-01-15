#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    // Process each test case
    for (int i = 0; i < n; i++) {
        int num, counter = 0;
        cin >> num;
        cin.ignore();

        // Loop through all numbers from 0 to num-1
        for (int j = 0; j < num; j++) {
            int temp = j;
            int digits = (j > 0) ? int(log10(j)) + 1 : 1;

            // Regular Rounding (Bessie)
            int Bessie = j;
            int roundTo = 1;
            while (Bessie % 10 >= 5) {
                Bessie += roundTo;
                roundTo *= 10;
                Bessie /= 10;
            }

            // Chain Rounding (Elsie)
            int Elsie = j;
            int powerOf10 = 1;
            // Loop through each digit, applying chain rounding progressively
            for (int k = 1; k <= digits; k++) {
                if ((Elsie % int(pow(10, k))) >= 5) {
                    Elsie += pow(10, k);  // Apply the rounding for this digit
                }
            }

            // Count the number of differences
            if (Elsie != Bessie) {
                counter++;
            }
        }

        // Output the count of differences for this test case
        cout << counter << "\n";
    }

    return 0;
}