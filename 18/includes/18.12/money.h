//
// Created by alexandr on 24.05.2021.
//

#ifndef PRACTICE_PSTU_MONEY_H
#define PRACTICE_PSTU_MONEY_H

#include <iostream>
#include <string>

using namespace std;

class Money
{
public:
    Money(void);
    Money(int, int);
    Money(const Money&);

    Money operator-(Money k);
    Money& operator=(const Money&);
    int GetDop();
    friend ostream& operator<< (ostream& out, const Money&);
    friend istream& operator>> (istream& in, Money&);
public:
    virtual ~Money(void) {};
private:
    int rub, kop, dop;
};

Money::Money()
{
    rub = 0;
    kop = 0;
    dop = 0;
}

Money::Money(float rub, float kop, int dop)
{
    this->rub = rub;
    this->kop = kop;
    this->dop = dop;
}

Money:: ~Money() {}

void Money::SetRub()
{
    float val;
    cout << "Enter rub: ";
    cin >> val;
    while (val < 0)
    {
        cout << "Enter correct number: ";
        cin >> val;
    }
    this->rub = val;
}

long Money::GetRub() { return rub; }

void Money::SetKop()
{
    float tmp;
    cout << "Enter kop: ";
    cin >> tmp;
    while (tmp > 99 || tmp < 0)
    {
        cout << "Enter correct number: ";
        cin >> tmp;
    }
    this->kop = tmp;
}

int Money::GetKop() { return kop; }

void Money::SetDop()
{
    int tmp1;
    cout << "Ââåäèòå âû÷èòàåìûå êîïåéêè: ";
    cin >> tmp1;
    while (tmp1 > 99 || tmp1 < 0)
    {
        cout << "Ââåäèòå êîððåêòíîå ÷èñëî:  ";
        cin >> tmp1;
    }
    this->dop = tmp1;
}

int Money::GetDop() { return dop; }

void Money::PrintClass()
{
    cout << "Çíà÷åíèå: " << this->rub << "," << this->kop << endl;
}

void Money::GetRazn()
{
    if (kop >= dop)
        kop -= dop;
    else {
        rub--;
        kop = 100 + kop - dop;
    }
}


Money& Money::operator++()
{
    rub++;
    return *this;
}

Money& Money::operator++(int a)
{
    Money tmp(*this);
    this->rub++;
    return tmp;
}

ostream& operator<<(ostream& out, const Money& m)
{
    out << m.rub;
    out << ",";
    out << m.kop;
    return out;
}

istream& operator>>(istream& in, Money& m)
{
    cout << "Enter rub:   ";
    in >> m.rub;
    cout << "Enter kop:   ";
    in >> m.kop;
    return in;
}

fstream& operator>>(fstream& fin, Money& m)
{
    fin >> m.rub;
    fin >> m.kop;
    return fin;
}

fstream& operator<<(fstream& fout, const Money& m)
{
    fout << m.rub << endl;
    fout << m.kop << endl;
    return fout;
}

bool Money::operator!=(Money secondOperand)
{
    return rub != secondOperand.rub && kop != secondOperand.kop;
}

#endif //PRACTICE_PSTU_MONEY_H
