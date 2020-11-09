#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void merge(const int *m1, int l1,
           const int *m2, int l2,
           int *o, int lo) {
    int i1 = 0, i2 = 0, io = 0;
    while (i1 < l1 && i2 < l2) {
        if (m1[i1] <= m2[i2]) {
            o[io++] = m1[i1++];
        }
        else {
            o[io++] = m2[i2++];
        }
    }
    while (i1 < l1) {
        o[io++] = m1[i1++];
    }
    while (i2 < l2) {
        o[io++] = m2[i2++];
    }
}

void mergesort(int *m, int l, int r) {
    if ((r - l) == 1) {
        return;
    }
    int mid = (r + l) / 2;
    mergesort(m, l, mid);
    mergesort(m, mid, r);
    int *tmp = new int[r-l];
    merge(m + l, mid - l, m + mid, r - mid, tmp, r - l);
    for (int i = 0; i < r-l; ++i) {
        m[l + i] = tmp[i];
        cout << "Swap elements at indices " << j + 1  << " and " << i + 1 << '.' << endl;
    }
    }
    delete[] tmp;
}

int main () {
    int arr[] = {3,1,4,1,5,9,2,6};
    mergesort(arr,0,8);
    for (auto c : arr) {
        cout << c;
    }
}