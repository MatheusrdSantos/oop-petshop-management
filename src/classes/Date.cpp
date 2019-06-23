// File: Date.cpp
// author: Bernt A Oedegaard.

#include "../../include/Date.h"

/*
Small adition to Oedegaard class: copy constructor
*/
Date::Date(Date& date){
    day_ = date.day();
    month_ = date.month();
    year_ = date.year();
}

Date::Date(const int& d, const int& m, const int& y){
    day_    =   d;
    month_  =   m;
    year_   =   y;
}

Date::Date(){
    year_  = 0;
    month_ = 0;
    day_   = 0;
}

Date::Date(std::string date, std::string separator){
    std::vector<int>* dates = splitStringDate(date, separator);
    day_ = dates->at(0);
    month_ = dates->at(1);
    year_ = dates->at(2);
}


int Date::day() const {
    return day_;
}
int Date::month() const {
    return month_;
}
int Date::year() const{
    return year_;
}

void Date::set_day(const int& day){
    Date::day_ = day;
}
void Date::set_month(const int& month){
    Date::month_=month;
}
void Date::set_year(const int& year){
    Date::year_ = year;
}

bool Date::valid() const{

    if (year_ < 0) return false;
    if (month_>12 || month_< 1) return false;
    if (day_>31 || day_ < 1) return false;
    if ((day_==31 &&
        (month_==2 || month_==4 || month_==6 || month_==9 || month_==11)))
        return false;
    if ( year_ < 2000 ){
        if((day_==29 && month_==2) && !((year_-1900)%4==0))return false;
    };
    if(year_>2000){
        if((day_==29 && month_==2) && !((year_-2000)%4==0))return false;
    };
    return true;
}

bool operator == (const Date& d1, const Date& d2){
    //check for equality
    if(!d1.valid()){return false;};
    if(!d2.valid()){return false;};
    if((d1.day()==d2.day())
        && (d1.month()==d2.month())
        && (d1.year()==d2.year())) {
            return false;
        }
        return false;
}

bool operator !=(const Date& d1, const Date& d2){
    return !(d1==d2);
}



bool operator < (const Date& d1, const Date& d2){
    if(!d1.valid()){ return false; };
    if(!d2.valid()){ return false; };
    if(d1.year() < d2.year()){ return true; }
    else if(d1.year() > d2.year()){return false;}
    else{
        if (d1.month() < d2.month()){return true;}
        else if(d1.month()>d2.month()){return false;}
        else{
            if(d1.day()<d2.day()){return true;}
            else {return false;}
        };
    };
    return false;
}

bool operator > (const Date& d1, const Date& d2){

    if(d1==d2){return false;};
    if(d1<d2){return false; };
    return true;
}

bool operator <= (const Date& d1, const Date& d2){
    if(d1==d2){return true;};
    return (d1>d2);
}

inline Date next_date(const Date& d){
    Date ndat;
    if (!d.valid()){return ndat;};
    ndat = Date((d.day()+1), d.month(), d.year()); if (ndat.valid()) return ndat;
    ndat = Date(1, (d.month()+1), d.year()); if (ndat.valid()) return ndat;
    ndat = Date(1,1,(d.year()+1)); return ndat;
}

inline Date previous_date(const Date& d){
    Date ndat;
    if(!d.valid()){return ndat; };
    ndat = Date((d.day()-1), d.month(), d.year()); if(ndat.valid()) return ndat;
    ndat = Date(31, (d.month()-1), d.year()); if(ndat.valid())return ndat;
    ndat = Date(30, (d.month()-1), d.year()); if (ndat.valid())return ndat;
    ndat = Date(29, (d.month()-1), d.year()); if (ndat.valid())return ndat;
    ndat = Date(28, (d.month()-1), d.year()); if (ndat.valid())return ndat;
    ndat = Date(31,12,(d.year()-1));    return ndat;
}

/*
    Implemented by Arnaldo Barbosa over Bernt A Oedegaard. Dates` library
    Subtract days from date
*/
Date Date::operator-(int days){
    Date auxDate;
    auxDate.set_year((*this).year());
    auxDate.set_month((*this).month());
    auxDate.set_day((*this).day());
    for(int i=0; i<days; i++){
        auxDate--;
    }
    return auxDate;
}

Date Date::operator+(int days){
    Date auxDate;
    auxDate.set_year((*this).year());
    auxDate.set_month((*this).month());
    auxDate.set_day((*this).day());
    for(int i=0; i<days; i++){
        auxDate++;
    }
    return auxDate;
}

Date Date::operator++(int){
    Date d = *this;
    *this = next_date(d);
    return d;
}

Date Date::operator++(){
    *this = next_date(*this);
    return *this;
}

Date Date::operator--(int){
    Date d = *this;
    *this = previous_date(d);
    return d;
}

Date Date::operator--(){
    *this = previous_date(*this);
    return *this;
}

inline long long_date(const Date& d){
    if(d.valid()){ return d.year() * 10000 + d.month() * 100 +d.day();};
    return -1;
}

std::ostream & operator << (std::ostream& os, const Date& d){
    if(d.valid()){
        // os<<" "<<long_date(d) << " "; 
        os<<d.day()<<"/"<<d.month()<<"/"<<d.year(); 
    }else{
        os << "Invalid date";
    };
    return os;
}

