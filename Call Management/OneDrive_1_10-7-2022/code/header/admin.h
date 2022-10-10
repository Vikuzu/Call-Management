#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
using namespace std;

class Admin
{
	map <string, string> udmap;
	
	public:
        	void loadUserdatabase();
		void addUser();
		void updateUser();
		void deleteUser();
		void listUsers();
		void adminLogout();
};

#endif
