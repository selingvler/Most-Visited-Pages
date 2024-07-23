

#ifndef hashTable_hpp
#define hashTable_hpp

#include <iostream>

struct KeyValue{
    std::string name;
    int count;
    KeyValue() {}
    KeyValue(const std::string& name, int count) : name(name), count(count) {}
};

class hashTable{
public:
    
    int hash(std::string key);
    hashTable();
    void AddFile(std::string name);
    static const int tableSize = 99991;
   
    int collision(int index);
    ~hashTable();
    
    
    void MostVisitedPages();
    
    KeyValue* hTable; //pointer to hash table array
private:
    int numOfFiles;
    
};


#endif /* hashTable_hpp */
