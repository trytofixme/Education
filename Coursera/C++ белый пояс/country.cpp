#include <iostream>
#include <map>
#include <string>

using std :: string;
using std :: map;
using std :: cin;
using std :: cout;
using std :: endl;

void print_map(const map<string, string>& n) {
for (const auto& it : n)
    cout << it.first << "/" << it.second << " ";
}

int main() {
    int n;
    cin >> n;
    map<string, string> list;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (list.count(country) == 0)
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            else {
                const string& old_capital = list[country];
                if (old_capital == new_capital)
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                else
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
            }
            list[country] = new_capital;
        }
        else if (operation == "RENAME") {
            string new_country, old_country;
            cin >> old_country >> new_country;
            if (old_country == new_country || list.count(old_country) == 0 || list.count(new_country) == 1)
                cout << "Incorrect rename, skip" << endl;
            else {
                cout << "Country " << old_country << " with capital " << list[old_country] << " has been renamed to "
                     << new_country << endl;
                list[new_country] = list[old_country];
                list.erase(old_country);
            }
        }
        else if (operation == "ABOUT") {
            string country;
            cin >> country;
            if (list.count(country) == 0)
                cout << "Country " << country << " doesn't exist " << endl;
            else
                cout << "Country " << country << " has capital " << list[country] << endl;
        }
        else if (operation == "DUMP") {
           if (list.empty())
               cout << "There are no countries in the world" << endl;
           else
               print_map(list);
        }
    }
}