// The day of the week of the new year starts on a Monday in 1900
// and progresses through the week, incrementing by one day for each
// year, unless the year is a leap year. A leap year is defined by a year
// that is divisible by four. In this case the following 
// day of the week that New Years day falls on will skip one day.
// For example 1906: Mo, 1907: Tu, 1908: We, 1909: Fr.

//Alaaddin Alokby

#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int dayOfWeek;        // Sunday (0), Monday (1)...
    int year = 1900; 
    int userYear;
    int difference;
    float leaps;
    float shifts;         // day of week changes
    int startingDay = 1;
    int daysInWeek = 7;


    
    // prompt user - acquire information
    cout << "Welcome to Alaa's New Year's Day Canculator" << endl;
    cout << "What Year?: " ;
    cin >> userYear;
    
    // calculate
    difference = userYear - year;           // calculate the difference between userYear and 1900
    leaps = ((difference / 4.0) - (0.25));  // calculate the number of years that have 'leaped'
    dayOfWeek = (1 + difference + (static_cast<int>((leaps)))) % 7; // calculate day of week of Jan 1
    
    // return day of week on Jan 1 of user defined year
    cout << "New Year's Day " << userYear << " fell on " ;
    cout << "day " << dayOfWeek << " of the week";
    cout << endl;

    // conclude program
    cout << "Thank you for using Alaa's New Year's Day Calculator" << endl;

    return 0;
}

