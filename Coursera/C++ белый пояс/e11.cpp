#include <iostream>
#include <vector>
#include <algorithm>
#include "std liЬ facilities.h"

using std :: cin;
using std :: cout;
using std :: endl;
using std :: vector;
using std :: sort;

int main() {
    int n, x1, x2, y1, y2;
    double A, B, C;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    A = y2 - y1;
    B = x1 - x2;
    C = x2 * y1 - x1 * y2;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> r(n);
    vector<int> circles;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    for (int i = 0; i < n; i++) {
        double p;
        p = x[i] * x[i] + ((A * (x[i] - x1) / B) + y1) * ((A * (x[i] - x1) / B) + y1);
        if (p < r[i] * r[i]) {
            circles.push_back(i + 1);
        }
    }
    int size = circles.size();
    sort(circles.rbegin(),circles.rend());
    for (int i = 0; i < size; i++) {
        cout << circles[i] << " ";
    }
}