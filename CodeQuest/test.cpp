#include <bits/stdc++.h>
using namespace std;

void getOutput();
pair<double, int> numBefore(string eq);
pair<double, int> numAfter(string eq);
string solve(string eq);

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int q = 0; q < n; q++) {
            string line;
            getline(cin, line);
            string left = solve(line.substr(0,line.find("=")));
            string right = line.substr(line.find("=")+1);
            if (left == right){
                cout << "VALID" << "\n";
            }
            else {
                cout << left << "\n";
            }
        }
        return 0;
}

string solve(string eq){
    if (eq.find("(") != string::npos){
        int parenIndex;
        for (int i = 0; i < eq.length(); i++){
            if (eq[i] == ')'){
                parenIndex = i;
            }
        }
        return solve(eq.substr(0,eq.find("(")) + solve(eq.substr(eq.find("("), parenIndex - eq.find("(") - 1)) + eq.substr(parenIndex + 1));
    }
    else if (eq.find("SQRT") != string::npos){
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("SQRT") + 4));
        return solve(eq.substr(0,eq.find("SQRT")) + to_string(sqrt(AnumAfter.first)) + eq.substr(eq.find("SQRT") + 4 + AnumAfter.second + 1));
    }
    else if (eq.find("^") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("^")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("^") + 1));
        return solve(eq.substr(0,eq.find("^") - AnumBefore.second - 1) + to_string(pow(AnumBefore.first, AnumAfter.first)) + eq.substr(eq.find("^") + 1 + AnumAfter.second + 1));
    }
    else if (eq.find("/") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("/")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("/") + 1));
        return solve(eq.substr(0,eq.find("/") - AnumBefore.second - 1) + to_string(AnumBefore.first / AnumAfter.first) + eq.substr(eq.find("/") + 1 + AnumAfter.second + 1));
    }
    else if (eq.find("*") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("*")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("*") + 1));
        return solve(eq.substr(0,eq.find("*") - AnumBefore.second - 1) + to_string(AnumBefore.first * AnumAfter.first) + eq.substr(eq.find("*") + 1 + AnumAfter.second + 1));
    }
    else if (eq.find("+") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("+")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("+") + 1));
        return solve(eq.substr(0,eq.find("+") - AnumBefore.second - 1) + to_string(AnumBefore.first + AnumAfter.first) + eq.substr(eq.find("+") + 1 + AnumAfter.second + 1));
    }
    else if (eq.find("-") != string::npos && eq.find("-") != 0){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("-")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("-") + 1));
        return solve(eq.substr(0,eq.find("-") - AnumBefore.second - 1) + to_string(AnumBefore.first - AnumAfter.first) + eq.substr(eq.find("-") + 1 + AnumAfter.second + 1));
    }
    else {
        return eq;
    }
}

pair<double, int> NumBefore(string eq){
    string output;
    int length = 0;
    for (int i = eq.length()-1; i >= 0; i--){
        if (isdigit(eq[i]) || eq[i] == '.'){
            output = eq[i] + output;
            length++;
        }
        else if (eq[i] == '-'){
            output = eq[i] + output;
            length++;
            break;
        }
        else {
            break;
        }
    }
    return {stod(output), length};
}

pair<double, int> NumAfter(string eq){
    string output;
    int length = 0;
    for (int i = 0; i < eq.length(); i++){
        if (isdigit(eq[i]) || eq[i] == '.'){
            output = eq[i];
            length++;
        }
        else if (i == 0 && eq[i] == '-'){
            output = eq[i];
            length++;
        }
        else {
            break;
        }
    }
    return {stod(output), length};
}


