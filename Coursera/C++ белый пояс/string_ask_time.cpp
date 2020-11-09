#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>

using namespace std;

string AskTimeServer() {
    ifstream input;
    string line;

    while (getline(input, line)) {
        return line;
    }
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            LastFetchedTime = AskTimeServer();
            return LastFetchedTime;
        }
        catch (system_error&) {
            return LastFetchedTime;
        }
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}