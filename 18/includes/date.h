//
// Created by alexandr on 19.03.2021.
//

#ifndef PRACTICE_PSTU_DATE_H
#define PRACTICE_PSTU_DATE_H

class Date:public Triad {
public:
    Date(void);
    ~Date(void);
    Date(int, int, int);
    Date(const Date&);

    void year(int);
    void month(int);
    void day(int);

    /// Перегруженные операции
    Date& operator++();
    Date operator++(int); // Постфиксная операция
    Date operator+(int);
};

Date::Date(void):Triad() {}
Date::~Date(void) {}
Date::Date(int Year, int Month, int Day):Triad(Year, Month, Day) {}
Date::Date(const Date &D) {
    first = D.first;
    second = D.second;
    third = D.third;
}

// ++VALUE
Date&Date::operator++() {
    int temp = first * 365 + second * 30 + third;
    temp += 1;
    first = temp / 365;
    temp = temp % 365;
    second = temp / 30;
    temp = temp % 30;
    third = temp;
    return *this;
}

// VALUE++
Date Date::operator++(int) {
    int temp = first * 365 + second * 30 + third;
    temp += 1;

    Date t(first, second, third);

    first = temp / 365;
    temp = temp % 365;
    second = temp / 30;
    temp = temp % 30;
    third = temp;
    return t;
}

Date Date::operator+(int days) {
    int temp = first * 365 + second * 30 + third + days;

    Date t(first, second, third);
    first = temp / 365;
    temp = temp % 365;
    second = temp / 30;
    temp = temp % 30;
    third = temp;
    return t;
}

void Date::year(int Year) {
    first = Year;
}

void Date::month(int Month) {
    second = Month;
}

void Date::day(int Day) {
    third = Day;
}

#endif //PRACTICE_PSTU_DATE_H
