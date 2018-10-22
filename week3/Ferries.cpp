#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    // Declare program variables
    double passengerFare = 0;           // Initialize Passenger Fare to zero
    double vehicleFare = 0;             // Initialize Vehicle Fare to zero

    double total = 0;                   // Initialize total to zero at beginning of program
    char vehicle;                       // Initialize vehicle char
    double vehicleLength;               // Initialize vehicle length double
    char seniorOrDisabled;              // Initialize variable to store senior or disabled driver information
    char tallVehicle;                   // Initialize variable to store whether vehicle is taller than 7'2"
    
    int adults = 0;
    int seniors = 0;
    int youth = 0;
    int bikes = 0;
    
    cout << fixed << showpoint;
    cout << setprecision(2);

    // Introduction
    cout << "Welcome to Alaa Alokby's Fare Calculator" << endl;

    // Get vehicle information
    cout << "Are you driving a vehicle onto the ferry? (y/n) ";
    cin >> vehicle;
    // cout << endl;
    
    // If user is bringing a vehicle
    if (vehicle == 'y' || vehicle == 'Y'){
        cout << "How long is your vehicle in feet? ";
        cin >> vehicleLength;
        
        // Vehicle Length less than 14 feet.
        if (vehicleLength < 14.0){

            // Check if driver is senior or disabled
            cout << "Is the driver a Senior Citizen or Disabled? (y/n): ";
            cin >> seniorOrDisabled;
            cout << endl;
            
            if (seniorOrDisabled == 'y' || seniorOrDisabled == 'Y'){
                vehicleFare = 44.25;                                    // Senior/Disabled vehicle fare
            }
            else{
                vehicleFare = 50.90;                                    // Non-Senior/Disabled vehicle fare
            }
        }
        
        // Vehicle Length greater than 14 feet and less than 22 feet
        else if(vehicleLength >= 14.0 && vehicleLength < 22.0){
            
            // Check if driver is senior or disabled
            cout << "Is the driver a Senior Citizen or Disabled? (y/n): ";
            cin >> seniorOrDisabled;

            if (seniorOrDisabled == 'y' || seniorOrDisabled == 'Y'){
                vehicleFare = 57.10;
            }
            else{
                vehicleFare = 63.75;
            }
        }

        // Long vehicle fares (Longer than 22 feet)
        else if (vehicleLength >= 22.0 && vehicleLength < 30.0){
            
            // Check if vehicle is over 7'2" High
            cout << "Is your vehicle over 7 feet, 2 inches in height? (y/n) ";
            cin >> tallVehicle;
            
            if (tallVehicle == 'y' || tallVehicle == 'Y'){
                vehicleFare = 197.10;
            }
            else{
                vehicleFare = 98.70;
            }
        }

        // Vehicles Longer than 30 feet and shorter than 40 feet
       else if (vehicleLength >= 30.0 && vehicleLength < 40.0){
            vehicleFare = 263.80;
        }

        // Get remaining passenger information
        cout << "How many passengers in your vehicle? (excluding the driver)" << endl;
        cout << "\tRegular Fare Adults: ";
        cin >> adults;
        cout << "\tSenior Citizens or Disabled: ";
        cin >> seniors;
        cout << "\tYouth: ";
        cin >> youth;
    }

    // If user is not bringing a vehicle
    else if (vehicle != 'y' && vehicle != 'Y'){
        
        cout << "How many Regular Fare Adults in your group? ";
        cin >> adults;
        cout << "How many Senior Citizens or Disabled persons in your group? ";
        cin >> seniors;
        cout << "How many Youths in your group? ";
        cin >> youth;
        cout << "How many bicycles? ";
        cin >> bikes;
  
    }
    
    // Calculate total fare
    passengerFare = adults * 13.25 + seniors * 6.60 + youth * 6.60 + bikes * 4.00;
    total = static_cast<float>(passengerFare + vehicleFare);

    cout << "Your total fare is $" << total << endl;
    cout << "Thank you for using Alaa Alokby's Fare Calculater" << endl;

    
    return 0;
}
