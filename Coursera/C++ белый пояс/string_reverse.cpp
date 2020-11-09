#include <string>
#include <utility>
#include <algorithm>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;
using std :: reverse;

class ReversibleString {
public:
    string Reverse() {
        reverse(word.begin(), word.end());
        return word;
    }
    ReversibleString (string s) {
        word = std::move(s);
    }

    string ToString() const {
        return word;
    }

    ReversibleString () {}

private:
    string word;
};
/*
int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}*/