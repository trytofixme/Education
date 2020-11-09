#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*void print_vector(vector<Students>& st) {
    for (Students& student : st) {
        cout << student.name << " " << student.surname << endl << student.day << "." << student.moth << "." << student.year;
    }
}*/

int main() {
    struct Students {
        string name;
        string surname;
        long int day;
        long int moth;
        long int year;

    };

    long int counts_of_students;
    cin >> counts_of_students;
    vector<Students> all_students;
    long int request_numbers, number_of_student, student_day, student_year, student_month;
    string request, first_name, last_name;

    for (int i = 0; i < counts_of_students; i++) {
        cin >> first_name >> last_name >> student_day >> student_month >> student_year;
        all_students.push_back({first_name, last_name, student_day, student_month, student_year});
    }

    cin >> request_numbers;

    for (int i = 0; i < request_numbers; i++) {
        cin >> request >> number_of_student;
        --number_of_student;
        if (request == "name" && number_of_student >= 0 && number_of_student < counts_of_students) {
                cout << all_students[number_of_student].name << " " << all_students[number_of_student].surname
                     << endl;
        } else if (request == "date" && number_of_student >= 0 && number_of_student < counts_of_students) {
                cout << all_students[number_of_student].day << "." << all_students[number_of_student].moth
                     << "."
                     << all_students[number_of_student].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
}
