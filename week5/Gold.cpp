// This program investigates the Goldbach conjecture. 
// In doing so it analyzes every even integer between 4 and 1000
// inclusively, and determines which prime numbers add into the even number. 
// The output of the program shows the even number being evaluated
// and the prime pair whose sum is equal to the even number in question.
// By: Alaa Alokby
// Sources: None
// Date: 8 November 2018

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Function Headers
bool isPrime(int number);
void findPrimes(int number);
void formatOutput(int prime1, int prime2, int number);

int main(){
    cout << "Goldbach's Conjecture by Alaa Alokby" << endl;
    cout << "Number" << setw(6) << "Prime" << setw(7) << "Prime" << endl;
    for(int x = 4; x <= 1000; x = x + 2){
        findPrimes(x);
    }
    
    return 0;
}

// This function takes in one argument and determines if it is prime. It will return
// a value of True if the argument is prime, and it will return false if the argument
// is not prime. A prime number is only divisible by one, and itself.
bool isPrime(int number){

    // Divide number argument by every number up to half of its value, and find the remainder.
    // if the remainder is not zero for every number, the number is prime.
    for(int i = 3; i <= number/2; i++){
        if(number%i == 0){
            return false;
        }
    }
    return true;
}

// This function accepts one argument and prints out a set of prime numbers that add into the
// number argument. This function does not return a value.
void findPrimes(int number){
    int oldNumber = 0;
    
    // List even numbers
    for(int i = 2; i < number; i++){
        for(int j = 2; j < number; j++){
            if(isPrime(i) && isPrime(j) && i + j == number && number != oldNumber){
                formatOutput(i, j, number);
                oldNumber = number;
            }
        }
    }
   
}
// This function formats the standard output stream
void formatOutput(int prime1, int prime2, int number){
    if(number < 10){
        // All numbers are single digit
        cout << number << setw(7) << prime1 << setw(7) << prime2 << endl;
    }
    else if(number >= 10 && number < 100){
        //number is double digit
        cout << number << setw(6) << prime1 << setw(7) << prime2 << endl;
    }
    else if(number >= 100 && number < 1000){
        // Number is triple digit
        cout << number << setw(5) << prime1 << setw(7) << prime2 << endl;
    }
    else if(number > 999){
        cout << number << setw(4) << prime1 << setw(7) << prime2 << endl;
    }
}
