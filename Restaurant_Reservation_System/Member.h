#ifndef MEMBERINFO_H
#define MEMBERINFO_H

#include <string>
using std::string;

class Member
{
public:
   Member( string theMobileNumber = "" );

   void setMobileNumber( string theMobileNumber );
   string getMobileNumber();

private:
   char mobileNumber[ 12 ];      // mobile number
};

#endif