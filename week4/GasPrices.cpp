// This program reads input data from a file stream and performs calculations on the data. 
// Specifically, this program is designed to calculate gas price averages of three different
// states: California, Oregon, and Washington.
// The program projects the raw stream of data as standard output to the console, for the user,
// and then determines the average gas price in each of the three states, the total average price
// of gas for all three states, and finally, the state with the lowest gas price and the state with
// the highest gas price.
// Written by: Alaa Alokby
// Sources: "C++ Programming: From Problem Analysis to Program Design, By: D.S. Malik",
//          Module 5 course material
// Date: 2 November, 2018


#include <iostream>
#include <fstream>
#include <string>                           // for string type, and stod() (string to double conversion)
#include <iomanip>
#include <cstdlib>                          // For exit()

using namespace std;

int main(){
    
    string filePath;                        // Declare variable to store data file path from user
    ifstream inData;                        // Declare stream object variable for input data

    double calSum = 0;                      // Declare and initialize state gas price sums
    double oreSum = 0;
    double wasSum = 0;                      
    
    double calAve = 0;                      // Declare and initialize variables to store average costs 
    double wasAve = 0;
    double oreAve = 0;

    int calStation = 0;                     // Store number of stations to find average price
    int oreStation = 0;
    int wasStation = 0; 

    string city;                            // Declare variables to hold input from file stream
    string state;
    string line;                            // Declare variable to hold a single line from input file
    string token;                           // Hold input
    string strPrice;                        // Store un-converted string price value

    // Introduction
    cout << "Please enter the file path to the datafile on disk: ";
    getline(cin, filePath);
    
    // Open file and begin stream 
    inData.open(filePath.c_str());

    // Verify that file path is correct and file can be opened
    if (!inData.is_open()){
        cout << "Could not open file at given file path" << endl;
        cout << "Program is exiting..." << endl;
        exit(0);                             // Return a 0, indicating completion of program
    }
    else{
        cout << "File opened successfully!" << endl << endl;
        cout << endl << "GAS PRICES" << endl;
       
        // Echo data from text file
        while(inData.peek() != EOF){
            getline(inData, line);
            cout << line << endl;
        }
        
        // Clear data stream and rewind to first byte of stream
        inData.clear();
        inData.seekg(0);

        // Stream input data from text file
        while(inData >> city >> state >> strPrice){
            // Sort the gas prices into buckets to later find averages
            if(state == "Ca"){
                calStation++;
                calSum += stod(strPrice);
            }
            else if(state == "Or"){
                oreStation++;
                oreSum += stod(strPrice);
            }
            else if(state == "Wa"){
                wasStation++;
                wasSum += stod(strPrice);
            }
        }

        // Calculate average price of gas per state
        calAve = calSum / calStation;
        oreAve = oreSum / oreStation;
        wasAve = wasSum / wasStation;

        // Set precision to 3 decimal places
        cout << fixed << showpoint << setprecision(3);

        // Show average price of gasoline per state
        cout << endl;
        cout << "Average Gas Prices Per State" << endl;
        cout << "CAL: $" << calAve << endl;
        cout << "ORE: $" << oreAve << endl;
        cout << "WAS: $" << wasAve << endl;
        cout << endl; 

        // Show average price of gas for all stations
        cout << "Total Average Price of Gas" << endl;
        cout << "Total Average: $" << (calSum + oreSum + wasSum)/(calStation + oreStation + wasStation) << endl;
        cout << endl;

        // Show state with lowest average price
        if(calAve <= oreAve && calAve <= wasAve){
            cout << "Lowest Average: California" << endl;
        }
        else if(oreAve <= calAve && oreAve <= wasAve){
            cout << "Lowest Average: Oregon" << endl;
        }
        else if(wasAve <= oreAve && wasAve <= calAve){
            cout << "Lowest Average: Washington" << endl;
        }
       
        // Show state with highest average price
        if(calAve >= oreAve && calAve >= wasAve){
            cout << "Highest Average: California" << endl;
        }
        else if(oreAve >= calAve && oreAve >= wasAve){
            cout << "Highest Average: Oregon" << endl;
        }
        else if(wasAve >= calAve && wasAve >= oreAve){
            cout << "Highest Average: Washington" << endl;
        }
    }
    
    // Close data file
    inData.close();                     
    
    // End of file stream and Data Analysis
    cout << endl << "End of Program" << endl;

    return 0;
}








