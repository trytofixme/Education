#include <iostream>
#include <vector>

using namespace std;

void Fib(unsigned int n) {
    int F0 = 1, F1 = 1;
    vector<vector<unsigned long long int>> mass = {{0, 1}, {1, 1}};
    vector<vector<unsigned long long int>> copy;
    for (int  i = 0; i < n/2; i++) {
        copy[0][0] = mass[0][0] * mass[0][0] + mass[0][1] * mass[1][0];
        copy[0][1] = mass[0][0] * mass[0][1] + mass[0][1] * mass[1][1];
        copy[1][0] = mass[1][0] * mass[0][0] + mass[1][0] * mass[1][1];
        copy[1][1] = mass[1][0] * mass[0][1] + mass[1][1] * mass[1][1];
    }
    cout << copy[0][0] + copy[0][1];
}

int main() {
    unsigned int n = 0;
    cin >> n;
    Fib(n);
}