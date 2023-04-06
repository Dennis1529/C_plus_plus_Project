// Transaction.cpp
// Member-function definitions for class Transaction.
#include <iostream>
using namespace::std;
#include "Transaction.h" // Transaction class definition

// constructor initializes common features of all Transactions
Transaction::Transaction( string userMobileNumber,
                          ReservationDatabase &theReservationDatabase )
   : mobileNumber( userMobileNumber ),
     reservationDatabase( theReservationDatabase )
{
}

string Transaction::getMobileNumber()
{
   return mobileNumber;
}

ReservationDatabase &Transaction::getReservationDatabase()
{
   return reservationDatabase;
}

int Transaction::inputAnInteger( int begin, int end )
{
   char string[ 80 ];

   do
   {
      cin.getline(string,80,'\n');
      int number = atoi( string );
      if( number >= begin && number <= end )
         return number;
      else
         cout << "\nOut of range! Please try again: ";

   } while( true );
}