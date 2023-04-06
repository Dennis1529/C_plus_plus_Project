#ifndef RESERVATION_DATABASE_H
#define RESERVATION_DATABASE_H

//#include <vector>
#include "Vector.h"
#include "Reservation.h" // Reservation class definition

class ReservationDatabase
{
public:
   ReservationDatabase(); // call loadFromReservationFile
   ~ReservationDatabase(); // call saveToReservationFile

   bool empty(); // returns true if the ReservationDatabase is empty

   // returns an iterator that points to the n-th Reservation object
   // containing specified mobileNumber
   vector< Reservation >::iterator searchReservation( string mobileNumber, int n );

   // returns true if there is a Reservation object containing specified mobileNumber
   bool exist( string mobileNumber );

   // returns true if there is a Reservation object containing specified
   // mobileNumber and date
   bool exist( string mobileNumber, string date );

   // displays all reservation informations for the Members object containing specified mobileNumber, and
   // returns the number of reservation informations displayed
   int displayReservationInfo( string mobileNumber );

   // modifies the Reservation object pointed by it
   void modifyReservation( vector< Reservation >::iterator it, string mobileNumber );

   // cancels the Reservation object pointed by it
   void cancelReservation( vector< Reservation >::iterator it );

   void pushBack( Reservation newReservation ); // add an element at the end of reservations

private:
   vector< Reservation > reservations; // vector of all reservations

   void loadReservations(); // loads reservations from the file Reservations.dat
   void storeReservations(); // stores reservations into the file Reservations.dat
   int inputAnInteger( int begin, int end ); // input an integer in the range [ begin, end ]
}; // end class ReservationDatabase

#endif