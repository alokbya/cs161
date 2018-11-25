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
    int shift = 0;                                  // Declare and initialize variable to hold encryption shift
   
    // Begin deciphering
    streamChar(alphabetArray);                      // Stream from input file
    shift = getShift(alphabetArray);                // Get the encryption shift, store in 'shift'
    writeOut("encrypted.txt", shift);               // Decipher, place deciphered text in file: 'd.txt'
    
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
    inputFile.open("encrypted.txt");
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
void writeOut(string fileName, int shift){
    
    ifstream ifile;
    ofstream ofile;

    bool shifted = false;
    int dnum;
    char letter;
    int anum;
    int difference;

    ifile.open(fileName);
    ofile.open("d.txt");
    while(ifile.peek() != EOF){
        ifile >> noskipws >> letter;                    // get letter into char
        anum = static_cast<int>(letter);                // num representation of letter
        cout << "original letter: " << anum << " - " << letter << endl;
        
        if(anum < 65 || anum > 90 && anum < 97 || anum > 122){                    
            dnum = anum;                                // Case where decrypted number is same as original
            cout << "OUT OF BOUNDS" << endl;
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
           if(shift >= 0){
                dnum = anum - shift;
                cout << "SHIFTED!!!" << endl;
                shifted = true;

                if(dnum < 65 && shifted == true){         
                    difference = 65 - dnum;
                    dnum = 91 - difference;
                }
           }
           else if(shift <= 0){
                dnum = anum - shift;
                cout << "SHIFTED!!!" << endl;
                shifted = true;

                if(dnum > 90 && shifted == true){
                    difference = dnum - 90;
                    dnum = 64 + difference;
                }
           }
        }
        
        cout << "decrypted letter: " << dnum << " - " << static_cast<char>(dnum) << endl;
        shifted = false;                                // Set shifted bit to false
        ofile << static_cast<char>(dnum);
    }
    ifile.close();
    ofile.close();
}

