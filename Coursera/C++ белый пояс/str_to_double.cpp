#include <iostream>
#include <string>
#include <vector>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;
using std :: vector;

int main() {
    string x;
    unsigned long p = 1, k = 0;
    double a = 0;
    vector<int> first;
    vector<int> second;
    cin >> x;

    for (auto c : x) {
        k++;
        if (c == '.')
            break;
    }
    k = x.size() - k;

    for (auto c : x) {
        switch (c) {
            case '1' : first.push_back(1);
                break;
            case '2' : first.push_back(2);
                break;
            case '3' : first.push_back(3);
                break;
            case '4' : first.push_back(4);
                break;
            case '5' : first.push_back(5);
                break;
            case '6' : first.push_back(6);
                break;
            case '7' : first.push_back(7);
                break;
            case '8' : first.push_back(8);
                break;
            case '9' : first.push_back(9);
                break;
            case '0' : first.push_back(0);
                break;
            default: ;
        }
    }

    second.push_back(1);
    for (unsigned long i = 0; i < x.size() - 2; ++i) {
        p *= 10;
        second.push_back(p);
    }

    reverse(begin(second), end(second));
    for (unsigned long  i = 0; i < first.size(); i++) {
        if (first[i])
        a += (first[i] * second[i]);
    }
    for (unsigned long i = 0; i < k; i++) {
        a /= 10;
    }

    cout << a;
}