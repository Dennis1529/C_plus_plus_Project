#include <iostream>
#include <fstream>
using namespace::std;
#include "MemberDatabase.h" // MemberDatabase class definition

// MemberDatabase default constructor
MemberDatabase::MemberDatabase()
{
   loadFromMemberFile();
}

// MemberDatabase destructor
MemberDatabase::~MemberDatabase()
{
   saveToMemberFile();
}

void MemberDatabase::execute( string mobileNumber )
{
   if( !exist( mobileNumber ) )
   {
      Member newMember( mobileNumber );
      members.push_back( newMember );
   }
}
void MemberDatabase::loadFromMemberFile() // loads members from the file Members.dat
{
	Member load;
	fstream File("Members.dat", ios::in | ios::out | ios::binary);
	if (!File)
	{
		File.close();
		ofstream inFile("Members.dat", ios::in | ios::binary);
		inFile.close();
	}
	File.seekg(0, ios::end);
	if (static_cast<int>(File.tellg()) != 0)
	{
		File.seekg(0, ios::beg);
		while (File.read(reinterpret_cast<char*>(&load), sizeof(Member)))
		{		
			members.push_back(load);
		}
	}
	File.close();
}
void MemberDatabase::saveToMemberFile() // stores members into the file Members.dat
{
	fstream File("Members.dat", ios::in | ios::out | ios::binary);
	if (!File)
	{
		File.close();
		ofstream inFile("Members.dat", ios::in | ios::binary);
		inFile.close();
	}
	File.seekg(0, ios::beg);
	for (int i = 0; i < members.size(); i++)
	{
		File.write(reinterpret_cast<char*>(&members[i]), sizeof(Member));
	}
	File.close();
}

// returns true if there is a Member object containing specified mobileNumber
bool MemberDatabase::exist(string userMobileNumber)
{
	for (int i = 0; i < members.size(); i++)
	{
		if (userMobileNumber == members[i].getMobileNumber())
			return true;
	}return false;
}