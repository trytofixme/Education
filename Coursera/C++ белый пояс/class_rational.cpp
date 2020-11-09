#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <exception>

using namespace std;

// Комментарии, которые говорят, что именно нужно реализовать в этой программе

class Rational {
public:
    Rational() {
        value_n = 1;
        value_z = 0;
    };
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
           throw invalid_argument("invalid");
        }
        int A = abs(numerator);
        int B = abs(denominator);
        while (A > 0 && B > 0) {
            if (A > B) {
                A %= B;
            }
            else {
                B %= A;
            }
        }

        if (B == 0) {
            numerator /= A;
            denominator /= A;
        }

        if (A == 0) {
            numerator /= B;
            denominator /= B;
        }

        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            if (numerator < 0) {
                value_z = numerator;
                value_n = denominator;
            }
            else if (denominator < 0) {
                value_z = (-1) * numerator;
                value_n = (-1) * denominator;
            }
        }
        else if (numerator > 0 && denominator > 0) {
            value_z = numerator;
            value_n = denominator;
        }
        else if (numerator < 0 && denominator < 0) {
            value_z = (-1) * numerator;
            value_n = (-1) * denominator;
        }
        if (numerator == 0) {
            value_z = 0;
            value_n = 1;
        }
    };

    int Numerator() const {
        return value_z;
    };
    int Denominator() const {
        return value_n;
    };
private:
    int value_z;
    int value_n;
};

bool operator <(const Rational& value1, const Rational& value2) {
    if (value1.Denominator() == value2.Denominator()) {
        return value1.Numerator() < value1.Numerator();
    } else {
        return (value1.Numerator() * value2.Denominator()) < (value2.Numerator() * value1.Denominator());
    }
}

bool operator >(const Rational& value1, const Rational& value2) {
    if (value1.Denominator() == value2.Denominator()) {
        return value1.Numerator() > value1.Numerator();
    } else {
        return (value1.Numerator() * value2.Denominator()) > (value2.Numerator() * value1.Denominator());
    }
}


istream & operator>>(istream& in, Rational& value) {
    int p, q;
    if (in >> p && in.ignore(1) && in >> q) {
        if (q == 0) {
            throw invalid_argument("invalid");
        }
        value = {p, q};
    }
    return in;
}

ostream & operator<<(ostream& out, const Rational& value) {
    out << value.Numerator() << '/' << value.Denominator();
    return out;
}

Rational operator* (const Rational& value1, const Rational& value2) {
    return Rational(value1.Numerator() * value2.Numerator(), value1.Denominator() * value2.Denominator());
}

Rational operator/ (const Rational& value1, const Rational& value2) {
    if (value2.Numerator() == 0) {
        throw domain_error("whaat?");
    }
    return Rational(value1.Numerator() * value2.Denominator(), value1.Denominator() * value2.Numerator());
}

Rational operator+ (const Rational& value1, const Rational& value2) {
    if (value1.Denominator() == value2.Denominator()) {
        return Rational(value1.Numerator() + value2.Numerator(), value1.Denominator());
    } else {
        return Rational(value1.Numerator() * value2.Denominator() + value1.Denominator() * value2.Numerator(), value1.Denominator() * value2.Denominator());
    }
}

Rational operator- (const Rational& value1, const Rational& value2) {
    if (value1.Denominator() == value2.Denominator()) {
        return Rational(value1.Numerator() - value2.Numerator(), value1.Denominator());
    } else {
        return Rational(value1.Numerator() * value2.Denominator() - value1.Denominator() * value2.Numerator(), value1.Denominator() * value2.Denominator());
    }
}

bool operator == (const Rational& value1, const Rational& value2) {
    return value1.Numerator() == value2.Numerator() && value2.Denominator() == value1.Denominator();
}

int main() {
    int x, y, z, f;
    char operation, slash1, slash2;
    cin >> x >> slash1 >> y >> operation >> z >> slash2 >> f;
    if (y == 0 || f == 0) {
        cout << "Invalid argument";
        return 0;
    }
    int n;
    Rational first(x, y);
    Rational second(z, f);
    switch (operation) {
        case '+' :
            cout << first + second;
            break;
        case '-' :
            cout << first - second;
            break;
        case '*' :
            cout << first * second;
            break;
        case '/' :
            if (second.Numerator() == 0) {
                cout << "Division by zero";
                return 0;
            }
            cout << first / second;
            break;
        default:;
    }
    return 0;
}
