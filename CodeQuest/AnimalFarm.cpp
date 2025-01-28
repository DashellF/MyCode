#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;
    cin.ignore();

    for (int q = 0; q < testCases; q++){
        int turkey, goats, horses;
        cin >> turkey >> goats >> horses;
        cout << (turkey*2 + goats*4 + horses*4) << "\n";
    }
}
