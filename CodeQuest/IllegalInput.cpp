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
            string line;
            getline(cin, line);
            bool reject = false;
            if (line.length() == 0){
                cout << "\n";
            }
            else {
                for (int i = 0; i < line.length()-6; i++){
                    if (line.substr(i,7) == "&& sudo" || line.substr(i,7) == "&& su -" || line.substr(i,7) == "<script"){
                        reject = true;
                        break;
                    }
                }
                for (int i = 0; i < line.length()-1; i++){
                    if (line.substr(i,2) == ";;" || line.substr(i,2) == "\%s" || line.substr(i,2) == "\%x" || line.substr(i,2) == "\%n"){
                        reject = true;
                        break;
                    }
                }
                for (int i = 0; i < line.length()-1; i++){
                    if (line.at(i) == '$'){
                        if (line.at(i+1) == '{'){
                            for (int k = i+2; k < line.length(); k++){
                                if (line.at(k) == '}'){
                                    reject = true;
                                    break;
                                }
                            }
                        }
                        if (line.at(i+1) == '('){
                            for (int k = i+2; k < line.length(); k++){
                                if (line.at(k) == ')'){
                                    reject = true;
                                    break;
                                }
                            }
                        }
                    }
                }
                for (int i = 0; i < line.length()-1; i++){
                    if (line.substr(i,2) == "';"){
                        for (int k = i; k < line.length()-1; k++){
                            if (line.substr(k,2) == "--"){
                                reject = true;
                                break;
                            }
                        }
                    }
                }
                for (int i = 0; i < line.length()-7; i++){
                    if (line.substr(i,8) == "' OR 1=1"){
                        reject = true;
                        break;
                    }
                }
                if (reject){
                    cout << "REJECTED" << "\n";
                }
                else {
                    cout << line << "\n";
                }
            }
        }

        return 0;
}