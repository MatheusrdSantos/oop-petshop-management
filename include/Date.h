// File: Date.h
// author: Bernt A Oedegaard.
#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "utils.h"


class Date{
    protected:
        int year_;
        int month_;
        int day_;
    public:
        Date();
        Date(Date& date);
        Date(const int& d, const int& m, const int& y);
        Date(std::string date, std::string separator);

        bool valid(void) const;

        int day() const;
        int month() const;
        int year() const;

        void set_day(const int& day);
        void set_month(const int& month);
        void set_year(const int& year);

        Date operator ++();
        Date operator ++(int);
        Date operator --();
        Date operator --(int);
        Date operator - (int);
        Date operator + (int);
};


bool operator == (const Date&, const Date&);
bool operator != (const Date&, const Date&);
bool operator < (const Date&, const Date&);
bool operator > (const Date&, const Date&);
bool operator <=(const Date&, const Date&);
bool operator >=(const Date&, const Date&);

std::ostream& operator << (std::ostream& os, const Date& d);

#endif
