#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

#include "../header/admin.h"

#define success 1
#define failure 0
#define err -1

extern string PROJECTDIR;

void Admin::loadUserdatabase()
{
	string str, username, password;
	string file = PROJECTDIR + "data/users.txt";
	
	ifstream f;
	try {
		f.open(file);
		if(!f.is_open())
			throw err;
	
	}
	catch(int e) {
		cout<<"\n\tError in opening file to read...";
		return;
	}

	while(getline(f,str)) {
		stringstream ss(str);
		getline(ss, username, ':');
		getline(ss, password, ':');
		
		udmap.insert({username, password});
	}
}

void Admin::addUser()
{
	system("clear");
	
	string username, password;
	cout << "\nEnter the username: ";
	getline(cin, username);
		
	password = "Changeme";
		
	udmap.insert({username, password});

	cout << "\n\nPress enter key to return: ";
	getchar();
}

void Admin::updateUser()
{
	system("clear");

	string username, newuser;
	cout<<"\nEnter the username: ";
	getline(cin, username);
	
	try {
		if(udmap.find(username) != udmap.end()) {
			map<string, string>:: iterator it = udmap.find(username);
			
			cout<<"\n\nEnter the new username: ";
			getline(cin,newuser);
			
			udmap[newuser] = it->second;
			
			udmap.erase(it);
		}
		else
			throw err;
	}
	catch(int e) {
		cout<<"\n\n\t"<< username << " not found...";
	}
		
	cout << "\n\nPress enter key to return: ";
	getchar();
}

void Admin::deleteUser()
{
	system("clear");

	string username;
	cout << "\nEnter the username: ";
	getline(cin, username);

	if(udmap.find(username) != udmap.end())
		udmap.erase(username);
	else
		cout<<"\n\n\t"<< username << " not found...";
	
	cout << "\n\nPress enter key to return: ";
	getchar();
}

void Admin::listUsers()
{
	system("clear");

	map <string, string> :: iterator itu;
	
	cout << "\n";
	
	for(itu = udmap.begin(); itu != udmap.end(); ++itu)
		cout <<"  "<< itu->first << "\n";
	
	cout << "\n\nPress enter key to return: ";
	getchar();
}

void Admin::adminLogout()
{
	string file = PROJECTDIR + "data/users.txt";
	
	ofstream f;
	f.open(file);
	
	try {
		if(!f.is_open())
			throw err;
	}
	catch (int e) {
		cout<<"\n\n\tError in opening file to write...";
		return;
	}
	
	map<string, string> :: iterator itu;
	
	for(itu = udmap.begin(); itu != udmap.end(); ++itu)
		f << itu->first << ":" << itu->second << "\n";
	
	udmap.clear();
}
