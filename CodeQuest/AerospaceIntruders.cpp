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
            int w;
            cin >> w;
            cin.ignore();
            map<string, pair<double,double>> shipsA;
            map<string, pair<double,double>> shipsB;
            map<string, pair<double,double>> shipsC;
            for (int s = 0; s < w; s++){
                string line;
                cin >> line;
                string name = line.substr(0,line.find(":")-2);
                string classs = line.substr(line.find(":")-1,1);
                double x = stod(line.substr(line.find(":")+1, line.find(",")-line.find(":")-1));
                double y = stod(line.substr(line.find(",")+1));
                if (classs == "A"){
                    shipsA[name] = {x, y};
                }
                else if (classs == "B"){
                    shipsB[name] = {x,y};
                }
                else if (classs == "C"){
                    shipsC[name] = {x,y};
                }
                cout << "ship added: " << name << " " << classs << " " << x << "," << y << "\n"; 
            }
            for (int s = 0; s < w; s++){
                // find min x
                double min = 100000000;
                string nameMin;
                string classMin;
                for (const auto& pair : shipsA){
                    if (pair.second.first < min){
                        min = pair.second.first;
                        nameMin = pair.first;
                        classMin = "A";
                    }
                    if (pair.second.first == min){
                        if (pair.second.second > shipsA[nameMin].second){
                            min = pair.second.first;
                            nameMin = pair.first;
                            classMin = "A";
                        }
                    }
                }

                for (const auto& pair : shipsB){
                    if (pair.second.first < min){
                        min = pair.second.first;
                        nameMin = pair.first;
                        classMin = "B";
                    }
                    if (pair.second.first == min){
                        if (pair.second.second > shipsB[nameMin].second){
                            min = pair.second.first;
                            nameMin = pair.first;
                            classMin = "B";
                        }
                    }
                }
                
                for (const auto& pair : shipsC){
                    if (pair.second.first < min){
                        min = pair.second.first;
                        nameMin = pair.first;
                        classMin = "C";
                    }
                    if (pair.second.first == min){
                        if (pair.second.second > shipsC[nameMin].second){
                            min = pair.second.first;
                            nameMin = pair.first;
                            classMin = "C";
                        }
                    }
                }
                cout << "Destroyed Ship: " << nameMin << " xLoc: " << min << "\n";
                if (classMin == "A"){
                    shipsA[nameMin].first += 1000;
                    cout << "ship deleted: " << nameMin << " with x of " << shipsA[nameMin].first << "\n";

                }
                else if (classMin == "B"){
                    shipsB[nameMin].first += 1000;
                    cout << "ship deleted: " << nameMin << " with x of " << shipsB[nameMin].first << "\n";
                }
                else if (classMin == "C"){
                    shipsC[nameMin].first += 1000;
                    cout << "ship deleted: " << nameMin << " with x of " << shipsC[nameMin].first << "\n";

                }
                for (auto& pair : shipsA) {
                    pair.second.first -= 10;
                }
                for (auto& pair : shipsB) {
                    pair.second.first -= 20;
                }
                for (auto& pair : shipsC) {
                    pair.second.first -= 30;
                }

            }
        }

        return 0;
}