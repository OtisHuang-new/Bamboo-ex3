#include "social.h"
Date::Date() {
    day = new int(1);
    month = new int(1);
    year = new int(1);

    hour = new int(0);
    minute = new int(0);
}

Date::Date(int day, int month, int year, int hour, int minute) {
    this->day = new int(day);    
    this->month = new int(month);
    this->year = new int(year);

    this->hour = new int(hour);
    this->minute = new int(minute);
    this->Validate();
}

Date::Date(const string& dateStr) { //dd-mm-yyyy hh:mm
    int day = stoi(dateStr.substr(0,2));
    int month = stoi(dateStr.substr(3,2));
    int year = stoi(dateStr.substr(6,4));
    int hour = stoi(dateStr.substr(11,2));
    int minute = stoi(dateStr.substr(14,2));
    if (!this->day) {
        this->day = new int(day);    
        this->month = new int(month);
        this->year = new int(year);

        this->hour = new int(hour);
        this->minute = new int(minute);
    }
    else {
        *this->day = day;
        *this->month = month;
        *this->year = year;

        *this->hour = hour;
        *this->minute = minute;
    }
    this->Validate();
}
Date::Date(const Date& other) {
        day = new int(*(other.day));
        month = new int(*(other.month));
        year = new int(*(other.year));

        hour = new int(*(other.hour));
        minute = new int(*(other.minute));
}
Date& Date::operator=(const Date& other) {
    Date date;
    if (&other && &date != &other) {
        *date.day = *other.day;
        *date.month = *other.month;
        *date.year = *other.year;

        *date.hour = *other.hour;
        *date.minute = *other.minute;
    }
    return *this;
}
Date::~Date() {
    delete day;
    delete month;
    delete year;

    delete hour;
    delete minute;
}

bool Date::isLeapYear(){
    if(!this) return false;
    return (*year % 4 == 0 && *year % 100 != 0 || *year % 400 == 0);
}
void Date::Validate() {
    if(!this) return;
    int daysOfMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->isLeapYear())
        daysOfMonths[2] = 29;
    if(*minute > 59) {
        *hour += *minute / 60;
        *minute = * minute % 60; 
    }
    if(*hour > 23) {
        *day += *hour/ 24;
        *hour = *hour % 24; 
    }
    while(*day > daysOfMonths[*month]) {
        *day -= daysOfMonths[*month];
        *month ++; 
        if(*month > 12) {
            year++;
            *month = 1;
            if (this->isLeapYear())
                daysOfMonths[2] = 29;
            else
                daysOfMonths[2] = 28;
        }
    }
    while(*month > 12) {
        *month -= 12;
        *year++;
    }
}

istream& operator>>(istream& in, Date& date) {
    string s;
    getline(in, s);
    date = Date(s);
    return in;
}
ostream& operator<<(ostream& out, const Date& date) {
    if(!date.day) {
    out << "No date to show.\n";
        return out;
    } 
    out << setw(2) << *date.day << "-" << setw(2) << *date.month << "-" << setw(4) << *date.year << " " 
    << setw(2) << *date.hour << ":" << *date.minute << endl;
    return out;
}


