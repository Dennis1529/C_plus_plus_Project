// MakeReservation.h
// MakeReservation class definition.
#ifndef MAKE_RESERVATION_H
#define MAKE_RESERVATION_H

#include "Transaction.h" // Transaction class definition

class MakeReservation : public Transaction
{
public:
   MakeReservation( string userMobileNumber, ReservationDatabase &theReservationDatabase );
   virtual void execute(); // perform the transaction
private:
   Reservation newReservation; // a new reservation
}; // end class MakeReservation

#endif // MAKE_RESERVATION_H