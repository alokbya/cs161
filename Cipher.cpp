// Cipher.cpp
// This program largely revolves around an array, alphabetArray[], which has 50 elements initialized
// to zero at the beginning of the program. Each element corresponds to an ASCII value of a character
// in the alphabet. Elements 0-24 are reserved for UPPERCASE letters A-Z. Elements 25-49 are
// reserved for lowercase letters a-z. The function streamChar() streams data in from a file and 
// adds 1 to the corresponding element in the array, based on the characters streamed from the file.
// The function getShift() then finds the element with the highest value. With the understanding that
// the element with the highest value will correspond to the letter 'e', the function will be able to make
// an appropriate shift based on which element has the highest integer value.


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function prototypes
void streamChar(int someArray[]);                   // Stream all characters from file into array
int getShift(int someArray[]);                      // Determine character encryption shift
string getFilePath();                               // Prompt user to enter path name, return path name
void writeOut(string filePath, int shift);          // Create new decrypted file

int main(){
    
    // Declare variables
    int alphabetArray[25] = { 0 };                  // Create alphabet array with 25 elements set to 0
    int shift = 0;
    /*for(int i = 0; i < 50; i++){
        cout << alphabetArray[i] << endl;
    }
    streamChar(alphabetArray);
    cout << endl << endl;
    for(int j = 0; j < 50; j++){
        cout << alphabetArray[j] << endl;
    }*/
    // Stream from input file
    streamChar(alphabetArray);
    // Now the array is filled with data

    // get shift
    shift = getShift(alphabetArray);

    // write new decrypted file
    // writeOut("encrypted.txt", shift);

    // create output file, input file and open
    ifstream ifile;
    ofstream ofile;

    bool shifted = false;
    int dnum;
    char letter;
    int anum;
    int difference;

    ifile.open("b.txt");
    ofile.open("d.txt");
    while(ifile.peek() != EOF){
        ifile >> noskipws >> letter;                    // get letter into char
        anum = static_cast<int>(letter);                // num representation of letter
        cout << "original letter: " << anum << " - " << letter << endl;
        
        if(anum < 97 || anum > 122 && anum < 65 || anum < 90){                    
            dnum = anum;                                // Case where decrypted number is same as original
        }
        else if(anum >= 97 && anum <= 122){             // Handle lowercase letters
            if(shift >= 0){                             // If the shift is greater than zero
            dnum = anum - shift;                        // Attempt to shift numbers (decrypt) back
            cout << "SHIFTED!!!" << endl;
            shifted = true;                             // Set shifted bit to true

            if(dnum < 97 && shifted == true){
                difference = 97 - dnum;
                dnum = 123 - difference;
            }
            }
            else if(shift <= 0){                        // If the shift is less than zero
                dnum = anum - shift;                    // Shift forward (adding)
                cout << "SHIFTED!!!" << endl;
                shifted = true;

                if(dnum > 122 && shifted == true){
                    difference = dnum - 122;
                    dnum = 96 + difference;
                }
            }
        }
        else if(anum >= 65 && anum <= 90){              // Handle uppercase letters
            
        }
        
        cout << "decrypted letter: " << dnum << " - " << static_cast<char>(dnum) << endl;
        shifted = false;                                // Set shifted bit to false
        ofile << static_cast<char>(dnum);
    }
    ifile.close();
    ofile.close();

    return 0;
}

// streamChar
// This function streams all characters from a file
// and fills the array 'alphabetArray' with the frequency 
// of each letter. 50 elements in the array correspond to the combination
// of upper and lowercase letters in the ascii table. The upper case 
// letters reside from alphabetArray[0] through alphabetArray[24]. The 
// lowercase letters reside from alphabetArray[25] through alphabetArray[49].
// Note that arrays are always passed by reference to functions.
void streamChar(int array[]){
    // Declare variables
    ifstream inputFile;             // Create input stream file object
    char letter;                    // Create char object to store characters from input
    int number;                     // Create int to store ASCII value of 'letter'
    
    // Open file
    //inputFile.open(getFilePath());
    inputFile.open("b.txt");
    if(!inputFile.is_open()){
        cout << "Could not open file at directed file path..." << endl;
        cout << "Exiting program." << endl;
        exit(0);
    }
    else{
        while(inputFile.peek() != EOF){
            inputFile >> noskipws >> letter;
            
            // Check if letter is lowercase or uppercase alphabet letter add 1 to corresponding element
            number = static_cast<int>(letter);
            if(number >= 97 && number <= 122){                         // If letter is between a-z
                array[number - 97] += 1;                               // Add one to corresponding position
            }           
        }        
        inputFile.close();
    }
}

// getShift
// This function finds the index of a passed-in array with the hightest
// integer value.
int getShift(int array[]){
    // Declare variable to store index of letter with highest frequency.
    int index = 0;
    int freq = 0;
    int shift = 0;
    int asciiValue = 0;
    // Loop through array -- find the index and value of 'e'
    for(int i = 0; i < 25; i++){
        if(array[i] >= freq){
            freq = array[i];
            index = i;
            cout << "Index: " << index << ", Value: " << freq << endl;
        }
    }
    // Use index of highest frequency letter to find shift
    // ASCII - e: 101
    asciiValue = index + 97;                                    // Get index in range of lower case letters
    shift = -(101 - asciiValue);                                // Give shift implicit direction
    cout << "Total Shift: " << shift << endl; 
    return shift;                                               // Return shift
}

// getFilePath
// This function prompts the user for the file path of the encrypted text.
// The function returns the string of the file path.
string getFilePath(){
    string pathName;                                                            // Variable to store path name
    cout << "Please enter the absolute path for the encrypted text file: " ;
    getline(cin, pathName);

    return pathName.c_str();                                                    // return c_str of pathName
}

// writeOut
// This function reads encrypted input from fileName and creates a decrypted output file
/*void writeOut(string fileName, int shift){
    // Declare local variables
    char letter;                                // Holds char value from input stream
    int number;                                 // Holds integer value of letter
    int decNumber = 0;                              // Decrypted number, after applying shift
    int difference = 0;                             // Used for number out of ASCII letter bounds
    // Declare input and output files
    ifstream inputData;
    ofstream outputData;
    // Open input data file
    inputData.open(fileName);
    if(!inputData.is_open()){
        cout << "Cannot open input file: " << fileName << "." << endl;
        cout << "Exiting program... " << endl;
        exit(0);
    }
    else{
        // Open output file
        outputData.open("decrypted.txt");                                   // Open output file
        if(!outputData.is_open()){
            cout << "Cannot open output file:'decrypted.tx'" << endl;
            cout << "Exiting program..." << endl;
            exit(0);
        }
        else{
            // Read in data
            while(inputData.peek() != EOF){                            // While not at end-of-file...
                inputData >> noskipws >> letter;                                   // Read in single character
                number = static_cast<int>(letter);                     // Get int value of char
                // Differentiate between letter casing
                if(number >= 65 && number <= 90){                      // If letter is uppercase
                    decNumber = number + shift;                        // Set decNum to shifted number
                    if(decNumber < 65){                                // If decNum below range
                        difference = 65 - decNumber;                   // Find number of steps below 65
                        decNumber = 91 - difference;                   // Set the correct decrypted number
                    }
                    else if(decNumber > 90){                           // If decNum above range
                        difference = 90 - decNumber;                   // Find how much above
                        decNumber = 64 + difference;                   // Normalize by adding to 64
                    }
                }
                else if(number >= 97 && number <= 122){                // If number is lowercase
                    decNumber = number + shift;                        // Set decNum to decrypted num
                    if(decNumber < 97){
                        difference = 97 - decNumber;
                        decNumber = 123 - difference;
                    }
                    else if(decNumber > 122){
                        difference = 122 - decNumber;
                        decNumber = 96 + difference;
                    }
                }
                // Write decrypted letter to output file
                if(decNumber != 0){
                    outputData << static_cast<char>(decNumber);
                }
                else{
                    outputData << static_cast<char>(number);
                }
                decNumber = 0;
            }
        }
    }

    // Close input and output data files
    inputData.close();
    outputData.close();
}
*/
