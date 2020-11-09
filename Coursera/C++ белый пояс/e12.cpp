#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: vector;
using std :: count;
using std :: map;
using std :: min;
using std :: string;

vector<int> in(vector<int>& x) {
    for (int& y : x)
        cin >> y;
    return x;
}

int main() {
    int n1, n2, count = 0;
    cin >> n1 >> n2;
    vector<int> mass1(n1);
    vector<int> mass2(n2);
    in(mass1);
    in(mass2);
    struct all {
        int number;
        double counts;
    };
    vector<all> mass;
    for (int i = 0; i < n1; i++) {
        int k = mass1[i];
        mass.push_back({mass1[i], count(mass1.begin(), mass1.end(), k)});

    }
}
