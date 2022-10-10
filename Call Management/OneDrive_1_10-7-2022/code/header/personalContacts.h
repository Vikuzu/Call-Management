#ifndef PERSONALCONTACTS_H
#define PERSONALCONTACTS_H

#include <iostream>
#include <string>
using namespace std;

#include "../header/contacts.h"

class Personal : public Contact
{
	protected:
		string address;
		string wPhone;
		string birthDate;
		string emergencyCt;
		
	public:
		Personal();
		void setAddress(string );
		void setWhatsappphone(string );
		void setBirthdate(string );
		void setEmergencycontact(string );
		string getAddress();
		string getWhatsAppphone();
		string getBirthdate();
		string getEmergencycontact();
		void addContact();
		void editContact();
		void displayContacts();
		~Personal();
};

#endif
