#include <iostream>
#include <iomanip>
using namespace::std;
#include "Reservation.h" // Reservation class definition

Reservation::Reservation( string theMobileNumber, string theName, string theDate,
                          int theTime, string theEmail, int theCustomerNumber )
{
   setMobileNumber(theMobileNumber);
   setName(theName);
   setDate(theDate);
   setTime(theTime);
   setEmail(theEmail);
   setCustomerNumber(theCustomerNumber);
}

void Reservation::setMobileNumber( string theMobileNumber )
{
   unsigned int length = theMobileNumber.size();
   length = ( length < 12 ? length : 11 );
   for( unsigned int i = 0; i < length; i++ )
      mobileNumber[ i ] = theMobileNumber[ i ];
   mobileNumber[ length ] = '\0';
}

void Reservation::setName( string theName )
{
   unsigned int length = theName.size();
   length = ( length < 8 ? length : 7 );
   for( unsigned int i = 0; i < length; i++ )
      name[ i ] = theName[ i ];
   name[ length ] = '\0';
}

void Reservation::setDate( string theDate )
{
   unsigned int length = theDate.size();
   length = ( length < 12 ? length : 11 );
   for( unsigned int i = 0; i < length; i++ )
      date[ i ] = theDate[ i ];
   date[ length ] = '\0';
}

void Reservation::setTime( int theTime )
{
   time = ( theTime >= 0 ? theTime : 0 );
}

void Reservation::setEmail( string theEmail )
{
   unsigned int length = theEmail.size();
   length = ( length < 40 ? length : 39 );
   for( unsigned int i = 0; i < length; i++ )
      email[ i ] = theEmail[ i ];
   email[ length ] = '\0';
}

void Reservation::setCustomerNumber( int theCustomerNumber )
{
   customerNumber = ( theCustomerNumber >= 0 ? theCustomerNumber : 0 );
}

string Reservation::getMobileNumber()
{
   return mobileNumber;
}

string Reservation::getName()
{
   return name;
}

string Reservation::getDate()
{
   return date;
}

int Reservation::getTime()
{
   return time;
}

string Reservation::getEmail()
{
   return email;
}

int Reservation::getCustomerNumber()
{
   return customerNumber;
}

void Reservation::displayReservationInfo()
{
   char times[ 6 ][ 12 ] = { "", "11:30 AM", "12:00 PM", "2:30 PM", "5:30 PM", "6:00 PM" };
   cout << setw( 14 ) << mobileNumber << setw( 10 ) << name << setw( 14 ) << date
        << setw( 10 ) << times[ time ] << setw( 40 ) << email << setw( 19 ) << customerNumber << endl;
}

void Reservation::displayReservationInfo1()
{
   char times[ 6 ][ 12 ] = { "", "11:30 AM", "12:00 PM", "2:30 PM", "5:30 PM", "6:00 PM" };
   cout << "\n1. Date            " << date
        << "\n2. Time            " << times[ time ]
        << "\n3. No of Customers " << customerNumber << endl;
}