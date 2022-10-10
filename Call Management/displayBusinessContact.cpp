void displayBusinessContact(map<int, Business> &b){
    map<int,Business>::iterator itr=b.begin();
    while(itr != b.end()){
        (itr->second).displayContacts();
        itr++;
    }
}