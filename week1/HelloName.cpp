//This is the Hello Name program, for Assignment 1.
// This program is written in ANSI standard C++, and 
// conducts a dialog with the user of the program.
// Written by: Alaa Alokby
// Date: 9/24/2018
// Sources: None


#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declare variables for user's name, sign, and subject
    string name;
    string sign;
    string subject;

   // Begin program 
    cout << "Welcome to Alaa Alokby's Crystal Ball!" << endl;               
    
    cout << "What is your name, please? ";                      // Prompt user for name
    cin >> name;                                                // Store user input
    cout << "Hello, " << name << ". My name is Alaa." << endl;
   
    cout << "What is your astrological sign, " << name << "? ";
    cin >> sign;                                                // Store user input
   
    cout << "What subject are you studying, " << name << "? ";
    cin >> subject;                                             // Store user input 
   
    cout << "Well, " << name << ", your horoscope for " << sign;
    cout << " says you will do very well in " << subject;
    cout << " this term." << endl;
    cout << "Good luck!" << endl;
    
    return 0;
}
