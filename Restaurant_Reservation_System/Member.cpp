// Member-function definitions for class Member.
#include "Member.h" // Member class definition

Member::Member( string theMobileNumber )
{
   setMobileNumber( theMobileNumber );
}

void Member::setMobileNumber( string theMobileNumber )
{
   unsigned int length = theMobileNumber.size();
   length = ( length < 12 ? length : 11 );
   for( unsigned int i = 0; i < length; i++ )
      mobileNumber[ i ] = theMobileNumber[ i ];
   mobileNumber[ length ] = '\0';
}

string Member::getMobileNumber()
{
   return mobileNumber;
}