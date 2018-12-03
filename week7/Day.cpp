#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
using namespace std;

// Function Prototypes
int yearStart(int year);            // Find day of week of Jan 1 for given year
void getDate(int &day, string &month, int &year);                   // Get user defined date
int dayOfWeek (int day, int month, int year);   // Get day of the week

int main(){
    
    // Declare Variables
    int userDay = 0;
    string userMonth;
    int userYear = 0;


    getDate(userDay, userMonth, userYear);
    cout << dayOfWeek(25, 12, 2018) << endl;
    cout << endl;
    cout << "ENTERED" << endl;
    cout << "DAY: " << userDay << endl;
    cout << "MONTH: " << userMonth << endl;
    cout << "YEAR: " << userYear << endl;

    return 0;
}

// yearStart(int)
// Returns the day of the week that the year starts, given the year.
// 0: Sunday... 6: Saturday
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
// Prompts user to enter date, returns string with date
void getDate(int &day, string &month, int &year){
    
    // Declare Variables
    string date;

    cout << "Welcome to Alaa's Weekday Calculator" << endl;
    cout << "What is the date (dd mmm yyyy): ";
    cin >> day >> month >> year;
}

int dayOfWeek(int day, int month, int year){
    
    // Declare Variable
    string months [] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int days [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int weekday = 0;
    int startingDay = 0;            // Starting day of week for given year
    int indexOfMonth = 0;           // Store month index to use for days [] jn month
    int totalDays = 0;              // Store total days since Jan 1

    // Get startingDay
    startingDay = yearStart(year);

    // Find number of days passed since Jan 1
    // month - 1 adds up to the month prior to given month, which days will add onto to find correct day
    for(int i = 0; i < month - 1; i++){
        totalDays += days[i];
    }
    
    // Add on days to find total days since Jan 1
    totalDays += day;

    // Calculate day of week 
    weekday = (startingDay + totalDays) % 7 - 1;



    return weekday;
}
