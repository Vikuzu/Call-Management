#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
#include <businessContacts.h>
using namespace std;

#define success 1
#define failure 0
#define err -1

Business::Business() {
	firstName   = "";
	lastName    = "";
	phone1      = "";
	phone2      = "";
	phone3      = "";
	email1      = "";
	email2      = "";
	company     = "";
	designation = "";
	website     = "";
}

void Business::setCompany(string str) {
	company = str;
}

void Business::setDesignation(string str) {
	designation = str;
}

void Business::setWebsite(string str) {
	website = str;
}

string Business::getCompany() {
	return company;
}

string Business::getDesignation() {
	return designation;
}

string Business::getWebsite() {
	return website;
}

void Business::displayContacts()
{
	cout <<"\n\n  1. First Name      : " << firstName;
	cout <<"\n  2. Last Name       : " << lastName;
	cout <<"\n  3. Mobile Number 1 : " << phone1;
	cout <<"\n  4. Mobile Number 2 : " << phone2;
	cout <<"\n  5. Mobile Number 3 : " << phone3;
	cout <<"\n  6. Email ID 1      : " << email1;
	cout <<"\n  7. Email ID 2      : " << email2;
	cout <<"\n  8. CompanyName     : " << company;
	cout <<"\n  9. Designation     : " << designation;
	cout <<"\n  10. Website        : " << website;
}

void Business::addContact()
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
	cout<<"\nEnter the primary Phone Number: ";
		getline(cin,str);
		setPhone1(str);
	cout<<"\nEnter the primary email-id: ";
		getline(cin,str);
		setEmail1(str);
	cout<<"\nEnter the company name: ";
		getline(cin,str);
		setCompany(str);
	cout<<"\nEnter the designation: ";
		getline(cin,str);
		setDesignation(str);
	cout<<"\nEnter the website: ";
		getline(cin,str);
		setWebsite(str);
	
	while(1)
	{
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

void Business::editContact()
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
			cout << "\n\nEnter the new email-id 2: ";
			getline(cin,str);
			setEmail2(str); break;
		case 8:
			cout << "\n\nEnter the new company: ";
			getline(cin,str);
			setCompany(str); break;
		case 9:
			cout << "\n\nEnter the new designation: ";
			getline(cin,str);
			setDesignation(str); break;
		case 10:
			cout << "\n\nEnter the new website: ";
			getline(cin,str);
			setWebsite(str); break;
		}
}

Business::~Business() { }
