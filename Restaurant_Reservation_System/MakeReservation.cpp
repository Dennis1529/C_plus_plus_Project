// MakeReservation.cpp
// Member-function definitions for class MakeReservation.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "MakeReservation.h"     // MakeReservation class definition

// MakeReservation constructor initializes base-class data members
MakeReservation::MakeReservation( string userMobileNumber,
                                  ReservationDatabase &theReservationDatabase )
   : Transaction( userMobileNumber, theReservationDatabase )
{
}
void MakeReservation::execute()
{
	string tmp;
	newReservation.setMobileNumber(getMobileNumber());
	cout << "Enter date (yyyy-mm-dd): ";
	cin >> tmp;
	if (getReservationDatabase().exist(getMobileNumber(),tmp))
	{
		cout << "You have already booked a table on " << tmp <<"!"<< endl;
		return;
	}
	else
	{
		newReservation.setDate(tmp);
	}
	cout << "\n1. 11:30 AM\n"
		<< "2. 12:00 PM\n"
		<< "3.  2:30 PM\n"
		<< "4.  5:30 PM\n"
		<< "5.  6:00 PM\n";
	cout << "Enter your choice: ";
	int choice = inputAnInteger(1, 5);
	newReservation.setTime(choice);
	cout << "Enter name: ";
	cin >> tmp;
	newReservation.setName(tmp);
	cout << "Enter email: ";
	cin >> tmp;
	newReservation.setEmail(tmp);
	cout << "Enter the number of customers (1~15): ";
	choice = inputAnInteger(1, 15);
	newReservation.setCustomerNumber(choice);
	getReservationDatabase().pushBack(newReservation);
	cout << "Reservation Completed!" << endl;
}