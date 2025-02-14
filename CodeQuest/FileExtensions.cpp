#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();
        map<string,int> thing;
        set<pair<string, int>> things;

        for (int q = 0; q < n; q++) {
            string link;
            cin >> link;
            string temp;
            for (int i = link.length() - 1; i >= 0; i--) {
                if (link[i] == '.') {
                    break;
                }
                temp = link[i] + temp;
            }

            // Check if the domain extension already exists in the set
            bool found = false;
            for (auto it = things.begin(); it != things.end(); ++it) {
                if (it->first == temp) {
                    // If found, remove the old pair and insert a new one with an updated count
                    int count = it->second;
                    things.erase(it);
                    things.insert({temp, count + 1});
                    found = true;
                    break;
                }
            }

            // If the domain extension was not found, insert a new pair with count = 1
            if (!found) {
                things.insert({temp, 1});
            }
        

                
        }
        for (auto &p : things) {
            cout << p.first << " " << p.second << "\n";
        }
        return 0;
}