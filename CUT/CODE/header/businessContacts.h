#ifndef BUSINESSCONTACTS_H
#define BUSINESSCONTACTS_H

#include <iostream>
#include <string>
using namespace std;

#include "../header/contacts.h"

class Business : public Contact
{
	protected:
		string company;
		string designation;
		string website;
	public:
		Business();
		void setCompany(string );
		void setDesignation(string );
		void setWebsite(string );
		string getCompany();
		string getDesignation();
		string getWebsite();
		void addContact();
		void editContact();
		void displayContacts();
		~Business();
};

#endif
