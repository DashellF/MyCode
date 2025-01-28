#include <bits/stdc++.h>
using namespace std;

void func();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int q = 0; q < n; q++) {
            func();
        } 
        return 0;
}
void func(){
    int speed, adder = 0;
    string birth;
    cin >> speed >> birth;
    if (birth == "true"){
        adder = 5;
    }

    if (speed <= 60 + adder){
        cout << "no ticket" << "\n";
    }
    else if (speed <= 80 + adder){
        cout << "small ticket" << "\n";
    }
    else {
        cout << "big ticket" << "\n";
    }
    return;
}