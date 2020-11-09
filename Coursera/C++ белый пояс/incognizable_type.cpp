#include <string>

using std :: string;

struct Specialization {
    string value;
    explicit Specialization (string s) {
        value = s;
    }
};

struct Course {
    string value;
    explicit Course (string s) {
        value = s;
    }
};

struct Week {
    string value;
    explicit Week (string s) {
        value = s;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle (const Specialization& s1, const Course& s2, const Week& s3) {
        specialization = s1.value;
        course = s2.value;
        week = s3.value;
    }
};