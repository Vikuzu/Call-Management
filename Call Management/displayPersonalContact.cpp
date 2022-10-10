void displayPersonalContact(map<int, Personal> &p){
    map<int ,Personal>::iterator itr=p.begin();
    while(itr != p.end()){
        (itr->second).displayContacts();
        itr++;
    }
}