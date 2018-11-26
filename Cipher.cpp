// Cipher.cpp

// This program largely revolves around an array, alphabetArray[], which has 25 elements initialized
// to zero at the beginning of the program. Each element corresponds to an ASCII value of a lower case 
// character in the alphabet. The function streamChar() streams data in from a file and 
// adds 1 to the corresponding element in the array, based on the characters streamed from the file.
// The function getShift() then finds the element with the highest value. With the understanding that
// the element with the highest value will correspond to the letter 'e', the function will be able to make
// an appropriate shift based on which element has the highest integer value.

// By: Alaa Alokby
// Sources: ASCII Table
// Date: 25 November 2018


#include <iostream>                                 // Standard input and output
#include <fstream>                                  // File input and output
#include <string>                                   // String type
#include <cstdlib>                                  // exit()

using namespace std;

// Function prototypes
void streamChar(int someArray[], string encrypted);     // Stream all characters from file into array
int getShift(int someArray[]);                          // Determine character encryption shift
void getFilePath(string& input, string& output);        // Prompt user to enter path name, return path name
void writeOut(string input, int shift, string output);  // Create new decrypted file

int main(){
   
    // Declare variables
    int alphabetArray[25] = { 0 };                  // Create alphabet array with 25 elements set to 0
    int shift = 0;                                  // Declare and initialize variable to hold encryption shift
    string efilePath;                               // Store file path for encrypted text
    string dfilePath;                               // Store file path for deciphered text

    getFilePath(efilePath, dfilePath);              // Prompt user for encrypted file path
   
    // Begin deciphering
    streamChar(alphabetArray, efilePath);           // Stream from input file
    shift = getShift(alphabetArray);                // Get the encryption shift, store in 'shift'
    writeOut(efilePath, shift, dfilePath);          // Decipher, place deciphered text in file: 'd.txt'
    
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
void streamChar(int array[], string encrypted){
    // Declare variables
    ifstream inputFile;                             // Create input stream file object
    char letter;                                    // Create char object to store characters from input
    int number;                                     // Create int to store ASCII value of 'letter'
    
    inputFile.open(encrypted);                      // Open file using passed in file path
    if(!inputFile.is_open()){                       // If input file is not open, exit program
        cout << "Could not open input file at directed file path..." << endl;
        cout << "Exiting program." << endl;
        exit(0);                                    // Exit and return value of 0
    }
    else{
        while(inputFile.peek() != EOF){             // Peek at next line in file, True while not end of file
            inputFile >> noskipws >> letter;        // Input stream from file, don't skip white space
            number = static_cast<int>(letter);
            
            if(number >= 97 && number <= 122){      // If letter is in range a-z
                array[number - 97] += 1;            // Increment corresponding element in array
            }           
        }        
        inputFile.close();                          // Close the input file
    }
}


// getShift
// This function finds the index of a passed-in array with the highest
// integer value. Utilize the knowledge that ASCII value of 'e' is 101.
// Use the index of the letter with the highest frequency to determine the
// shift.
int getShift(int array[]){

    int index = 0;                                  // Used to store the index of the largest integer in array
    int freq = 0;                                   // Used to store the value of the integer at index
    int shift = 0;                                  // Store calculation for total shift
    int asciiValue = 0;                             // Used to store the Ascii value of index

    for(int i = 0; i < 25; i++){                    // Loop through array, find the index and value of 'e'
        if(array[i] >= freq){                       
            freq = array[i];                        // Assign value at index i to freq
            index = i;                              // Assign index to i
        }
    }
    asciiValue = index + 97;                        // Get index in range of lower case letters
    shift = -(101 - asciiValue);                    // Give shift implicit direction
    return shift;                                   // Return shift
}


// getFilePath
// This function prompts the user for the file path of the encrypted text.
// The function returns the string of the file path.
void getFilePath(string& input, string& output){
    cout << "Please enter the absolute path for the encrypted text file: ";
    getline(cin, input);
    cout << "Please enter the absolute path for the clear-text file (deciphered output): ";
    getline(cin, output);
}


// writeOut
// This function reads encrypted input from fileName and creates a deciphered output file
void writeOut(string input, int shift, string output){
    
    ifstream ifile;                                 // Input file
    ofstream ofile;                                 // Output file

    bool shifted = false;                           // Used to indicate if a character needs to be shifted
    int dnum = 0;                                   // Holds ASCII value of deciphered number
    char letter;                                    // Holds original char from file stream
    int anum = 0;                                   // Hold original integer value of character
    int difference = 0;                             // Used to make a correction to characters out of bounds

    ifile.open(input);
    ofile.open(output);

    if(!ifile.is_open()){                           // Handle unsuccessful attempt to open input file
        cout << "Could not successfully open input file: " << input << endl;
        cout << "Exiting program with value 0... " << endl;
        exit(0);    
    }
    else{
        cout << "Successfully opened input file: " << input << endl;
    }
    if(!ofile.is_open()){                           // Handle unsuccessful attempt to open output file
        cout << "Could not successfully open the output file: " << output << endl;
        cout << "Exiting program with value 0... " << endl;
        exit(0);
    }
    else{
        cout << "Successfully opened output file: " << output << endl;
    }
    while(ifile.peek() != EOF){
        ifile >> noskipws >> letter;                // Stream character into char variable, include whitespaces
        anum = static_cast<int>(letter);            // Determine the numerical representation of the character
        
        if(anum < 65 || anum > 90 && anum < 97 || anum > 122){                    
            dnum = anum;                            // Case where there is no shift (punctuation, etc.)
        }
        else if(anum >= 97 && anum <= 122){         // Handle lowercase letters
            if(shift >= 0){                         // If the shift is greater than zero
                dnum = anum - shift;                // Attempt to shift numbers (decrypt) back
                shifted = true;                     // Set shifted bit to true

                if(dnum < 97 && shifted == true){   
                    difference = 97 - dnum;         // Find how far out of bounds the shift pushed the char
                    dnum = 123 - difference;        // Reset dnum to the correct character, roll around
                }
            }
            else if(shift <= 0){                    // If the shift is less than zero (backwards)
                dnum = anum - shift;                // Shift forward to correct (adding)
                shifted = true;                     // Set the shifted bit to true

                if(dnum > 122 && shifted == true){
                    difference = dnum - 122;        // Find how far out of bounds the shift pushed the char
                    dnum = 96 + difference;         // Reset dnum to the correct character, roll around
                }
            }
        }
        else if(anum >= 65 && anum <= 90){          // Handle uppercase letters
           if(shift >= 0){
                dnum = anum - shift;                // First attempt at correcting the Cipher shift
                shifted = true;                     // Set shifted bit to true

                if(dnum < 65 && shifted == true){         
                    difference = 65 - dnum;         // Find how far out of bounds dnum is
                    dnum = 91 - difference;         // Correct dnum
                }
           }
           else if(shift <= 0){
                dnum = anum - shift;                // First attempt with correction shift
                shifted = true;                     // Set shifted bit to true

                if(dnum > 90 && shifted == true){   
                    difference = dnum - 90;         // Find how far out of bounds initial correction was
                    dnum = 64 + difference;         // Correct dnum
                }
           }
        }
        
        shifted = false;                            // Reset shifted bit to false
        ofile << static_cast<char>(dnum);           // Stream out deciphered character
    }
    ifile.close();                                  // Close input file
    ofile.close();                                  // Close output file
}

