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
        map<string, double> times = {{"Smith", -7}, {"Sprey", -5}, {"Anderson", 0},
                                     {"Bolade", 1}, {"Hassan", 2}, {"Agarwal", 5.3},
                                     {"Sato", 9}, {"Thomas", 10}};
        string line;
        getline(cin, line);
        stringstream a(line);
        string org, date, time;
        a >> org >> date >> time;
        string temp;
        vector<string> people;
        while (a >> temp) {
            people.push_back(temp);
        }
        people.push_back(org);
        sort(people.begin(), people.end());

        int century, year, month, day;
        year = stoi(date.substr(0, 4));
        century = year / 100;
        year %= 100;

        int startSprey, endSprey, startAnderson, endAnderson, startThomas, endThomas;
        month = 3;
        day = 1;

        for (int i = 0; i < 31; i++) {
            if ((day + (13 * (month + 1)) / 5 + year + year / 4 + century / 4 + 5 * century) % 7 == 0) {
                startSprey = day + 7;
                break;
            }
            day++;
        }
        day = 31;
        for (int i = 0; i < 31; i--) {
            if ((day + (13 * (month + 1)) / 5 + year + year / 4 + century / 4 + 5 * century) % 7 == 0) {
                startAnderson = day;
                break;
            }
            day--;
        }

        month = 10;
        day = 1;
        for (int i = 0; i < 31; i++) {
            if ((day + (13 * (month + 1)) / 5 + year + year / 4 + century / 4 + 5 * century) % 7 == 0) {
                startThomas = day;
                break;
            }
            day++;
        }

        day = 31;
        for (int i = 0; i < 31; i--) {
            if ((day + (13 * (month + 1)) / 5 + year + year / 4 + century / 4 + 5 * century) % 7 == 0) {
                endAnderson = day;
                break;
            }
            day--;
        }

        month = 11;
        day = 31;
        for (int i = 0; i < 31; i--) {
            if ((day + (13 * (month + 1)) / 5 + year + year / 4 + century / 4 + 5 * century) % 7 == 0) {
                endSprey = day;
                break;
            }
            day--;
        }

        month = 4;
        day = 1;
        for (int i = 0; i < 31; i++) {
            if ((day + (13 * (month + 1)) / 5 + year + year / 4 + century / 4 + 5 * century) % 7 == 0) {
                endThomas = day;
                break;
            }
            day++;
        }

        double orgtime = stod(time.substr(0, 2)) + stod(time.substr(3)) / 100;
        double UTC = orgtime - times[org];
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));

        if (org == "Sprey") {
            if (month > 3 && month < 11) {
                UTC--;
            } else if (month == 3 && (day > startSprey || (day == startSprey && stoi(time.substr(0, 2)) >= 2))) {
                UTC--;
            } else if (month == 11 && (day < endSprey || (day == endSprey && stoi(time.substr(0, 2)) < 2))) {
                UTC--;
            }
        }

        else if (org == "Anderson") {
            if (month > 3 && month < 10) {
                UTC--;
            } else if (month == 3 && (day > startAnderson || (day == startAnderson && stoi(time.substr(0, 2)) >= 1))) {
                UTC--;
            } else if (month == 10 && (day < endAnderson || (day == endAnderson && stoi(time.substr(0, 2)) < 2))) {
                UTC--;
            }
        }

        else if (org == "Thomas") {
            if (month < 4 || month > 10) {
                UTC--;
            } else if (month == 4 && (day < endThomas || (day == endThomas && stoi(time.substr(0, 2)) < 3))) {
                UTC--;
            } else if (month == 10 && (day > startThomas || (day == startThomas && stoi(time.substr(0, 2)) >= 2))) {
                UTC--;
            }
        }

        printf("%s's meeting:\n", org.c_str());

        for (const string& person : people) {
            double usertime = UTC + times[person];

            if (person == "Sprey") {
                if (month > 3 && month < 11 || (month == 3 && (day > startSprey || (day == startSprey && stoi(time.substr(0, 2)) >= 2))) ||
                    (month == 11 && (day < endSprey || (day == endSprey && stoi(time.substr(0, 2)) < 2)))) {
                    usertime++;
                }
            } else if (person == "Anderson") {
                if (month > 3 && month < 10 || (month == 3 && (day > startAnderson || (day == startAnderson && stoi(time.substr(0, 2)) >= 1))) ||
                    (month == 10 && (day < endAnderson || (day == endAnderson && stoi(time.substr(0, 2)) < 2)))) {
                    usertime++;
                }
            } else if (person == "Thomas") {
                if (month < 4 || month > 10 || (month == 4 && (day < endThomas || (day == endThomas && stoi(time.substr(0, 2)) < 3))) ||
                    (month == 10 && (day > startThomas || (day == startThomas && stoi(time.substr(0, 2)) >= 2)))) {
                    usertime++;
                }
            }

            if (usertime >= 24) {
                usertime -= 24;
                day++;
                if (day > 31) { 
                    month++; 
                    day = 1; 
                    if (month > 12) { 
                        year++; 
                        month = 1; 
                    }
                }
            }

            int hour = static_cast<int>(usertime);
            int minute = static_cast<int>((usertime - hour) * 100);
            printf("%s %04d-%02d-%02d %02d:%02d\n", person.c_str(), year, month, day, hour, minute);
        }
    }

    return 0;
}
