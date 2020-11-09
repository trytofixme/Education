#include <iostream>
#include <map>
#include <string>
#include <vector>


using std :: cin;
using std :: cout;
using std :: endl;
using std :: map;
using std :: string;
using std :: vector;

int main() {
    int Q;
    map<string, vector<string>> bus_and_stops;
    map<string, vector<string>> stop_and_buses;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;
        if (operation == "NEW_BUS") {
            string bus_name;
            int stops_count;
            cin >> bus_name >> stops_count;
            for (int j = 0; j < stops_count; j++) {
                string stops;
                cin >> stops;
                bus_and_stops[bus_name].push_back(stops);
                stop_and_buses[stops].push_back(bus_name);
            }
        } else if (operation == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stop_and_buses[stop].empty()) {
                cout << "No stop" << endl;
            } else {
                for (const auto &bus : stop_and_buses[stop])
                    cout << bus << " ";
                cout << endl;
            }
        } else if (operation == "STOPS_FOR_BUS") {
            string bus_name;
            cin >> bus_name;
            if (bus_and_stops.count(bus_name) == 0)
                cout << "No bus" << endl;
            else {
                for (const auto &all_stop : bus_and_stops[bus_name]) {
                    if (stop_and_buses[all_stop].size() == 1)
                        cout << "Stop " << all_stop << ": no interchange" << endl;
                    else {
                        cout << "Stop " << all_stop << ": ";
                        for (const auto &bus : stop_and_buses[all_stop])
                            if (bus != bus_name)
                                cout << bus << " ";
                        cout << endl;
                    }
                }
            }
        }
        if (operation == "ALL_BUSES") {
            if (bus_and_stops.empty())
                cout << "No buses" << endl;
            else
                for (auto[bus, all_stop] : bus_and_stops) {
                    cout << "Bus " << bus << ": ";
                    for (const auto& stop : all_stop)
                        cout << stop << " ";
                    cout << endl;
                }
        }
    }
}