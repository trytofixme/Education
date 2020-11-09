#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std :: vector;
using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;
using std :: min;

int main() {
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> trouble(31, "");
    int Q, count = 0;
    string operation;
    cin >> Q;
    trouble.resize(months[count]);
    for (int i = 0; i < Q; i++) {
        cin >> operation;
        if (operation == "ADD") {
            string take;
            int day;
            cin >> day >> take;
            trouble[day - 1] += (take + " ");
        } else if (operation == "NEXT") {
            if ( count == 11 ) {
                count = 0;
            } else {
                vector<string> troubles_copy = trouble;
                count++;
                trouble.clear();

                for (int j = 0; j < min(months[count % 12], months[count % 12 - 1]); j++)
                    trouble.push_back(troubles_copy[j]);
                if (months[count % 12 - 1] > months[count % 12]) {

                    for (int j = months[count % 12]; j < months[count % 12 - 1]; j++) {
                        trouble[months[count % 12] - 1] = trouble[months[count % 12] - 1] + troubles_copy[j];
                    }

                } else if (months[count % 12 - 1] < months[count % 12]) {

                    for (int j = months[count % 12 - 1]; j < months[count % 12]; j++) {
                        trouble.push_back("");
                    }

                }
            }
        } else if (operation == "DUMP") {
            int day_out, num = 0;
            cin >> day_out;
            for (const char& can : trouble[day_out - 1]) {
                if (can == ' ') {
                    num++;
                }
            }
            cout << num << " " << trouble[day_out - 1] << endl;
        }
    }
}