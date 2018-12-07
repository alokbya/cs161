//Please fill in the function at the bottom of the file.  (deleteItem)
//DO NOT CHANGE ANYTHING ELSE.
//main has all the code needed to test your function.  Once your function is written, please build and make sure it works fine

#include <iostream>
#include <fstream>
using namespace std;

//constants
const int CAP = 100;

//function prototypes
bool openFile(ifstream &);
void readData(ifstream &, int [], int &);
void printData(const int [], int);
void deleteItem(int[], int &, int);


int main()
{
	ifstream inFile;
	int list[CAP], size = 0;

	if (!openFile(inFile))
	{
		cout << "Program terminating!! File not found!" << endl;
		return -1;
	}
	//read the data from the file
	readData(inFile, list, size);
	inFile.close();
	cout << "Data in file:" << endl;
	printData(list, size);
	//delete a few items
	deleteItem(list, size, 20);
	deleteItem(list, size, 210);
	deleteItem(list, size, 110);
	deleteItem(list, size, 220);
	printData(list, size);
	//end program
	cin.ignore(100, '\n');
	cout << "Press any key to continue...";
	getchar();

	return 0;
}

//function to open file
bool openFile(ifstream &inFile)
{
	inFile.open("numbers.txt");
	if (!inFile)
	{
		return false;
	}
	return true;
}

//reads the data from the file
void readData(ifstream &inFile, int list[], int &size)
{
	while (!inFile.eof())
	{
		inFile >> list[size++];
	}
}

//print the contents of the array
void printData(const int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
	cout << endl;
}


//delete an item (num) from the array
//if num is not found, display 'Item Not Found'
void deleteItem(int list[], int &size, int num)
{
    bool found = false;                           // Bit to track if num is found
    for(int i = 0; i <= size; i++)
    {                                             // Iterate through the list
        if(list[i] == num)
        {                                         // If we find the num
            found = true;                         // Set found bit to true
            for(int j = i; j <= size; j++)
            {
                list[j] = list[j+1];              // Shift the upstream elements--down
            }
            i-=1;                                 // Reduce I by one to check if same num shifted into prev. i
            size -= 1;
        }
    }
    if(found == false)
    {
        cout << "Item Not Found"  << endl;        // If nothing was found, print 'Item Not Found'
    }
   
}
