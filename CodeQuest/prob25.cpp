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
            if (stod(left) == stod(right)){
                cout << "Correct" << "\n";
            }
            else {
                string out = left;
                for (int i = out.length()-1; i > -1; i--){
                    if (out[i] == '0' || out[i] == '.'){
                        out = out.substr(0,i);
                    }
                    else {
                        break;
                    }
                }
                if (out.length() < left.length() - 3){
                    cout << out << "\n";
                }
                else {
                    cout << fixed << setprecision(3) << stod(left) << "\n";
                }
            }
        }
        return 0;
}

string solve(string eq){
    // cout << eq << "\n";
    if (eq.find("(") != string::npos){
        int parenIndex;
        int depth = 1;
        for (int i = eq.find("(")+1; i < eq.length(); i++){
            if (eq[i] == '('){
                depth++;
            }
            else if (eq[i] == ')'){
                depth--;
            }
            if (depth == 0){
                parenIndex = i;
                break;
            }
        }
        return solve(eq.substr(0,eq.find("(")) + solve(eq.substr(eq.find("(")+1, parenIndex - eq.find("(") - 1)) + eq.substr(parenIndex + 1));
    }
    else if (eq.find("SQRT") != string::npos){
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("SQRT") + 4));
        if (eq.find("-SQRT") == 0){
            return solve(eq.substr(0,eq.find("-SQRT")) + to_string((-1 * sqrt(AnumAfter.first))) + eq.substr(eq.find("SQRT") + 4 + AnumAfter.second));
        }
        else {
            return solve(eq.substr(0,eq.find("SQRT")) + to_string((sqrt(AnumAfter.first))) + eq.substr(eq.find("SQRT") + 4 + AnumAfter.second));
        }
    }
    else if (eq.find("^") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("^")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("^") + 1));
        return solve(eq.substr(0,eq.find("^") - AnumBefore.second) + to_string((pow(AnumBefore.first, AnumAfter.first))) + eq.substr(eq.find("^") + 1 + AnumAfter.second));
    }
    else if (eq.find("/") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("/")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("/") + 1));
        return solve(eq.substr(0,eq.find("/") - AnumBefore.second) + to_string((AnumBefore.first / AnumAfter.first)) + eq.substr(eq.find("/") + 1 + AnumAfter.second));
    }
    else if (eq.find("*") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("*")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("*") + 1));
        return solve(eq.substr(0,eq.find("*") - AnumBefore.second) + to_string((AnumBefore.first * AnumAfter.first)) + eq.substr(eq.find("*") + 1 + AnumAfter.second));
    }
    else if (eq.find("+") != string::npos){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("+")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("+") + 1));
        return solve(eq.substr(0,eq.find("+") - AnumBefore.second) + to_string((AnumBefore.first + AnumAfter.first)) + eq.substr(eq.find("+") + 1 + AnumAfter.second));
    }
    else if (eq.find("-") != string::npos && eq.find("-") != 0){
        pair<double, int> AnumBefore = numBefore(eq.substr(0,eq.find("-")));
        pair<double, int> AnumAfter = numAfter(eq.substr(eq.find("-") + 1));
        return solve(eq.substr(0,eq.find("-") - AnumBefore.second) + to_string((AnumBefore.first - AnumAfter.first)) + eq.substr(eq.find("-") + 1 + AnumAfter.second));
    }
    else {
        return eq;
    }
}

pair<double, int> numBefore(string eq){
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

pair<double, int> numAfter(string eq){
    string output;
    int length = 0;
    for (int i = 0; i < eq.length(); i++){
        if (isdigit(eq[i]) || eq[i] == '.'){
            output += eq[i];
            length++;
        }
        else if (i == 0 && eq[i] == '-'){
            output += eq[i];
            length++;
        }
        else {
            break;
        }
    }
    return {stod(output), length};
}


