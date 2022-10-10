#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

#define success 1
#define failure 0
#define nomatch -1

class Contact
{
	protected:
		char type;
		int contactId;
		string firstName;
		string lastName;
		string phone1;
		string phone2;
		string phone3;
		string email1;
		string email2;
	public:
		Contact()                    { ++contactId; }
		void setType(char t)         { type = t; }
		void setFirstname(string fn) { firstName = fn; }
		void setLastname(string ln)  { lastName = ln; }
		void setPhone1(string ph1)   { phone1 = ph1; }
		void setPhone2(string ph2)   { phone2 = ph2; }
		void setPhone3(string ph3)   { phone3 = ph3; }
		void setEmail1(string em1)   { email1 = em1; }
		void setEmail2(string em2)   { email2 = em2; }

		int getContactid()    { return contactId; }
		char getType()        { return type; }
		string getFirstname() { return firstName; }
		string getLastname()  { return lastName; }
		string getPhone1()    { return phone1; }
		string getPhone2()    { return phone2; }
		string getPhone3()    { return phone3; }
		string getEmail1()    { return email1; }
		string getEmail2()    { return email2; }
};

//int contact::contactid = 0;

class Personal : public Contact
{
	protected:
		string address;
		string wPhone;
		string birthDate;
		string emergencyCt;

	public:
		void setAddress(string add)          { address = add; }
		void setWhatsappphone(string wph)    { wPhone = wph; }
		void setBirthdate(string bdate)      { birthDate = bdate; }
		void setEmergencycontact(string ect) { emergencyCt = ect; }
		
		string getAddress()          { return address; }
		string getWhatsappphone()    { return wPhone; }
		string getBirthdate()        { return birthDate; }
		string getEmergencycontact() { return emergencyCt; }
};

class Business : public Contact
{
	protected:
		string company;
		string designation;
		string website;

	public:
		void setCompany(string cmp)     { company = cmp; }
		void setDesignation(string deg) { designation = deg; }
		void setWebsite(string web)     { website = web; }
		
		string getCompany()     { return company; }
		string getDesignation() { return designation; }
		string getWebsite()     { return website; }
};

map <int, Personal> pmap;
map <int, Business> bmap;

void showDetails()
{
		
		map<int, Personal>::iterator itp;	
		map<int, Business>::iterator itb;	
		for(itp = pmap.begin(); itp != pmap.end(); ++itp) {			
			cout<<"\n\nContactid: "<<itp->first;
			cout<<"\nFirstname: "<<itp->second.getFirstname();
		}
		for(itb = bmap.begin(); itb != bmap.end(); ++itb) {			
			cout<<"\n\nContactid: "<<itb->first;
			cout<<"\nFirstname: "<<itb->second.getFirstname();
		}
			
}

int checkContact()
{
	
}

int loadContactdatabase(string username)
{
	string file = "/home/SAMSON PAUL M/sprint2/" + username + "/contacts.txt";
	ifstream fr;
	fr.open(file);
	if(!fr.is_open())
		cout<<"\n\terror in opening the file to read...";

	ofstream fw;
	fw.open("/home/SAMSON PAUL M/sprint2/InvalidContacts.txt");
	if(!fw.is_open())
		cout<<"\n\terror in opening the file to write...";

	string str, type, fname, lname, ph1, ph2, ph3, em1, em2, add, wph, bdate, ect, com, des, web;
	int id;
	
	while(getline(fr, str)) 
	{
		stringstream ss(str);
		getline(ss, type, ':');
		if(type.compare("p") == 0) 
		{
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
			getline(ss, ect, '|');
					
			if(fname != "" && ph1 != "" && em1 != "" && add != "" && wph != "" && bdate != "")
			{
				//p= new Personal;
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
			{
				fw << str;
			}
		}
		
		if(type.compare("b") == 0) 
		{
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
					
			if(fname != "" && ph1 != "" && em1 != "" && com != "" && des != "" && web != "")
			{
				//b= new Business;
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
			{
				fw << str;
			}
		}
	}	
}

void changePassword(string username)
{
	string password, str;

	fstream f;
	f.open("/home/SAMSON PAUL M/sprint2/users.txt");
	if(!f.is_open())
		cout<<"\n\terror in opening the file...";
	
	while(getline(f,str)) {	
		stringstream ss(str);
		string user, pass;
		getline(ss, user, ':');
		if((username.compare(user)) == 0) {
			getline(ss, pass, ':');

			cout<<"\nEnter the new password (minimum 8 characters): ";
			getline(cin, password);
			f.seekp(user.length()+1, ios::beg);
			f << password;
			}
	}
}

void listPersonalcontacts()
{
	
	map<int, Personal>::iterator itp;	
	
	for(itp = pmap.begin(); itp != pmap.end(); ++itp) {			
		cout << "\n\n" << itp->first << " | " << itp->second.getFirstname() << " | " << itp->second.getLastname() << " | " 
		     << itp->second.getPhone1() << " | " << itp->second.getPhone2() << " | "  << itp->second.getPhone3() << " | " 
		     << itp->second.getEmail1() << " | " << itp->second.getEmail2() << " | "  << itp->second.getAddress() << " | " 
		     << itp->second.getWhatsappphone() << " | " << itp->second.getBirthdate() << " | " << itp->second.getEmergencycontact();
	}
}

void listBusinesscontacts()
{
	
	map<int, Business>::iterator itb;	
	
	for(itb = bmap.begin(); itb != bmap.end(); ++itb) {			
		cout << "\n\n" << itb->first << " | " << itb->second.getFirstname() << " | " << itb->second.getLastname() << " | " 
		     << itb->second.getPhone1() << " | " << itb->second.getPhone2() << " | "  << itb->second.getPhone3() << " | " 
		     << itb->second.getEmail1() << " | " << itb->second.getEmail2() << " | "  << itb->second.getCompany() << " | " 
		     << itb->second.getDesignation() << " | " << itb->second.getWebsite();
	}
}

void userLogout(string username)
{
	string file = "/home/SAMSON PAUL M/sprint2/" + username + "/contacts.txt";
	ofstream f;
	f.open(file);
	if(!f.is_open())
		cout<<"\n\terror in opening the file to read...";

	map<int, Personal>::iterator itp;	
	map<int, Business>::iterator itb;	
	
	for(itp = pmap.begin(); itp != pmap.end(); ++itp) {			
		f << "p:" << itp->second.getFirstname() << "|" << itp->second.getLastname() << "|" 
		     << itp->second.getPhone1() << "|" << itp->second.getPhone2() << "|"  << itp->second.getPhone3() << "|" 
		     << itp->second.getEmail1() << "|" << itp->second.getEmail2() << "|"  << itp->second.getAddress() << "|" 
		     << itp->second.getWhatsappphone() << "|" << itp->second.getBirthdate() << "|" << itp->second.getEmergencycontact() <<"\n";
	}
	
	for(itb = bmap.begin(); itb != bmap.end(); ++itb) {			
		f << "b:" << itb->second.getFirstname() << "|" << itb->second.getLastname() << "|" 
		     << itb->second.getPhone1() << "|" << itb->second.getPhone2() << "|"  << itb->second.getPhone3() << "|" 
		     << itb->second.getEmail1() << "|" << itb->second.getEmail2() << "|"  << itb->second.getCompany() << "|" 
		     << itb->second.getDesignation() << "|" << itb->second.getWebsite() << "\n";
	}
	
	cout << "\n"<< username<<" logged out...";	
}


int updateContact()
{
	int choice;
	int id;
	cout<<"\n\n\tEnter the contactid: ";
	cin >> id;
	getchar();

	if(pmap.find(id) != pmap.end()) {
		cout << "\n\n# Enter 0 to update firstname";
		cout << "\n# Enter 1 to update lastname";
		cout << "\n# Enter 2 to update phone1";
		cout << "\n# Enter 3 to update phone2";
		cout << "\n# Enter 4 to update phone3";
		cout << "\n# Enter 5 to update email1";
		cout << "\n# Enter 6 to update email2";
		cout << "\n# Enter 7 to update address";
		cout << "\n# Enter 8 to update whatsappphone";
		cout << "\n# Enter 9 to update birthdate";
		cout << "\n# Enter 10 to update emergencycontact\n\t";
		cin>>choice;
		getchar();
	
		switch(choice)
		{
			case 0:
				pmap[id].setFirstname("prakash");
				break;
			case 1:
				pmap[id].setLastname("r");
				break;
			case 2:
				pmap[id].setPhone1("9834256378");
				break;
			case 3:
				pmap[id].setPhone2("9846572845");
				break;
			case 4:
				pmap[id].setPhone3("9898342567");
				break;
			case 5:
				pmap[id].setEmail1("prakash@gmail.com");
				break;
			case 6:
				pmap[id].setEmail2("surya@gmail.com");
				break;
			case 7:
				pmap[id].setAddress("Anikkorai, Ooty");
				break;
			case 8:
				pmap[id].setWhatsappphone("8745637854");
				break;
			case 9:
				pmap[id].setBirthdate("23/05/2001");
				break;
			case 10:
				pmap[id].setEmergencycontact("yes");
				break;
		}
		cout<<"\n\tContactid found and updated...";
		return success;
	}
	else if(bmap.find(id) != bmap.end()) {
		cout << "\n\n# Enter 0 to update firstname";
		cout << "\n# Enter 1 to update lastname";
		cout << "\n# Enter 2 to update phone1";
		cout << "\n# Enter 3 to update phone2";
		cout << "\n# Enter 4 to update phone3";
		cout << "\n# Enter 5 to update email1";
		cout << "\n# Enter 6 to update email2";
		cout << "\n# Enter 7 to update company";
		cout << "\n# Enter 8 to update designation";
		cout << "\n# Enter 9 to update website\n\t";
		cin>>choice;
		getchar();
	
		switch(choice)
		{
			case 0:
				bmap[id].setFirstname("prakash");
				break;
			case 1:
				bmap[id].setLastname("r");
				break;
			case 2:
				bmap[id].setPhone1("9834256378");
				break;
			case 3:
				bmap[id].setPhone2("9846572845");
				break;
			case 4:
				bmap[id].setPhone3("9898342567");
				break;
			case 5:
				bmap[id].setEmail1("prakash@gmail.com");
				break;
			case 6:
				bmap[id].setEmail2("surya@gmail.com");
				break;
			case 7:
				bmap[id].setCompany("Capgemini, India");
				break;
			case 8:
				bmap[id].setDesignation("Analyst");
				break;
			case 9:
				bmap[id].setWebsite("prakash.com");
				break;
		}
		cout<<"\n\tContactid found and updated...";
		return success;
	}
	else{
		cout<<"\n\tContactid not found...";
		return failure;
	}
}

int deleteContact()
{
	int id;
	cout<<"\n\n\tEnter the contactid: ";
	cin >> id;
	getchar();

	if(pmap.find(id) != pmap.end()) {
		pmap.erase(id);
		cout<<"\n\tContactid found and deleted...";
		return success;
	}
	else if(bmap.find(id) != bmap.end()) {
		bmap.erase(id);
		cout<<"\n\tContactid found and deleted...";
		return success;
	}
	else{
		cout<<"\n\tContactid not found...";
		return failure;
	}
}

int checkUser(string username)
{
	string password, str;
	int flag = 0;
	cout << "\nEnter the password: ";
	getline(cin, password);

	ifstream f;
	f.open("/home/SAMSON PAUL M/sprint2/users.txt");
	if(!f.is_open())
		cout<<"\n\terror in opening the file...";
	
	while(getline(f,str)) {	
		stringstream ss(str);
		string user, pass;
		getline(ss, user, ':');
		if((username.compare(user)) == 0) {
			flag = 1;
			getline(ss, pass, ':');
			if((password.compare(pass)) == 0) {
				cout << "\n\t"<< username <<" logged in...";
				f.close();
				return success;
			}
			else {
				cout << "\n\tpassword is incorrect...";
				f.close();
				return failure;
			}
		}
	}
	if(flag == 0) {
		cout<<"\n\t"<< username <<" not found...";
		f.close();
		return nomatch ;
	}

	return success;
}

int user(string u)
{
	
	string username;
	char choice1, choice2;
	int ret;
 static int i = 1;

	cout << "\nEnter the username: ";
	getline(cin, username);

	ret = checkUser(username);
	while(1) {
		if(ret == 1) {
			while(1) {
				cout << "\n\n# Enter m to map contacts";
				cout << "\n\n# Enter c to change password";
				cout << "\n# Enter a to add contact";
				cout << "\n# Enter u to update contact";
				cout << "\n# Enter d to delete contact";
				cout << "\n# Enter p to list all personal contacts";
				cout << "\n# Enter b to list all business contacts";
				cout << "\n# Enter l to logout\n\t";
				cin >> choice1;
				getchar();

				switch(choice1) {
					case 'm':
						ret = loadContactdatabase(username);
						//showDetails(pmap, bmap);
						break;
					case 'c':
						changePassword(username);
						break;
					case 'a':
						cout << "\n\n##Enter p to add peronal contact";
						cout << "\n##Enter b to add business contact\n\n\t";
						cin>>choice2;
						getchar();

 						switch(choice2) {
							case 'p':
								break;
							case 'b': 
								break;
						}
						break;
					case 'u':
						ret = updateContact();
						break;
					case 'd':
						ret = deleteContact();
						break;
					case 'p':
						listPersonalcontacts();
						break;
					case 'b':
						listBusinesscontacts();
						break;
					case 'l':
						userLogout(username);
						break;
					return success;
				}
			}
		}
		else if (ret == -1)
			return failure;
		else
			ret = checkUser(username);
	}
}

int main()
{
	char choice;
	int ret;

	while(1) {
		cout << "\n\n# Enter a for admin";
		cout << "\n# Enter u for user";
		cout << "\n# Enter e to exit\n\t";
		cin >> choice;
		getchar();
		switch(choice) {
			case 'a':
				//ret = admin();
				break;
			case 'u':
				ret = user("user");
				break;
			case 'e':
				exit(1);
		}
	}

	return success;
}
