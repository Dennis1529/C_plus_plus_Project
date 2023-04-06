#ifndef MEMBER_DATABASE_H
#define MEMBER_DATABASE_H

//#include <vector>
#include "Vector.h"
#include "Member.h" // Member class definition

class MemberDatabase
{
public:
   MemberDatabase(); // call loadFromMemberFile
   ~MemberDatabase(); // call saveToMemberFile

   // if there is no Member object containing specified mobileNumber,
   // adds a Member object containing specified mobileNumber into members
   void execute( string mobileNumber );

private:
   vector< Member > members; // Vector of the informations of all members

   void loadFromMemberFile(); // loads members from the file Members.dat
   void saveToMemberFile(); // stores members into the file Members.dat

   // returns true if there is a Member object containing specified mobileNumber
   bool exist( string userMobileNumber );
}; // end class MemberDatabase

#endif