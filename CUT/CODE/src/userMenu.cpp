#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

#include "../header/userMenu.h"

#define success 1
#define failure 0
#define err -1

string PROJECTDIR = "../";

int checkUser(string username)
{
	string str, password, user, pass;
	int flag = 0;
	
	cout << "\n\nEnter the password: ";
	getline(cin, password);

	ifstream f;
	try {
		f.open(PROJECTDIR + "data/users.txt");
		if(!f.is_open())
			throw err;
	}
	catch (int e) {
		cout<<"\n\n\tError in opening file to read...";
		return failure;
	}
		
	while(getline(f,str)) {	
		stringstream ss(str);
		getline(ss, user, ':');
		
		if((username.compare(user)) == 0) {
			flag = 1;
			getline(ss, pass, ':');
			if((password.compare(pass)) == 0)
				f.close();
			else {
				cout << "\n\n\tPassword is incorrect...";
				f.close();
				return failure;
			}
		}
	}
	
	if(flag == 0) {
		cout<<"\n\n\t"<< username <<" not found...";
		f.close();
		return err ;
	}
	return success;
}

void user(string username)
{
	int choice, ret;
	
	ret = checkUser(username);
		
	while(1) {
		if(ret == 1) {
			User u;
			u.loadUserdatabase1();
			u.loadContactdatabase(username);
			
			while(1) {
				system("clear");
				cout << "\n\n  1. change password";
				cout << "\n  2. add contact";
				cout << "\n  3. update contact";
				cout << "\n  4. delete contact";
				cout << "\n  5. list personal contacts";
				cout << "\n  6. list business contacts";
				cout << "\n  7. logout";

				cout << "\n\n  Choose an option: ";
				cin >> choice;
				getchar();

				switch(choice) {
					case 1:
						u.changePassword(username); break;
					case 2:
						u.addContact(); break;
					case 3:
						u.updateContact(); break;
					case 4:
						u.deleteContact(); break;
					case 5:
						u.listPersonalcontacts(); break;
					case 6:
						u.listBusinesscontacts(); break;
					case 7:
						u.userLogout(username); return;
					default:
						cout<<"\n\n  Please choose the correct option...";
				}
			}
		}

		else if (ret == -1)
			return;
		else
			ret = checkUser(username);
	}
}
