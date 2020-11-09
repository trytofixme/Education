#include <string>
#include <map>
#include <vector>
//#include <iostream>
#include <algorithm>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
    string name;
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
        } else
            break;
    }
    return name;
}

class Person {

public:
    Person (const string& str1, string str2, int year_of_born) {
        first_names[year_of_born] = str1;
        last_names[year_of_born] = str2;
        born_year = year_of_born;
    }

    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) const {
        if (born_year != 0 && year < born_year) {
            return "No person";
        }

        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) const {
        if (born_year != 0 && year < born_year) {
            return "No person";
        }
        vector<string> names;
        vector<string> lasts;
        for (const auto& iter : first_names) {
            if (iter.first <= year) {
                names.push_back(iter.second);
            }
        }
        for (const auto& iter : last_names) {
            if (iter.first <= year) {
                lasts.push_back(iter.second);
            }
        }

        auto its = unique (names.begin(), names.end());
        names.resize(distance(names.begin(),its));
        auto itz = unique (lasts.begin(), lasts.end());
        lasts.resize(distance(lasts.begin(),itz));

        reverse(names.begin(), names.end());
        reverse(lasts.begin(), lasts.end());

        string all_names;
        string all_lasts;
        for (int i = 0; i < names.size(); i++) {
            if (i == 0 && names.size() == 1)
                all_names += names[i];
            else if (i == 0 && names.size() > 1)
                all_names += (names[i] + " (");
            else if (i != names.size() - 1)
                all_names += (names[i] + ", ");
            else
                all_names += (names[i] + ")");
        }

        for (int i = 0; i < lasts.size(); i++) {
            if (i == 0 && lasts.size() == 1)
                all_lasts += lasts[i];
            else if (i == 0 && lasts.size() > 1)
                all_lasts += (lasts[i] + " (");
            else if (i != lasts.size() - 1)
                all_lasts += (lasts[i] + ", ");
            else if (i == lasts.size() - 1)
                all_lasts += (lasts[i] + ")");
        }

        if (all_names.empty() && !all_lasts.empty())
            return all_lasts + " with unknown first name";
        else if (all_lasts.empty() && !all_names.empty())
            return all_names + " with unknown last name";
        else if (!all_lasts.empty() && !all_names.empty())
            return all_names + " " + all_lasts;
        else
            return "Incognito";
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
    int born_year = 0;
};
/*
int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
*/