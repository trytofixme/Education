#include <iostream>
#include <vector>
#include <algorithm>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: vector;
using std :: sort;
using std :: abs;
using std :: max;


int main() {
    int n, min = 10000, x1 = 0, x2 = 0;
    long unsigned int iter1 = 0, iter2 = 0;
    cin >> n;
    vector<int> numbers(n);
    vector<int> numbers_positive;
    vector<int> numbers_negative;
    vector<int> numbers_sort;
    for (int& x : numbers)
        cin >> x;
    for (int& x : numbers) {
        if (x >= 0)
            numbers_positive.push_back(x);
        else
            numbers_negative.push_back(x);
    }
    sort(numbers_positive.begin(), numbers_positive.end());
    sort(numbers_negative.begin(), numbers_negative.end());
    numbers_sort.reserve(numbers_negative.size());
    for (int it : numbers_negative) {
        numbers_sort.push_back(it);
    }
    for (int iter : numbers_positive) {
        numbers_sort.push_back(iter);
    }
    for (long unsigned int i = 0; i < numbers.size(); i++) {
        if (i == numbers.size() - 1)
            break;
        if (abs(abs(numbers_sort[i]) - abs(numbers_sort[i + 1])) < min) {
            min = abs(abs(numbers_sort[i]) - abs(numbers_sort[i + 1]));
            x1 = numbers_sort[i];
            x2 = numbers_sort[i + 1];
        }
    }
    for (long unsigned int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == x1) {
            iter1 = i + 1;
            break;
        }
    }
    for (long unsigned int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == x2 && (iter1 - 1) != i) {
            iter2 = i + 1;
            break;
        }
    }
    if (max(iter1, iter2) == iter2)
        cout << endl << min << endl << iter1 << " " << max(iter1, iter2);
    else
        cout << endl << min << endl << iter2 << " " << iter1;
}
