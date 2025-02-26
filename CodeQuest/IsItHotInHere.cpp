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
            int s;
            cin >> s;
            cin.ignore();
            for (int i = 0; i < s; i++){
                string line;
                getline(cin,line);
                bool f;
                if (line.back() == 'F'){
                    f = true;
                }
                else {
                    f = false;
                }
                double temp;
                string g;
                string num = "";
                for (int a = 0; a < line.length(); a++){
                    if (isdigit(line[a]) || line[a] == '.' || line[a] == '-'){
                        num += line[a];
                    }
                }
                double numb = stod(num);
                if (f){
                    temp = 5.0 / 9.0 * (numb - 32);
                    g = " C";
                }
                else {
                    temp = (numb * 9.0/5.0) + 32;
                    g = " F";
                }
                cout << line << " = " << fixed << setprecision(1) << temp << g << "\n";
            }
        }

        return 0;
}