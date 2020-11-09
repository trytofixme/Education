#include <vector>
#include <algorithm>

using std :: reverse;
using std :: vector;

class FunctionPart {
public:
    FunctionPart (char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply (double x) const {
        if (operation == '+') {
            return x + value;
        }
        else if (operation == '-') {
            return x - value;
        }
        else if (operation == '/') {
            return x / value;
        }
        else
            return x * value;
    }

    void Invert() {
        if (operation == '+')
            operation = '-';
        else if (operation == '-')
            operation = '+';
        else if (operation == '/')
            operation = '*';
        else
            operation = '/';
    };

private:
    char operation;
    double value;
};


class Function {

public:
    void AddPart (char operation, double value) {
        parts.push_back({operation, value});
    }

    double Apply (double x) const{
        for (const FunctionPart& part : parts) {
            x = part.Apply(x);
        }
        return x;
    }
    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    };
private:
    vector<FunctionPart> parts;
};
