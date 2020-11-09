#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: vector;
using std :: sort;
using std :: abs;

int main() {
    int n, min = 100000, min1 = 0, min2 = 0, index1 = 0, index2 = 0;
    cin >> n;
    vector<int> numbers(n);
    vector<int> numbers_changed(n);
    for (int& x : numbers)
        cin >> x;
    numbers_changed = numbers;
    sort(numbers.rbegin(), numbers.rend(), [](const int& x, const int& y) { return abs(x) < abs(y);});
    for (int i = 0; i < n; i++) {
        if (i == (n - 1))
            break;
        if (numbers[i] < 0 && numbers[i + 1] < 0) {
            if (numbers[i - 1] - numbers[i] < min) {
                min = numbers[i + 1] - numbers[i];
                min1 = numbers[i + 1];
                min2 = numbers[i];
            }
        }
        else if (numbers[i] > 0 && numbers[i + 1] > 0) {
            if (numbers[i] - numbers[i + 1] < min) {
                min = numbers[i] - numbers[i + 1];
                min1 = numbers[i];
                min2 = numbers[i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (numbers_changed[i] == min1)
            index1 = i++;
        if (numbers_changed[i] == min2)
            index2 = i;
    }
    if (index1 < index2)
        cout << min << endl << index1 + 1 << " " << index2 + 1;
    cout << min << endl << index2 + 1 << " " << index1 + 1;
}
