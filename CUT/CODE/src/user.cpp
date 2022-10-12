#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#include "../header/user.h"
#define success 1
#define failure 0
#define err -1
extern string PROJECTDIR;
int Contact::contactId = 0;
void User::loadUserdatabase1() 
{
	string str, username , password;
	string file = PROJECTDIR + "data/users.txt";
	ifstream f;
	try {
		f.open(file);
		if(!f.is_open())
			throw err;
	} catch(int e) {
		cout<<"\n\tError in opening file to read..."; return;
	}
	while(getline(f,str)) {
		stringstream ss(str);
		getline(ss, username, ':');
		getline(ss, password, ':');
		umap.insert({username, password});
	}
}
int User::checkDate(string date)
{
	string day, month, year;
	stringstream ss(date);
	getline(ss, day, '/');
	getline(ss, month, '/');
	getline(ss, year, '/');
	int dd = stoi(day);
	int mm = stoi(month);
	int yy = stoi(year);
	if(yy >= 2000) {
		if(mm >= 1 && mm <=12) {
			if(mm <= 7 && mm != 2) {
				if(mm % 2 == 1)
					if(dd >= 1 && dd <= 31)
						return success;
					else
						return failure;
				else
					if(dd >= 1 && dd <= 30)
						return success;
					else
						return failure;
			}
			else if(mm > 7) {
				if(mm % 2 == 1)
					if(dd >= 1 && dd <= 30)
						return success;
					else
						return failure;
				else
					if(dd >= 1 && dd <= 31)
						return success;
					else
						return failure;
			}
			else 
			{
				if ((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0))
					if(dd >= 1 && dd <= 29)
						return success;
					else
						return failure;
				else
					if(dd >= 1 && dd <= 28)
						return success;
					else
						return failure;
			}
		}
		else
			return failure;
	}
	else
		return failure;
}
int User::checkContact(string str)
{
	string type, fname, lname, ph1, ph2, ph3, em1, em2, add, wph, bdate, ect, com, des, web;
	int id;
	stringstream ss(str);
	getline(ss, type, ':');
	if(type.compare("p") == 0) {
		int ret = 0;
		getline(ss, fname, '|');
		getline(ss, lname, '|');
		getline(ss, ph1, '|');
		getline(ss, ph2, '|');
		getline(ss, ph3, '|');
		getline(ss, em1, '|');
		getline(ss, em2,'|');
		getline(ss, add, '|');
		getline(ss, wph, '|');
		getline(ss, bdate, '|');
		if(bdate != "")
			ret = checkDate(bdate);
		getline(ss, ect, '|');		
		if(fname != "" && ph1 != "" && em1 != "" && add != "" && wph != "" && ret == 1) {
			Personal p;
			p.setFirstname(fname);
			p.setLastname(lname);
			p.setPhone1(ph1);
			p.setPhone2(ph2);
			p.setPhone3(ph3);
			p.setEmail1(em1);
			p.setEmail2(em2);
			p.setAddress(add);
			p.setWhatsappphone(wph);
			p.setBirthdate(bdate);
			p.setEmergencycontact(ect);	
			id = p.getContactid();
			pmap.insert({id, p});
		}
		else 
			return failure;
	}	
	if(type.compare("b") == 0)  {
		getline(ss, fname, '|');
		getline(ss, lname, '|');
		getline(ss, ph1, '|');
		getline(ss, ph2, '|');
		getline(ss, ph3, '|');
		getline(ss, em1, '|');
		getline(ss, em2,'|');
		getline(ss, com, '|');
		getline(ss, des, '|');
		getline(ss, web, '|');			
		if(fname != "" && ph1 != "" && em1 != "" && com != "" && des != "" && web != "") {
			Business b;
			b.setFirstname(fname);
			b.setLastname(lname);
			b.setPhone1(ph1);
			b.setPhone2(ph2);
			b.setPhone3(ph3);
			b.setEmail1(em1);
			b.setEmail2(em2);
			b.setCompany(com);
			b.setDesignation(des);
			b.setWebsite(web);	
			id = b.getContactid();
			bmap.insert({id, b});
		}
		else 
			return failure;
	}
	return success;
}
void User::loadContactdatabase(string username)
{
	string file = PROJECTDIR + "data/" + username + "/contacts.txt";
	ifstream fr;
	try {
		fr.open(file);
		if(!fr.is_open())
			throw err;
	} catch(int e) {
		char dir[100];
		strcpy(dir,"mkdir -p ../data/");
		system(strcat(dir, username.c_str())); return;
	}
	ofstream fw;
	try {
		fw.open(PROJECTDIR + "reports/InvalidContacts.txt");
		if(!fw.is_open())
			throw err;
	} catch(int e) {
		cout<<"\n\tError in opening file to write..."; return;
	}
	string str; int ret;
	while(getline(fr,str)) {
		ret= checkContact(str);
		if (ret == 0)
			fw << str;
	}
}
void User::changePassword(string username)
{
	system("clear");
    	string password;
	if(umap.find(username) != umap.end()) {
		cout<<"\nEnter the new password: ";
		getline(cin, password);
		umap[username] = password;
	}
	cout << "\n\nPress enter key to return: "; getchar();
}
void User::addContact()
{
	system("clear");
	int choice, id;
    	cout << "\n  1. add personal contact";
	cout << "\n  2. add business contact";					
	cout << "\n\n  Choose an option: ";
	cin>>choice; getchar();
	switch(choice) {
		case 1: {
		    	system("clear");
			Personal p; p.addContact();
			id = p.getContactid();
			pmap.insert({id, p}); return;
		}
		case 2: {
			system("clear");
			Business b; b.addContact();
			id = b.getContactid();
			bmap.insert({id, b}); return;
			}
		}
}
void User::updateContact()
{
	system("clear");
	int id;
	cout<<"\n\nEnter the contactid: ";
	cin >> id; getchar();
	if(pmap.find(id) != pmap.end())
		pmap[id].editContact();
	else if(bmap.find(id) != bmap.end())
		bmap[id].editContact();
	else
		cout<<"\n\n\tContactid " <<  id <<" not found...";
	cout << "\n\nPress enter key to return: "; getchar();
}
void User::deleteContact()
{
	system("clear");
	int id;
	cout<<"\n\nEnter the contactid: ";
	cin >> id; getchar();
	if(pmap.find(id) != pmap.end())
		pmap.erase(id);
	else if(bmap.find(id) != bmap.end())
		bmap.erase(id);
	else
		cout<<"\n\n\tContactid " <<  id <<" not found...";
	cout << "\n\nPress enter key to return: "; getchar();
}
void User::listPersonalcontacts()
{
	system("clear");
	map<int, Personal>::iterator itp;	
	for(itp = pmap.begin(); itp != pmap.end(); ++itp)			
		cout << "\n\n" << itp->first << " | " << itp->second.getFirstname() << " | " << itp->second.getLastname() << " | " << itp->second.getPhone1() << " | " << itp->second.getPhone2() << " | "  << itp->second.getPhone3() << " | " << itp->second.getEmail1() << " | " << itp->second.getEmail2() << " | "  << itp->second.getAddress() << " | " << itp->second.getWhatsAppphone() << " | " << itp->second.getBirthdate() << " | " << itp->second.getEmergencycontact();
	cout << "\n\nPress enter key to return: "; getchar();
}
void User::listBusinesscontacts()
{
	system("clear");
	map<int, Business>::iterator itb;	
	for(itb = bmap.begin(); itb != bmap.end(); ++itb)			
		cout << "\n\n" << itb->first << " | " << itb->second.getFirstname() << " | " << itb->second.getLastname() << " | " << itb->second.getPhone1() << " | " << itb->second.getPhone2() << " | "  << itb->second.getPhone3() << " | " << itb->second.getEmail1() << " | " << itb->second.getEmail2() << " | "  << itb->second.getCompany() << " | " << itb->second.getDesignation() << " | " << itb->second.getWebsite();
	cout << "\n\nPress enter key to return: "; getchar();
}
void User::userLogout(string username)
{
	string ufile = PROJECTDIR + "data/users.txt";
	ofstream fu;
	try {
		fu.open(ufile);
		if(!fu.is_open())
			throw err;
	} catch(int e) {
		cout<<"\n\n\tError in opening the file to write..."; return;
	}
	string cfile = PROJECTDIR + "data/" + username + "/contacts.txt";
	ofstream fc;
	try {
		fc.open(cfile);
		if(!fc.is_open())
			throw err;
	} catch(int e){
		cout<<"\n\n\tError in opening file to write..."; return ;
	}
	map<string, string> :: iterator itu;
	map<int, Personal>::iterator itp;	
	map<int, Business>::iterator itb;	
	for(itu = umap.begin(); itu != umap.end(); ++itu)
		fu << itu->first << ":" << itu->second << "\n";
	umap.clear();
	for(itp = pmap.begin(); itp != pmap.end(); ++itp) {			
		fc << "p:" << itp->second.getFirstname() << "|" << itp->second.getLastname() << "|" << itp->second.getPhone1() << "|" << itp->second.getPhone2() << "|"  << itp->second.getPhone3() << "|" << itp->second.getEmail1() << "|" << itp->second.getEmail2() << "|"  << itp->second.getAddress() << "|" << itp->second.getWhatsAppphone() << "|" << itp->second.getBirthdate() << "|" << itp->second.getEmergencycontact() <<"\n";
	} pmap.clear();
	for(itb = bmap.begin(); itb != bmap.end(); ++itb) {			
		fc << "b:" << itb->second.getFirstname() << "|" << itb->second.getLastname() << "|" << itb->second.getPhone1() << "|" << itb->second.getPhone2() << "|"  << itb->second.getPhone3() << "|" << itb->second.getEmail1() << "|" << itb->second.getEmail2() << "|"  << itb->second.getCompany() << "|" << itb->second.getDesignation() << "|" << itb->second.getWebsite() << "\n";
	} bmap.clear();
	Contact::contactId = 0;
}
