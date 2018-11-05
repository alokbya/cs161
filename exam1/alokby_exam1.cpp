// This program reads in numbers as standard input from the user through their console and evaluates
// whether the number is even, odd, or negative. If the input is even, the value of that number
// is stored into a variable to sum all even input values. Likewise, a variable will store all 
// user-entered variables that are odd. The program will ignore any negative numbers with the exception
// of the Sentinel (-999) that will evacuate the input loop and return results for sum and count, for 
// both even and odd values that were entered.
// By: Alaa Alokby
// Sources: None
// Date: 3 November 2018

#include <iostream>     // standard input/output
#include <string>       // string object, methods, stod() -- converts strings to doubles
#include <cmath>        
#include <cstdlib>      // exit()
#include <iomanip>      // output formatting, fixed, showpoint, setprecision()

using namespace std;

int main(){
   
    // Declare and initialize variables
    double evenSum = 0;     // Variable to store sum of even numbers
    double oddSum = 0;      // Variable to store sum of odd numbers
    
    int evenCount = 0;      // Variable to store count of even numbers
    int oddCount = 0;       // Variable to store count of odd numbers

    string userInput;       // Variable to store input from user

    // Prompt user to enter numbers
    do{
        cout << "Please input a number, and press enter: ";
        cin >> userInput;

    // Check if the input is odd and greater than 0 
    if(static_cast<int>(stod(userInput)) %2 != 0.00 && static_cast<int>(stod(userInput)) > 0) {
        oddCount++;                 // Increment odd count if input is odd
        oddSum += stod(userInput);  // Add input to sum of odd numbers
    }
    // Check if the input is even and greater than 0
    else if(static_cast<int>(stod(userInput)) %2 == 0.00 && static_cast<int>(stod(userInput)) > 0){
        evenCount++;                // Increment even count if input is even            
        evenSum += stod(userInput); // Add input to sum of even numbers
    }
    }while(static_cast<int>(stod(userInput)) != -999);  // Continue this loop while input is not -999

    // Set precision in case user enters decimal numbers
    cout << fixed << showpoint << setprecision(2);

    // Return information (sum and count) for even numbers
    cout << endl;
    cout << "EVEN" << endl << "----" << endl;
    cout << "Sum: " << evenSum << endl;
    cout << "Count: " << evenCount << endl;
    cout << endl;
    // Return information (sum and count) for odd numbers
    cout << "ODD" << endl << "---" << endl;
    cout << "Sum: " << oddSum << endl;
    cout << "Count: " << oddCount << endl;

    cout << endl;
    cout << "Thank you!" << endl;

    return 0;
}
