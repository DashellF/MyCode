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
            // cout << (day + int(2.6*month-0.2) - 2*century + year + year/4 + century/4)%7;

            if (org == "Sprey"){
                if (month > 3 && month < 11){
                    UTC--;
                }
                else if (month == 3){
                    if (day > startSprey){
                        UTC--;
                    }
                    else if (day == startSprey){
                        if (stoi(time.substr(0,2)) >= 2){
                            UTC--;
                        }
                    }
                }
                else if (month == 11){
                    if (day < endSprey){
                        UTC--;
                    }
                     else if (day == endSprey){
                        if (stoi(time.substr(0,2)) < 2){
                            UTC--;
                        }
                    }
                }
            }

            else if (org == "Anderson"){
                if (month > 3 && month < 10){
                    UTC--;
                }
                else if (month == 3){
                    if (day > startAnderson){
                        UTC--;
                    }
                    else if (day == startAnderson){
                        if (stoi(time.substr(0,2)) >= 1){
                            UTC--;
                        }
                    }
                }
                else if (month == 10){
                    if (day < endAnderson){
                        UTC--;
                    }
                     else if (day == endAnderson){
                        if (stoi(time.substr(0,2)) < 2){
                            UTC--;
                        }
                    }
                }
            }

            else if (org == "Thomas"){
                if (month < 4 && month > 10){
                    UTC--;
                }
                else if (month == 4){
                    if (day < endThomas){
                        UTC--;
                    }
                    else if (day == endThomas){
                        if (stoi(time.substr(0,2)) < 3){
                            UTC--;
                        }
                    }
                }
                else if (month == 10){
                    if (day > startThomas){
                        UTC--;
                    }
                     else if (day == startThomas){
                        if (stoi(time.substr(0,2)) >= 2){
                            UTC--;
                        }
                    }
                }
            }

            cout << org << "\'s meeting:\n";
            for (int i = 0; i < people.size(); i++){
                double usertime = UTC + times[people[i]];
                
                if (people[i] == "Sprey"){
                    if (month > 3 && month < 11){
                        usertime--;
                    }
                    else if (month == 3){
                        if (day > startSprey){
                            usertime--;
                        }
                        else if (day == startSprey){
                            if (stoi(time.substr(0,2)) >= 2){
                                usertime--;
                            }
                        }
                    }
                    else if (month == 11){
                        if (day < endSprey){
                            usertime--;
                        }
                        else if (day == endSprey){
                            if (stoi(time.substr(0,2)) < 2){
                                usertime--;
                            }
                        }
                    }
                }

                else if (people[i] == "Anderson"){
                    if (month > 3 && month < 10){
                        usertime--;
                    }
                    else if (month == 3){
                        if (day > startAnderson){
                            usertime--;
                        }
                        else if (day == startAnderson){
                            if (stoi(time.substr(0,2)) >= 1){
                                usertime--;
                            }
                        }
                    }
                    else if (month == 10){
                        if (day < endAnderson){
                            usertime--;
                        }
                        else if (day == endAnderson){
                            if (stoi(time.substr(0,2)) < 2){
                                usertime--;
                            }
                        }
                    }
                }

                else if (people[i] == "Thomas"){
                    if (month < 4 && month > 10){
                        usertime--;
                    }
                    else if (month == 4){
                        if (day < endThomas){
                            usertime--;
                        }
                        else if (day == endThomas){
                            if (stoi(time.substr(0,2)) < 3){
                                usertime--;
                            }
                        }
                    }
                    else if (month == 10){
                        if (day > startThomas){
                            usertime--;
                        }
                        else if (day == startThomas){
                            if (stoi(time.substr(0,2)) >= 2){
                                usertime--;
                            }
                        }
                    }
                }
                map<int, int> MonthDays = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};  
                if (usertime > 24){
                    usertime -= 24;
                    day++;
                    if (day > MonthDays[month]){
                        month++;
                        day = 1;
                        if (month > 12){
                            year++;
                            month = 1;
                        }
                    }
                }
                string susertime = to_string(usertime);
                if (susertime[1] ==  '.'){
                    susertime = "0" + susertime;
                }
                string sday = to_string(day);
                if (sday.length() == 1){
                    sday = "0" + sday;
                }
                string smonth = to_string(month);
                if (smonth.length() == 1){
                    smonth = "0" + smonth;
                }
                susertime = susertime.substr(0,2) + ":" + susertime.substr(3,2);
                cout << people[i] << " " << year << '-' << smonth << '-' << sday << " " << susertime << "\n";
            }
        }

        return 0;
}