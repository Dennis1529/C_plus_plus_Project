#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace::std;
#include "ReservationDatabase.h" // ReservationDatabase class definition

// ReservationDatabase default constructor
ReservationDatabase::ReservationDatabase()
{
   loadReservations();
}

// ReservationDatabase destructor
ReservationDatabase::~ReservationDatabase()
{
   storeReservations();
}

bool ReservationDatabase::empty()
{
   return ( reservations.size() == 0 );
}

void ReservationDatabase::cancelReservation( vector< Reservation >::iterator it )
{
   reservations.erase( it );
}

void ReservationDatabase::pushBack( Reservation newReservation )
{
   reservations.push_back( newReservation );
}

int ReservationDatabase::inputAnInteger( int begin, int end )
{
   char string[ 80 ];

   do
   {
      cin.getline( string, 80, '\n' );
      int number = atoi( string );
      if( number >= begin && number <= end )
         return number;
      else
         cout << "\nOut of range! Please try again: ";

   } while( true );
}
// returns an iterator that points to the n-th Reservation object
// containing specified mobileNumber
vector< Reservation >::iterator ReservationDatabase::searchReservation(string mobileNumber, int n)
{
	int i=0,j=0;
	vector<Reservation>::iterator it1 = reservations.begin();
	vector<Reservation>::iterator it2 = reservations.end();
	for (; it1 != it2; ++it1)
	{
		if (it1->getMobileNumber() == mobileNumber)
		{
			i++;
			if (i == n)
			{
				return it1;
			}
		}
	}
	it1 = NULL;
	return it1;
}

// returns true if there is a Reservation object containing specified mobileNumber
bool ReservationDatabase::exist(string mobileNumber)
{
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].getMobileNumber() == mobileNumber)
			return true;
	}return false;
}

// returns true if there is a Reservation object containing specified
// mobileNumber and date
bool ReservationDatabase::exist(string mobileNumber, string date)
{
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].getMobileNumber() == mobileNumber)
		{
			if(reservations[i].getDate() == date)
				return true;
		}
	}return false;
}

// displays all reservation informations for the Members object containing specified mobileNumber, and
// returns the number of reservation informations displayed
int ReservationDatabase::displayReservationInfo(string mobileNumber)
{
	int j=0;
	cout << setw(14) << "Mobile Number" << setw(10) << "Name" << setw(14) << "Date" << setw(10)
		<< "Time"<< setw(40) << "Email"<< setw(19) << "No of Customers" << endl;
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations[i].getMobileNumber() == mobileNumber)
		{
			j++;
			cout << j<<".";
			reservations[i].displayReservationInfo();
		}
	}return j;
}

// modifies the Reservation object pointed by it
void ReservationDatabase::modifyReservation(vector< Reservation >::iterator it, string mobileNumber)
{		
	string tmp;
	int choice;
	it->displayReservationInfo1();
	cout << "Enter your choice (0 to end): ";
	choice = inputAnInteger(0, 3);
	if (choice > 0)
	{
		switch (choice)
		{
			case 1:
			{
				cout << "Enter date (yyyy-mm-dd): ";
				cin >> tmp;
				if (exist(mobileNumber, tmp))
				{
					cout << "You have already booked a table on " << tmp << "!" << endl;
					break;
				}
				else
				{
					it->setDate(tmp);
					break;
				}
			}
			case 2:
			{
				int t;
				cout << "\n1. 11:30 AM\n"
					<< "2. 12:00 PM\n"
					<< "3.  2:30 PM\n"
					<< "4.  5:30 PM\n"
					<< "5.  6:00 PM\n";
				cout << "Enter your choice: ";
				t = inputAnInteger(1, 5);
				it->setTime(t);
				break;
			}
			case 3:
			{
				int num;
				cout << "Enter the number of customers (1~15): " << endl;
				num = inputAnInteger(1, 15);
				it->setCustomerNumber(num);
			}
		}
	}
}
void ReservationDatabase::loadReservations() // loads reservations from the file Reservations.dat
{
	Reservation load;
	fstream File("Reservations.dat", ios::in | ios::out | ios::binary);
	if (!File)
	{
		File.close();
		ofstream inFile("Reservations.dat", ios::in | ios::binary);
		inFile.close();
	}
	File.seekg(0, ios::end);
	if (static_cast<int>(File.tellg()) != 0)
	{
		File.seekg(0, ios::beg);
		while (File.read(reinterpret_cast<char*>(&load), sizeof(Reservation)))
		{		
			reservations.push_back(load);
		}
	}
	File.close();
}
void ReservationDatabase::storeReservations() // stores reservations into the file Reservations.dat
{
	fstream File("Reservations.dat", ios::in | ios::out | ios::binary);
	if (!File)
	{
		File.close();
		ofstream inFile("Reservations.dat", ios::in | ios::binary);
		inFile.close();
	}
	File.seekg(0, ios::beg);
	for (int i = 0; i < reservations.size(); i++)
	{
		File.write(reinterpret_cast<char*>(&reservations[i]), sizeof(Reservation));
	}
	File.close();
}