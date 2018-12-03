// This program prompts the user to enter a date within a described format, and processes
// the day of the week for that given date. Code is used from the week 2 assignment to 
// determine the day of the week of New Year's Day for a given year.
// By: Alaa Alokby
// Sources: https://www.en.wikipedia.org/wiki/Leap_year
// Date: 2 December 2018

#include <iostream>         // Standard input, output
#include <string>           // String objects
#include <cstdlib>          // exit(0)

using namespace std;

// Function Prototypes
int yearStart(int year);                                               // Find day of week of Jan 1 for given year
void getDate(int &day, string &month, int &year);                      // Get user defined date
int dayOfWeek (int day, int month, int year);                          // Get day of the week
void checkDate(int &day, string &month, int &year, int &monthInt);     // Validate the user defined date
bool isLeapYear(int year);                                             // Determine if year is leap year
void nonValidDate(int day, string month, int year);                    // Exit program if user date is not valid
string getDayString(int dayOfWeekInteger);                             // Convert integer to readable string

int main(){
    
    // Declare Variables
    int userDay = 0;                    // Store user assigned day
    string userMonth;                   // Store user assigned month
    int userYear = 0;                   // Store the user assigned year
    int monthInteger = 0;               // Store the integer value of a month
    int weekday = 0;                    // Store weekday for user assigned date


    // Process date 
    getDate(userDay, userMonth, userYear);
    checkDate(userDay, userMonth, userYear, monthInteger);
    weekday = dayOfWeek(userDay, monthInteger, userYear);

    // Output information to console
    cout << userDay << " " << userMonth << " " << userYear << " falls on a " << getDayString(weekday) << endl;
    cout << "Thank you for using Alaa's Weekday Calculator" << endl;
    
    return 0;
}

// getDayString(int)
// This function accepts an integer argument and outputs a string that corresponds to the integer.
// The dayOfWeek() function returns an integer that identifies a day of the week
// with a code that corresponds to the index of each element inside of the days [] array
// within this function. 
string getDayString(int day){
    
    // Declare Variables
    string days [] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day];
}


// yearStart(int)
// Returns the day of the week that the year starts, given the year.
// 0: Sunday... 6: Saturday
// The logic for this code was used from the week 2 assignment
int yearStart(int year){
    
    // Declare Variables
    int dayOfWeek;                  // Store day of week code
    int difference;                 // Store number of shifts from 1900
    float leaps;                    // store number of leaps contained in difference

    // Initialize and Define Constants
    const int STARTING_DAY = 1;
    const int DAYS_IN_WEEK = 7;
    const int STARTING_YEAR = 1900;

    // Calculate day of week for year argument
    difference = year - STARTING_YEAR;          // Calculate the difference between 'year' and 1900
    leaps = ((difference / 4.0) - (0.25));      // Calculate number of years that have leaped
    dayOfWeek = (STARTING_DAY + difference + (static_cast<int>((leaps)))) % DAYS_IN_WEEK;    
    
    return dayOfWeek;
}

// getDate();
// This function prompts the user to enter three pieces of data, the day as an integer
// the month as a string, and the year as an integer. This function is passed three 
// variables by reference so that it can make changes to all of these variables within
// the functions scope.
void getDate(int &day, string &month, int &year){
    
    // Declare Variables
    string date;

    cout << "Welcome to Alaa's Weekday Calculator" << endl;
    cout << "What is the date (dd mmm yyyy): ";
    cin >> day >> month >> year;
}

// dayOfWeek(int day, int month, int year)
// This function accepts the user defined date, from getDate(), and returns the day of the week
// according to this date. 
int dayOfWeek(int day, int month, int year){
    
    // Declare Variable
    string months [] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int days [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int weekday = 0;
    int startingDay = 0;            // Starting day of week for given year
    int indexOfMonth = 0;           // Store month index to use for days [] jn month
    int totalDays = 0;              // Store total days since Jan 1

    // Get startingDay
    startingDay = yearStart(year);  // Use week 2 algorithm to find day of week of Jan 1 in user defined year

    // Find number of days passed since Jan 1
    // month - 1 adds up to the month prior to given month, which days will add onto to find correct day
    for(int i = 0; i < month - 1; i++){
        totalDays += days[i];                      // Increment totalDays by number of days in each prior month
    }
    
    // Add on days to find total days since Jan 1
    totalDays += day;                              // Increment totalDays by day of the user defined month

    // Calculate day of week 
    weekday = (startingDay + totalDays) % 7 - 1;   // Sum the total days, and find the remainder when divided by 7

    return weekday;
}

// checkDate(int day, string month, int year)
// Validate the date, make sure it can be processed. Check to make sure that the user defined date
// is reasonable, and that it can be processed to determine the day of the week.
void checkDate(int &day, string &month, int &year, int &monthInt){
    
    // Declare Local Variables
    string months [] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int days [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool dayBit = false;
    bool monthBit = false;
    bool yearBit = false;

    // Validate Month
    for(int i = 0; i < 12; i++){
        // Get the numeric value for the month 
        // If the month matches months [], assign value
        if(month == months[i]){
            monthBit = true;
            monthInt = i + 1;
        }
    }

    // Continue Month Validation
    if(!monthBit){
        nonValidDate(day, month, year);
    }

    // Validate Day
    if(day < 0 || day > days[monthInt - 1]){
        dayBit = false;
        nonValidDate(day, month, year);
    }
    else if(isLeapYear(year) && month == months[2] && day == 29){       // Leap year Feb adjustment
        dayBit = true;        
    }
    else{
        dayBit = true;
    }

    // Validate year
    if(year < 1900 || year > 2099){
        yearBit = false;
        nonValidDate(day, month, year);
    }
    else{
        yearBit = true;
    }
    
    // If any part of the date is not valid, exit the program
    if(!dayBit || !monthBit || !yearBit){
        nonValidDate(day, month, year);
    }
}

// isLeapYear(int)
// Determine if the parameter (year) is a leap year. This is primarily
// used in the case that February 29th is used in the user defined date.
bool isLeapYear(int year){
    if(year % 4 != 0){
        return false;
    }
    else if(year % 100 != 0){
        return true;
    }
    else if(year % 400 != 0){
        return false;
    }
    else{
        return true;
    }
}

// nonValidDate(int, string, int)
// Exit program if user date is not valid. This function will exit the program and
// show the user the incorrect date that they input.
void nonValidDate(int day, string month, int year){
    cout << day << " " << month << " " << year << " is not a valid date." << endl;
    cout << "Thank you for using Alaa's Weekday Calculator" << endl;
    exit(0);
}
