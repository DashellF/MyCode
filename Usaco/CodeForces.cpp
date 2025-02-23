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
                int useless;
                cin >> useless;
                cin.ignore();

                string line;
                getline(cin,line);
                stringstream s(line);
                vector<int> b;
                string num;
                while(s >> num){
                        b.push_back(stoi(num));
                }
                
                vector<int> a(b.size()+2,0);
                int k = 1;
                for(int i = 0; i < b.size(); i++){
                        if (b[i] == 1){
                                a[i] = k;
                                a[i+1] = k;
                                a[i+2] = k;
                        }
                        if (b[i] == 0){
                                k++;
                        }
                }
                //check
                bool False = false;
                for (int i = 0; i < b.size(); i++){
                        if (b[i] == 1){
                                if (a[i] != a[i+1]  ||  a[i] != a[i+2]){
                                        cout << "NO" << "\n";
                                        False = true;
                                        break;
                                }
                        }
                }
                if (!False){
                        cout<< "YES" << "\n";
                }
        }
        return 0;
}