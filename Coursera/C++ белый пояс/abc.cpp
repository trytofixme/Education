#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int N, a[10000]={};
    int min=100000;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> a[i];
        if (a[i]>180 && min>a[i] ) {
            min=a[i];
        }

    }
    cout << min;
    return 0;
}