// ModifyCancel.h
// ModifyCancel class definition.
#ifndef MODIFY_CANCEL_H
#define MODIFY_CANCEL_H

#include "Transaction.h" // Transaction class definition

class ModifyCancel : public Transaction
{
public:
   ModifyCancel( string userMobileNumber, ReservationDatabase &theReservationDatabase );
   virtual void execute(); // perform the transaction
private:
   void performTransactions( vector< Reservation >::iterator it ); // performs the transaction
   void displaySubMenu(); // displays sub menu
}; // end class ModifyCancel

#endif // VIEW_CANCEL_RESERVATION_H