#include <iostream>
using namespace::std;
#include "MemberDatabase.h" // MemberDatabase class definition
#include "MakeReservation.h" // MakeReservation class definition
#include "ModifyCancel.h" // ModifyCancel class definition

void displayMainMenu();
int inputAnInteger(int begin, int end); // input an integer in the range [ begin, end ]

int main()
{
	cout << "Welcome to Hi-Lai Harbour Taoyuan Location!\n\n";

	cout << "Please enter your mobile number: ";
	string mobileNumber; // current user's mobile number
	cin >> mobileNumber; // input mobile number
	cin.ignore();

	MemberDatabase memberDatabase; // member information database
	memberDatabase.execute(mobileNumber);

	ReservationDatabase reservationDatabase; // reservation information database

											 // enumeration constants represent main menu options
	enum MenuOption { Book_A_Table = 1, My_Bookings, EXIT };

	// local pointer to store transaction currently being processed
	Transaction *currentTransactionPtr;

	bool userExited = false; // user has not chosen to exit

							 // loop while user has not chosen option to exit system
	while (!userExited)
	{
		displayMainMenu(); // show main menu and get user selection
		int mainMenuSelection = inputAnInteger(1, 3);

		// decide how to proceed based on user's menu selection
		switch (mainMenuSelection)
		{
		case Book_A_Table:
			currentTransactionPtr = new MakeReservation(mobileNumber, reservationDatabase);
			currentTransactionPtr->execute(); // execute transaction        
			delete currentTransactionPtr; // free the space for the dynamically allocated Transaction
			break;
		case My_Bookings:
			currentTransactionPtr = new ModifyCancel(mobileNumber, reservationDatabase);
			currentTransactionPtr->execute(); // execute transaction        
			delete currentTransactionPtr; // free the space for the dynamically allocated Transaction
			break;
		case EXIT: // user chose to terminate session
			userExited = true; // this session should end
			cout << endl;
			break;
		default: // user did not enter an integer from 1-3
			cout << "\nIncorrect choice!" << endl;
		} // end switch
	} // end while

	system("pause");
}

// display the main menu
void displayMainMenu()
{
	cout << "\n1 - Book a Table\n";
	cout << "2 - My Bookings\n";
	cout << "3 - End\n\n";
	cout << "Enter your choice: (1~3): ";
} // end function displayMainMenu

int inputAnInteger(int begin, int end)
{
	char string[80];

	do {
		cin.getline(string, 80, '\n');
		int number = atoi(string);
		if (number >= begin && number <= end)
			return number;
		else
			cout << "\nOut of range! Please try again: ";

	} while (true);
}