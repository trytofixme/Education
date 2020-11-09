#include <set>
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using std :: string;
using std :: cin;
using std :: cout;
using std :: endl;
using std :: multiset;
using std :: map;
using std :: pair;
using std :: vector;
using std :: make_pair;
using std :: set;

pair<string, string> sorted_pair(const string& word1, const string& word2) {
    return (word1 <= word2) ? make_pair(word1, word2) : make_pair(word2, word1);
}

bool check(const string& word1, const string& word2, const set<pair<string, string>>& words) {
    return words.count(sorted_pair(word1, word2)) != 0;
}


int main() {
    set<pair<string, string>> all_words;
    map<string, int> counts_of_words;
    map<int, set<pair<s>>> words;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++) {
            string word;
            cin >> word;
            ++counts_of_words[word];
        }

                ++counts_of_words[word2];
                all_words.insert(sorted_pair(word1, word2));
            cin >> word1 >> word2;
            if (check(word1, word2, all_words))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
    }
}