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
            string link;
            cin >> link;
            string temp;
            map<string,int> thing;
            for (int i = link.length()-1; i > 0; i--;){
                if (link[i] == '.'){
                    thing[temp]++;
                    break;
                }
                else {
                    temp = link[i] + temp;
                }
            }
        }
        
        return 0;
}