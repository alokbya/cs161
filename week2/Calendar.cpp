// This program calculates the day of the week on New Year's day for any given year. 
// It has been tested for years 1900 to 2099, inclusively. The program prompts the user 
// to enter a year of their choice, and the program returns the corresponding day of 
// the week. 

// The days are coded as follows:
// Sunday: 0
// Monday: 1
// Tuesday: 2
// Wednesday: 3
// Thursday: 4
// Friday: 5
// Saturday: 6

// 7 October 2018
// Author: Alaaddin Alokby
// Sources: https://www.timeanddate.com/calendar
// Compiled with: gcc version 7.2.0 (GCC)


#include <iostream>
#include <string>

using namespace std;

int main(){

    // Initialize Variables
    int dayOfWeek;                      // variable to store day of week code 
    int userYear;                       // variable to store user input
    int difference;                     // variable to store the number of shifts from 1900
    float leaps;                        // variable to store  number of leaps contained in difference
    
    // Initialize and Define Constants
    const int STARTING_DAY = 1;         // variable to store the day of the week of the starting year
    const int DAYS_IN_WEEK = 7;
    const int STARTING_YEAR = 1900;
    
    // prompt user - acquire information
    cout << endl;
    cout << "Welcome to Alaa's New Year's Day Canculator" << endl;
    cout << "What Year?: " ;
    cin >> userYear;
    
    // calculate day of the week on user year
    difference = userYear - STARTING_YEAR;           // calculate the difference between userYear and 1900
    leaps = ((difference / 4.0) - (0.25));  // calculate the number of years that have 'leaped'
    dayOfWeek = (STARTING_DAY + difference + (static_cast<int>((leaps)))) % DAYS_IN_WEEK; // calculate day of week of Jan 1
    
    // return day of week on Jan 1 of user defined year
    cout << "New Year's Day " << userYear << " fell on " ;
    cout << "day " << dayOfWeek << " of the week";
    cout << endl;

    // conclude program
    cout << "Thank you for using Alaa's New Year's Day Calculator" << endl << endl;

    return 0;
}

