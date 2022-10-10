#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

#include "../header/adminMenu.h"
#include "../header/userMenu.h"

#define success 1
#define failure 0
#define err -1

int main()
{
	string username;
	char choice;
	
	while(1) {
		system("clear");
		cout << "\nEnter the username: ";
		getline(cin, username);
		
		if(username.compare("admin") == 0)
			admin(username);
		else
			user(username);
		
		cout << "\nDo you want to continue with the application (y/n)? ";
		cin >> choice;
		getchar();
		
		if (choice == 'n')
			break;
	}
	
	return success;
}
