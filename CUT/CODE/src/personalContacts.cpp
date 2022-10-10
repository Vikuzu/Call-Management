#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

#include "../header/personalContacts.h"

#define success 1
#define failure 0
#define err -1

Personal::Personal() {
	firstName   = "";
	lastName    = "";
	phone1      = "";
	phone2      = "";
	phone3      = "";
	email1      = "";
	email2      = "";
	address     = "";
	wPhone      = "";
	birthDate   = "";
	emergencyCt = "";
}

void Personal::setAddress(string str) {
	address = str;
}

void Personal::setWhatsappphone(string str) {
	wPhone = str;
}

void Personal::setBirthdate(string str) {
	birthDate = str;
}

void Personal::setEmergencycontact(string str) {
	emergencyCt = str;
}

string Personal::getAddress() {
	return address;
}

string Personal::getWhatsAppphone() {
	return wPhone;
}

string Personal::getBirthdate() {
	return birthDate;
}

string Personal::getEmergencycontact() {
	return emergencyCt;
}

void Personal::displayContacts()
{
	cout << "\n\n  1. First Name         : " << firstName;
	cout << "\n  2. Last Name          : " << lastName;
	cout << "\n  3. Phone Number 1     : " << phone1;
	cout << "\n  4. Phone Number 2     : " << phone2;
	cout << "\n  5. Phone Number 3     : " << phone3;
	cout << "\n  6. Email-ID 1         : " << email1;
	cout << "\n  7. Email-ID 2         : " << email2;
	cout << "\n  8. Address            : " << address;
	cout << "\n  9. WhatsApp Number    : " << wPhone;
	cout << "\n  10. Birth Date        : " << birthDate;
	cout << "\n  11. Emergency Contact : " << emergencyCt;
}

void Personal::addContact()
{
	system("clear");
	
	string str;
	char choice;
	
	cout<<"\nEnter the first name: ";
		getline(cin,str);
		setFirstname(str);
	cout<<"\nEnter the last name: ";
		getline(cin,str);
		setLastname(str);
	cout<<"\nEnter the primary phone number: ";
		getline(cin,str);
		setPhone1(str);
	cout<<"\nEnter the primary email-id: ";
		getline(cin,str);
		setEmail1(str);
	cout<<"\nEnter the address: ";
		getline(cin,str);
		setAddress(str);
	cout<<"\nEnter the whatsApp number: ";
		getline(cin, str);
		setWhatsappphone(str);
	cout<<"\nEnter the birthdate (DD/MM/YYYY): ";
		getline(cin,str);
		setBirthdate(str);
	cout<<"\nEmergency contact? (Yes/No): ";
		getline(cin,str);
		setEmergencycontact(str);

	while(1){
		cout <<"\n\nDo you want to add secondary details (y/n)? ";
		cin >> choice;
		if(choice == 'y')
		{
			system("clear");
			editContact();
		}		
		else 
			break;
	}
}


void Personal::editContact()
{
	string str;
	int choice;

	displayContacts();

	cout<<"\n\n  Choose an option: ";
	cin>>choice;
	getchar();
	
	switch(choice)
	{
		case 1:
			cout << "\n\nEnter the new first name: ";
			getline(cin,str);
			setFirstname(str); break;
		case 2:
			cout << "\n\nEnter the new last name: ";
			getline(cin,str);
			setLastname(str); break;
		case 3:
			cout << "\n\nEnter the new phone number 1: ";
			getline(cin,str);
			setPhone1(str); break;
		case 4:
			cout << "\n\nEnter the new phone number 2: ";
			getline(cin,str);
			setPhone2(str); break;
		case 5:
			cout << "\n\nEnter the new phone number 3: ";
			getline(cin,str);
			setPhone3(str); break;
		case 6:
			cout << "\n\nEnter the new email-id 1: ";
			getline(cin,str);
			setEmail1(str); break;
		case 7:
			cout << "\n\nEnter the new emai-id 2: ";
			getline(cin,str);
			setEmail2(str); break;
		case 8:
			cout << "\n\nEnter the new address: ";
			getline(cin,str);
			setAddress(str); break;
		case 9:
			cout << "\n\nEnter the new whatsapp phone number: ";
			getline(cin,str);
			setWhatsappphone(str); break;
		case 10:
			cout << "\n\nEnter the new birthdate: ";
			getline(cin,str);
			setBirthdate(str); break;
		case 11:
			cout << "\n\nEmergency contact (Yes/No): ";
			getline(cin,str);
			setEmergencycontact(str); break;
	}
		
}

Personal::~Personal() { }
