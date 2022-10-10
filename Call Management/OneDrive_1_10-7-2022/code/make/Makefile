application: contactsTester.o userMenu.o user.o personalContacts.o businessContacts.o adminMenu.o admin.o 
	g++ -o ../bin/contactsManagement.exe ../obj/contactsTester.o ../obj/userMenu.o ../obj/user.o ../obj/personalContacts.o  ../obj/businessContacts.o ../obj/adminMenu.o ../obj/admin.o 
test: test.o user.o personalContacts.o businessContacts.o adminMenu.o user.o admin.o
	g++ -o ../bin/testApp.exe ../obj/testContactmanagement.o ../obj/user.o ../obj/personalContacts.o  ../obj/businessContacts.o ../obj/adminMenu.o ../obj/admin.o -lcppunit
contactsTester.o: ../src/contactsTester.cpp
	g++ -o ../obj/contactsTester.o ../src/contactsTester.cpp -c
user.o: ../src/user.cpp
	g++ -o ../obj/user.o ../src/user.cpp -c
userMenu.o: ../src/userMenu.cpp
	g++ -o ../obj/userMenu.o ../src/userMenu.cpp -c
admin.o: ../src/admin.cpp
	g++ -o ../obj/admin.o ../src/admin.cpp -c
adminMenu.o: ../src/adminMenu.cpp
	g++ -o ../obj/adminMenu.o ../src/adminMenu.cpp -c
personalContacts.o: ../src/personalContacts.cpp
	g++ -o ../obj/personalContacts.o ../src/personalContacts.cpp -c
businessContacts.o: ../src/businessContacts.cpp
	g++ -o ../obj/businessContacts.o ../src/businessContacts.cpp -c
test.o: ../src/testContactmanagement.cpp 
	g++ -o ../obj/testContactmanagement.o ../src/testContactmanagement.cpp -c 
clean:
	rm ../obj/*.o ../bin/*.exe 

# test: ../../ToolsReport/CUnit/testprogram.cpp ../../ToolsReport/CUnit/func.cpp
# 	g++ -o ../../ToolsReport/CUnit/test.exe ../../ToolsReport/CUnit/testprogram.cpp ../../ToolsReport/CUnit/func.cpp -lcunit
# 	../../ToolsReport/CUnit/test.exe > ../../ToolsReport/CUnit/cunitReport.txt
