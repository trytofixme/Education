#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <vector>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;
using std :: tolower;
using std :: sort;
using std :: vector;

string str_low(const string& s) {
    string result_str;
    for (const auto& iter : s)
        result_str += tolower(iter);

    return result_str;
}

int main() {
    int n;
    cin >> n;
    vector<string> str(n);
    for (string &x : str)
        cin >> x;
    sort(str.begin(), str.end(), [](const string& x, const string& y) {return str_low(x) < str_low(y);});
    for (const auto& x : str)
        cout << x << " ";
}
