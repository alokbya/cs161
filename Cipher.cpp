#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function prototypes
void streamChar(int&);                              // Stream variables from file into array

int main(){
    
    // Declare variables
    string filePath = "encrypted.txt";              // create filePath variable
    int alphabetArray[50] = { 0 };                     // Create alphabet array, initialize elements to zero

    streamChar(alphabetArray);
    
    // print letter frequency
    // ...
    for(int i = 0; i < 50; i++{
        if(i <= 25){
            cout << static_cast<char>(alphabet[i]) << ": " << static_cast<char>(i + 97) << endl; 
        }
        else{
            cout << static_cast<char>(alphabet[i]) << ": " << static_cast<char>(i + 65) << endl;
        }
    }
    return 0;
}

void streamChar(int& alphabet){
    // Create local variables
    ifstream inFile;                    // Create file object
    char letter;                        // Variable to hold letter
    int number;                         // Variable to hold number
    inFile.open(filePath);              // Open file

    // Verify that the file path is correct and file can be opened
    if(!inFile.is_open()){
        cout << "Could not open the file..." << endl;
        cout << "Program is exiting..." << endl;
        exit(0);                                                            // Exit program, return 0

    }
    else{
        // Stream characters from file into array
        while(inFile.peek() != EOF){
            inFile >> letter;
            number = static_cast<int>(letter);
            if(number >= 97 && number <= 122){
                alphabet[number - 97] += 1;
            }
            else if(number >= 65 && number <= 90){
            alphabet[number - 40] += 1;

            }
        }
        inFile.close();                                                     // Close File
    }

}


