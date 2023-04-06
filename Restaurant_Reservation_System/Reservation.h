// Reservation.h
// Reservation class definition. Represents a reservation.
#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation
{
public:
   Reservation( string theMobileNumber = "", string theName = "", string theDate = "",
                int theTime = 0, string theEmail = "", int theCustomerNumber = 0 );

   void setMobileNumber( string theMobileNumber );
   void setName( string theName );
   void setDate( string theDate );
   void setTime( int theTime );
   void setEmail( string theEmail );
   void setCustomerNumber( int theCustomerNumber );

   string getMobileNumber();
   string getName();
   string getDate();
   int getTime();
   string getEmail();
   int getCustomerNumber();

   // displays mobileNumber, name, date, time, email, customerNumber
   void displayReservationInfo();

   // displays 1: date
   //          2: time
   //          3: customerNumber
   void displayReservationInfo1();

private:
   char mobileNumber[ 12 ]; // �q�ܸ��X
   char name[ 8 ];          // �m�W
   char date[ 12 ];         // �w�����
   int time;                // �w���ɶ��G
   char email[ 40 ];        // �q�l�a�}
   int customerNumber;      // ���O�H��
};

#endif