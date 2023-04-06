// Transaction.h
// Transaction abstract base class definition.
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "ReservationDatabase.h" // ReservationDatabase class definition

class Transaction
{
public:
   // constructor initializes common features of all Transactions
   Transaction( string userMobileNumber, ReservationDatabase &theReservationDatabase );

   virtual ~Transaction() // virtual destructor with empty body
   {
   }

   string getMobileNumber(); // returns mobile number

   // returns reference to reservationDatabase
   ReservationDatabase &getReservationDatabase();

   // input an integer in the range [ begin, end ]
   int inputAnInteger( int begin, int end );

   // pure virtual function to perform the transaction
   virtual void execute() = 0; // overridden in derived classes
private:
   string mobileNumber;
   ReservationDatabase &reservationDatabase;
}; // end class Transaction

#endif // TRANSACTION_H