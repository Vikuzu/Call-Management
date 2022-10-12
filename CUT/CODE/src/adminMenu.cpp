#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

#include <adminMenu.h>
#include <admin.h>

#define success 1
#define failure 0
#define err -1

int checkAdmin(string password)
{
	if((password.compare("Admin")) == 0)
		return success;
	else
		return failure;
}

void admin(string username)
{
	string password;
	int choice, ret;	
	cout << "\n\nEnter the password: ";
	getline(cin, password);
	
	ret = checkAdmin(password);
	
	while(1) {
		if(ret == 1) {
           		Admin a;
			
			a.loadUserdatabase();
        
			while(1){
				
				system("clear");
				cout << "\n\n  1. add user";
				cout << "\n  2. update user";
				cout << "\n  3. delete user";
				cout << "\n  4. display users";
				cout << "\n  5. logout";
				
				cout << "\n\n  Choose an option: ";
				cin >> choice;
				getchar();
				
				switch(choice) {
					case 1:
						a.addUser(); break;
					case 2:
						a.updateUser(); break;
					case 3:
						a.deleteUser(); break;
					case 4:
						a.listUsers(); break;
					case 5:
						a.adminLogout(); return;
					default:
						cout<<"\n\n  Please choose the correct option...";
				}
			}
		}

		else {
			cout << "\n\n\tPassword is incorrect...\n";
			cout << "\n\nEnter the password: ";
			getline(cin, password);

			ret = checkAdmin(password);
		}
	}
}
