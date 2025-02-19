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
            map <string, double> times = {{"Smith",-7}, {"Sprey",-5}, {"Anderson", 0},
                                        {"Bolade",1}, {"Hassan", 2}, {"Agarwal", 5.3},
                                        {"Sato", 9}, {"Thomas",10}};
            string line;
            getline(cin, line);
            stringstream a(line);
            string org, date, time;
            a >> org >> date >> time;
            string temp;
            vector<string> people;
            while (a >> temp){
                people.push_back(temp);
            }
            bool dst = false;
            int century, year, month, day;
            year = stod(date.substr(0,4));
            month = 3;
            day = 1;


            century = year/100;
            year = year % 100;
            int startSprey, endSprey, startAnderson, endAnderson, startThomas, endThomas;
            for (int i = 0; i < 31; i++){
                if (day + int(2.6*month-0.2) - 2*century + year + year/4 + century/4 == 1){
                    startSprey = day + 7;
                    break;
                }
                day++;
            } 
            day = 31;
            for (int i = 0; i < 31; i++){
                if (day + int(2.6*month-0.2) - 2*century + year + year/4 + century/4 == 1){
                    startAnderson = day;
                    break;
                }
                day--;
            }
            month = 10;
            day = 1;
            for (int i = 0; i < 31; i++){
                if (day + int(2.6*month-0.2) - 2*century + year + year/4 + century/4 == 1){
                    startThomas = day;
                    break;
                }
                day++;
            } 
            day = 31;
            for (int i = 0; i < 31; i++){
                if (day + int(2.6*month-0.2) - 2*century + year + year/4 + century/4 == 1){
                    endAnderson = day;
                    break;
                }
                day--;
            }
            month = 11;
            day = 31;
            for (int i = 0; i < 31; i++){
                if (day + int(2.6*month-0.2) - 2*century + year + year/4 + century/4 == 1){
                    endSprey = day;
                    break;
                }
                day--;
            }
            month = 4;
            day = 1;
            for (int i = 0; i < 31; i++){
                if (day + int(2.6*month-0.2) - 2*century + year + year/4 + century/4 == 1){
                    endThomas = day;
                    break;
                }
                day++;
            }
            double orgtime = stod(time.substr(0,2)) + stod(time.substr(3))/100;
            double UTC = orgtime - times[org];
            month = stoi(date.substr(5,2));
            day = stoi(date.substr(8,2));
            if (org == "Sprey" && month >= 3 && month <= 11){
                if (month == 3){
                    if (day >= startSprey && stoi(time.substr(0,2)) >= 2){
                        UTC--;
                    }
                }
                else if (month == 11){
                    if (day == endsprey){
                        UTC--;
                    }
                }
            }
            cout << org << "\'s meeting:\n";
            for (int i = 0; i < people.size(); i++){
                double usertime = UTC + times[people[i]];
                string susertime = to_string(usertime);
                susertime = susertime.substr(0,2) + ":" + susertime.substr(3,2);
                cout << people[i] << " " << date << " " << susertime << "\n";
            }
        }

        return 0;
}