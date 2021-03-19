//
// Created by alexandr on 19.03.2021.
//

#ifndef PRACTICE_PSTU_EXAM_H
#define PRACTICE_PSTU_EXAM_H

class Exam {
    string name;
    string subject;
    int rating;
public:
    Exam();
    Exam(string, string, int);
    Exam(const Exam&);
    ~Exam();
    string get_name();
    void set_name(string);
    string get_subject();
    void set_subject(string);
    int get_rating();
    void set_rating(int);
    void show();
};

Exam::Exam() {
    name = "";
    subject = "";
    rating = 0;
}

Exam::Exam(string Name, string Subject, int Rating) {
    name = Name;
    subject = Subject;
    rating = Rating;
}

Exam::Exam(const Exam &data) {
    name = data.name;
    subject = data.subject;
    rating = data.rating;
}

Exam::~Exam() {

}

string Exam::get_name() {
    return name;
}

string Exam::get_subject() {
    return subject;
}

int Exam::get_rating() {
    return rating;
}

void Exam::set_name(string Name) {
    name = Name;
}

void Exam::set_subject(string Subject) {
    subject = Subject;
}

void Exam::set_rating(int Rating) {
    rating = Rating;
}

void Exam::show() {
    cout << "ФИО: " << name << endl;
    cout << "Предмет: " << subject << endl;
    cout << "Оценка: " << rating << endl;
}

// FUNCS

#endif //PRACTICE_PSTU_EXAM_H
