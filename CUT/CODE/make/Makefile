GCC = g++
CFLAGS = -c -g -Wall
LFLAGS = -o
IFLAGS = -I $(INC)
SRC = ../src
BIN = ../bin
OBJ = ../obj
INC = ../header


application: contactsTester.o userMenu.o user.o personalContacts.o businessContacts.o adminMenu.o admin.o 
	$(GCC) $(LFLAGS) $(BIN)/contactsManagement.exe $(OBJ)/contactsTester.o $(OBJ)/userMenu.o $(OBJ)/user.o $(OBJ)/personalContacts.o  $(OBJ)/businessContacts.o $(OBJ)/adminMenu.o $(OBJ)/admin.o 

test: test.o user.o personalContacts.o businessContacts.o adminMenu.o user.o admin.o
	$(GCC) $(LFLAGS) $(BIN)/testApp.exe $(OBJ)/testContactmanagement.o $(OBJ)/user.o $(OBJ)/personalContacts.o  $(OBJ)/businessContacts.o $(OBJ)/adminMenu.o $(OBJ)/admin.o -lcppunit

contactsTester.o: $(SRC)/contactsTester.cpp
	$(GCC) $(LFLAGS) $(OBJ)/contactsTester.o $(SRC)/contactsTester.cpp $(CFLAGS) $(IFLAGS)

user.o: $(SRC)/user.cpp
	$(GCC) $(LFLAGS) $(OBJ)/user.o $(SRC)/user.cpp $(CFLAGS) $(IFLAGS)

userMenu.o: $(SRC)/userMenu.cpp
	$(GCC) $(LFLAGS) $(OBJ)/userMenu.o $(SRC)/userMenu.cpp $(CFLAGS) $(IFLAGS)

admin.o: $(SRC)/admin.cpp
	$(GCC) $(LFLAGS) $(OBJ)/admin.o $(SRC)/admin.cpp $(CFLAGS) $(IFLAGS)

adminMenu.o: $(SRC)/adminMenu.cpp
	$(GCC) $(LFLAGS) $(OBJ)/adminMenu.o $(SRC)/adminMenu.cpp $(CFLAGS) $(IFLAGS)

personalContacts.o: $(SRC)/personalContacts.cpp
	$(GCC) $(LFLAGS) $(OBJ)/personalContacts.o $(SRC)/personalContacts.cpp $(CFLAGS) $(IFLAGS)

businessContacts.o: $(SRC)/businessContacts.cpp
	$(GCC) $(LFLAGS) $(OBJ)/businessContacts.o $(SRC)/businessContacts.cpp $(CFLAGS) $(IFLAGS)

test.o: $(SRC)/testContactmanagement.cpp 
	$(GCC) $(LFLAGS) $(OBJ)/testContactmanagement.o $(SRC)/testContactmanagement.cpp $(CFLAGS) $(IFLAGS)

clean:
	rm $(OBJ)/*.o $(BIN)/*.exe 


