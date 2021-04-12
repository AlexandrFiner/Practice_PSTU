//
// Created by alexandr on 19.03.2021.
//

#ifndef PRACTICE_PSTU_MONEY_H
#define PRACTICE_PSTU_MONEY_H

class Money {
    long rub;    // Рубли
    int penny;  // Копеки
public:
    Money() {
        rub = 0;
        penny = 0;
    };
    Money(long r, int p) {
        rub = r;
        penny = p;
    };
    Money(const Money&t) {
        rub = t.rub;
        penny = t.penny;
    }
    ~Money() {};
    long get_rub() {
        return rub;
    }
    int get_penny() {
        return penny;
    }
    void set_rub(long num) {
        rub = num;
    }
    void set_penny(int num) {
        penny = num;
    }
    /// Перегруженные операции
    Money&operator=(const Money&);
    Money& operator++();
    Money operator++(int); // Постфиксная операция
    Money& operator--();
    Money operator--(int); // Постфиксная операция
    Money operator+(const Money&);
    /// Глобальные функции ввода-вывода
    friend istream& operator>>(istream&in, Money&t);
    friend ostream& operator<<(ostream&out, const Money&t);
    friend bool operator== (const Money&c1, const Money&c2);
    friend bool operator!= (const Money&c1, const Money&c2);
};

Money&Money::operator=(const Money &t) {
    if (&t == this) {
        // На самом деле проверка не особо нужна, но иногда пригодится
        return *this;
    }
    rub = t.rub;
    penny = t.penny;
    return *this;
}

bool operator== (const Money &c1, const Money &c2)
{
    return (c1.rub == c2.rub && c1.penny== c2.penny);
}

bool operator!= (const Money &c1, const Money &c2) {
    return !(c1 == c2);
}

// ++VALUE
Money&Money::operator++() {
    long temp = rub*100+penny;
    temp++;
    rub = temp/100;
    penny = temp%100;
    return *this;
}

// VALUE++
Money Money::operator++(int) {
    long temp = rub*100+penny;
    temp++;
    Money t(rub, penny);
    rub = temp/100;
    penny = temp%100;
    return t;
}

Money Money::operator+(const Money &t) {
    int temp1 = rub*100+penny;
    int temp2 = t.rub*100+t.penny;
    int temp = temp1 + temp2;
    Money p;
    p.rub = temp/100;
    p.penny = temp%100;
    return p;
}

// --VALUE
Money&Money::operator--() {
    long temp = rub*100+penny;
    temp--;
    if(temp < 0)
        temp = 0;
    rub = temp/100;
    penny = temp%100;
    return *this;
}

// VALUE--
Money Money::operator--(int) {
    long temp = rub*100+penny;
    temp--;
    if(temp < 0)
        temp = 0;
    Money t(rub, penny);
    rub = temp/100;
    penny = temp%100;
    return t;
}

istream&operator>>(istream&in, Money&t) {
    cout << "Рублей: "; in >> t.rub;
    cout << "Копеек: "; in >> t.penny;
    return in;
}

ostream&operator<<(ostream&out, const Money&t) {
    return (out << t.rub << "," << t.penny);
}

#endif //PRACTICE_PSTU_MONEY_H
