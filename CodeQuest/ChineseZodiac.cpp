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
            int year;
            cin >> year;
            string aspect, element, animal;
            string aspectArr[] = {"Yang", "Yin"};
            string elementArr[] = {"Wood", "Fire", "Earth", "Metal", "Water"};
            string animalArr[] = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
            aspect = aspectArr[year%2];

            int temp = year;
            temp -= 4;
            temp = temp % 10;
            temp /= 2;
            element = elementArr[temp];

            temp = year;
            temp -= 4;
            temp = temp  % 12;
            animal = animalArr[temp];

            cout << year << " " << aspect << " " << element << " " << animal << "\n";
        }

        return 0;
}