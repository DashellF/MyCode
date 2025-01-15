
#include <bits/stdc++.h>
using namespace std;



int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int N, F;
        cin >> N >> F;
        cin.ignore();


        string contest;
        int bigCounter = 0;
        cin >> contest;
        cin.ignore();
        vector<string> arr;
        for (int k = 0; k < contest.length()-2; k++){
            if (contest[k+1] == contest[k+2] && find(arr.begin(), arr.end(), contest.substr(k,3)) == arr.end()){
                string temp = contest;
                string moo = contest.substr(k,3);
                int counter = 0;
                while (temp.find(moo) < temp.length()){
                    counter++;
                    temp = temp.substr(0, temp.find(moo)) + temp.substr(temp.find(moo)+3);
                }
                if (counter >= F){
                    bigCounter++;
                    arr.push_back(contest.substr(k,3));
                }
            }
        }
        int counter = 0;
        cout << bigCounter << "\n";
        for (int k = 0; k < arr.size(); k++){
            cout << arr[k] << "\n";
        }
        

        return 0;
}
