#ifndef CONTACTS_H
#define CONTACTS_H

#include <iostream>
#include <string>
using namespace std;

class Contact
{
	public:
		static int contactId;
		Contact()                    { ++contactId; }
		void setType(char t)         { type = t; }
		void setFirstname(string fn) { firstName = fn;}
		void setLastname(string ln)  { lastName = ln;} 
		void setPhone1(string ph1)   { phone1 = ph1; }
		void setPhone2(string ph2)   { phone2 = ph2; }
		void setPhone3(string ph3)   { phone3 = ph3; }
		void setEmail1(string em1)   { email1 = em1; }
		void setEmail2(string em2)   { email2 = em2; }

		int getContactid()    { return contactId; }
		char getType()        { return type; }
		string getFirstname() { return firstName; }
		string getLastname()  { return lastName; }
		string getPhone1()    { return phone1; }
		string getPhone2()    { return phone2; }
		string getPhone3()    { return phone3; }
		string getEmail1()    { return email1; }
		string getEmail2()    { return email2; }
	
	protected:
		char type;
		string firstName;
		string lastName;
		string phone1;
		string phone2;
		string phone3;
		string email1;
		string email2;
};

#endif
