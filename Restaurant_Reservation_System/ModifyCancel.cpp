#include <iostream>
#include<string>
using namespace::std;
#include "ModifyCancel.h"

ModifyCancel::ModifyCancel( string userMobileNumber,
                            ReservationDatabase &theReservationDatabase )
   : Transaction( userMobileNumber, theReservationDatabase )
{
}

void ModifyCancel::execute()
{
   ReservationDatabase &reservationDatabase = getReservationDatabase();

   if( reservationDatabase.empty() )
   {
      cout << "\nNo reservations!\n";
      return;
   }

   if( !reservationDatabase.exist( getMobileNumber() ) )
   {
      cout << "\nYou have no reservations!\n";
      return;
   }

   int numReservations = reservationDatabase.displayReservationInfo( getMobileNumber() );
   //cout << numReservations << endl;

   cout << "\nChoose a reservation (0 to end): ";
   int reservationNumber = inputAnInteger( 0, numReservations );

   if( reservationNumber > 0 )
   {
      vector< Reservation >::iterator it = reservationDatabase.searchReservation( getMobileNumber(), reservationNumber );
      performTransactions( it );
   }      
}

// display the submenu and return an input selection
void ModifyCancel::displaySubMenu()
{
   cout << "\n1 - Modify Booking\n";
   cout << "2 - Cancel Booking\n";
   cout << "3 - End\n\n";
   cout << "Enter your choice: (1~3): ";
} // end function displaySubMenu
void ModifyCancel::performTransactions(vector< Reservation >::iterator it) // performs the transaction
{
	if (it == NULL)
	{
		cout << "This reservation is not exist please try again!" << endl;
		return;
	}
	else
	{
		bool exit=false,check=false;
		int choice;
		string tmp;
		while (!exit)
		{
			displaySubMenu();
			choice = inputAnInteger(1, 3);
			switch(choice)
			{
				case 1:
				{
					if(check)
						cout << "This reservations is not exist" << endl;
					else
						getReservationDatabase().modifyReservation(it,getMobileNumber());
					break;
				}
				case 2:
				{
					if(check)
						cout << "This reservations is not exist" << endl;
					else
					{
						getReservationDatabase().cancelReservation(it);
						check = true;
					}
					break;
				}
				case 3:
				{
					exit = true;
					break;
				}
			}
		}
	}
}