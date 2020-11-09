#include <iostream>
#include <fstream>
#include <vector>
#include <strings
#include <sstream>

using namespace std;

int kolchisel(vector<int>& arr, ifstream& in) {
    while (!in.eof()) {
        int a;
        in >> a;
        arr.push_back(a);
    }
    cout << arr.size() << std::endl;
    return arr.size();
}
void telo(const vector<int>& arr, ofstream& out, int n) {
    int count, max = 1;
    for (int i = 0, j = 1; j < n; i++, j++) {
        count = 1;
        while (arr[i] <= arr[j] && j < n) {
            count++;
            i++;
            j++;
        }
        if (count > max) {
            max = count;
        }
    }
    cout << max << endl;
}
    int proverkain(ifstream &in) {
        if (!in.is_open()) {
            std::cerr << "Oshibka file ne naiden!" << std::endl;
            return -1;
        }
        return 0;
    }

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> arr;
    string r;

        ifstream in("input.txt");
        proverkain(in);
        ofstream out("out.txt",ios::app);
        int num = kolchisel(arr, in);
        in.close();
        telo(arr, out, num);
        out.close();
    return 0;
}

/*
int main() {
    ifstream in("input.txt");
    string word;
    int a;
    int count = 0;
    vector<int> counts;
    getline(in, word);
    for (char j : word) {
        if (j != ' ')
            counts.push_back(j - '0');
    }
    if (in) {

        for (int i = 0; i < counts[0]; i++) {
            count++;
            for (int k = 0; k < counts[1]; k++) {
                in >> a; // считываем число из потока
                cout << setw(10) << a;
                if (k != counts[1] - 1) {
                    cout << " ";
                }
                in.ignore(1); // игнорируем 1 символ(т.е. запятую)
            }
            if (count != counts[0]) { // условие чтобы лишнего перевода строки не было в конце
                cout << endl;
            }
        }
    }
}*/
