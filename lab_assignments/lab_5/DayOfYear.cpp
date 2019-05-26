//Che Blankenship

// File for member functions
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#include "DayOfYear.h" // Class


// Constructor 1 //
// constructor for the class should take as parameter an integer representing the day of the year.
// Example: Day 32 => February 1
DayOfYear::DayOfYear(int dayOfYear)
{
    // attribute and param have same name
    this->dayOfYear = dayOfYear;

    converter(dayOfYear);


}


// Constructor 2 //
// second constructor that takes two parameters: a string representing month and an integer (1-31) for the day of the month.
DayOfYear::DayOfYear(string month, int day)
{
    this->month = month;
    std::transform(month.begin(), month.end(), month.begin(), ::tolower);

    if (month == "january")
    {
        this->dayOfYear = day;
    }
    else if(month == "february")
    {
        this->dayOfYear = 31 + day;
        dayOfMonth = day;
    }
    else if(month == "march")
    {
        this->dayOfYear = 59 + day;
        dayOfMonth = day;
    }
    else if(month == "april")
    {
        this->dayOfYear = 90 + day;
        dayOfMonth = day;
    }
    else if(month == "may")
    {
        this->dayOfYear = 120 + day;
        dayOfMonth = day;
    }
    else if(month == "june")
    {
        this->dayOfYear = 151 + day;
        dayOfMonth = day;
    }
    else if(month == "july")
    {
        this->dayOfYear = 181 + day;
        dayOfMonth = day;
    }
    else if(month == "augest")
    {
        this->dayOfYear = 212 + day;
        dayOfMonth = day;
    }
    else if(month == "september")
    {
        this->dayOfYear = 243 + day;
        dayOfMonth = day;
    }
    else if(month == "october")
    {
        this->dayOfYear = 273 + day;
        dayOfMonth = day;
    }
    else if(month == "november")
    {
        this->dayOfYear = 304 + day;
        dayOfMonth = day;
    }
    else if(month == "december")
    {
        this->dayOfYear = 334 + day;
        dayOfMonth = day;
    }
    else
    {
        std::cout << "ERROR!!!! DayOfYear(string, int) " << '\n';
    }
}


// member function print() that prints the day in the month-day format
void DayOfYear::print()
{
    cout << month << " " << dayOfMonth << "," << endl;
}


// Convert to Month day format using dayOfYear
void DayOfYear::converter(int dOfY)
{
    // January
    if (dayOfMonth <= 31)
    {
        month = "January";
        dayOfMonth = dayOfYear;
    }
    // February
    if (31 < dayOfYear && dayOfYear <= 59)
    {
        month = "February";
        dayOfMonth = dayOfYear - 31;
    }
    // March
    if (59 < dayOfYear && dayOfYear <= 90)
    {
        month = "March";
        dayOfMonth = dayOfYear - 59;
    }
    // April
    if (90 < dayOfYear && dayOfYear <= 120)
    {
        month = "April";
        dayOfMonth = dayOfYear - 90;
    }
    // May
    if (120 < dayOfYear && dayOfYear <= 151)
    {
        month = "May";
        dayOfMonth = dayOfYear - 120;
    }
    // June
    if (151 < dayOfYear && dayOfYear <= 181)
    {
        month = "June";
        dayOfMonth = dayOfYear - 151;
    }
    // July
    if (181 < dayOfYear && dayOfYear <= 212)
    {
        month = "July";
        dayOfMonth = dayOfYear - 181;
    }
    // Augest
    if (212 < dayOfYear && dayOfYear <= 243)
    {
        month = "Augest";
        dayOfMonth = dayOfYear - 212;
    }
    // September
    if (243 < dayOfYear && dayOfYear <= 273)
    {
        month = "September";
        dayOfMonth = dayOfYear - 243;
    }
    // October
    if (273 < dayOfYear && dayOfYear <= 304)
    {
        month = "October";
        dayOfMonth = dayOfYear - 273;
    }
    // Novermber
    if (304 < dayOfYear && dayOfYear <= 334)
    {
        month = "Novermber";
        dayOfMonth = dayOfYear - 304;
    }
    // December
    if (334 < dayOfYear && dayOfYear <= 365)
    {
        month = "December";
        dayOfMonth = dayOfYear - 334;
    }
}
