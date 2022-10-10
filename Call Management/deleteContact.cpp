void deleteContact(int contactid){
    map<int,Business>::iterator itr=b.begin();
    map<int,Personal>::iterator itr1=p.begin();
    while(itr != b.end()){
        if((itr->first)== contactid){
            b.erase(itr);
            delete itr;
            break;
        }
        itr++;
    }

    while(itr1 != p.end()){
        if((itr1->first)== contactid){
            b.erase(itr1);
            delete itr1;
            break;
        }
        itr1++;
    }
}