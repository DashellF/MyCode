#include <bits/stdc++.h>
using namespace std;



int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int dim, N;
        cin >> dim >> N;
        cin.ignore();
        bool cube[dim][dim][dim] = {}; 
        for (int i = 0; i < N; i++){
            int x, y, z, counter = 0;
            cin >> x >> y >> z;
            cin.ignore();
            cube[x][y][z] = true;
            int changeIndex = 0;
            for (int y = 0; y < dim; y++) {
                for (int z = 0; z < dim; z++) {
                bool completeLine = true;
                    for (int x = 0; x < dim; x++) {
                        if (!cube[x][y][z]) {
                            completeLine = false;
                            break;
                        }
                    }
                    if (completeLine) counter++;
                }
            }
            for (int x = 0; x < dim; x++) {
                for (int z = 0; z < dim; z++) {
                    bool completeLine = true;
                    for (int y = 0; y < dim; y++) {
                        if (!cube[x][y][z]) {
                            completeLine = false;
                            break;
                        }
                    }
                    if (completeLine) counter++;
                }
            }
            for (int x = 0; x < dim; x++) {
                for (int y = 0; y < dim; y++) {
                    bool completeLine = true;
                    for (int z = 0; z < dim; z++) {
                        if (!cube[x][y][z]) {
                            completeLine = false;
                            break;
                        }
                    }
                    if (completeLine) counter++;
                }
            }
            cout << counter << "\n";
        }

        return 0;
}