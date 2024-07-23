

#include "hashTable.hpp"


#include <fstream>
#include <queue>
#include <vector>

using namespace std;


hashTable::hashTable(){
    hTable = new KeyValue[tableSize];
    for(int i=0;i<tableSize ;i++){
        hTable[i].name = "empty" ;
        hTable[i].count= 0;
    }
    
    numOfFiles = 0;
}

int hashTable:: hash(string key){

    int index;
    
    //djb2 hashing algorithm
    unsigned int hash = 5381;

        for (char ch : key) {
            hash = hash * 33 + ch;
        }

        index =  hash % tableSize;
     
    
    //This condition detects collisions by checking the name field of the found index is empty and equals to the given key. If not it means that there is a collision. Function calles "collision" to get a new index which is available.
    if (hTable[(int)index].name != key && hTable[(int)index].name != "empty") {
        return collision(index);
    }
    else
        return index;
}

void hashTable::AddFile(std::string name){
    int index = hash(name);
    
    if( hTable[index].name== "empty"){ //if the file is not in the hash table, then it inserts
        hTable[index].name = name;
        hTable[index].count ++;
        numOfFiles++;
    }
    else if(hTable[(int)index].name == name){ //otherwise founds the file and just increments the count
        hTable[index].count ++;
    }
    
}

hashTable::~hashTable()
{
    delete [] hTable;
}

int hashTable::collision(int index){
    int i = 1;
    
    int maxIterations = 1000; //to avoid infinite loop
    
    while (hTable[index].name != "empty" && i <= maxIterations) {
            index = index + i^2;
            i++;
        
            if (index >= tableSize) {
                index = index % tableSize; //to avoid exceeding the size of hash table
            }
        }

        if (i > maxIterations) {
            return -1;
        }
    return index;
     
}


void hashTable::MostVisitedPages(){
    
    struct CompareKeyValue {
        bool operator()(const KeyValue& a, const KeyValue& b) {
            return a.count > b.count;  // returns true for a being greater than b
        }
    };
    
    
    std::priority_queue<KeyValue, std::vector<KeyValue>, CompareKeyValue> minHeap; //declared a priority queue called minHeap
    
    for (int i = 0; i < tableSize; i++) {
        if (minHeap.size() < 10) {
            minHeap.push(hTable[i]);
        } else if (hTable[i].count > minHeap.top().count) { //when the element's count is greater than the smallest count, element is inserted to minHeap
            minHeap.pop();
            minHeap.push(hTable[i]);
        }
    }
    
    
    KeyValue* arr = new KeyValue[9]; //array to store most visited files
    
    for (int i = 9; i >= 0; i--) {
        if (!minHeap.empty()) {
            arr[i] = minHeap.top();
            minHeap.pop();
        }
    }
    
    cout << "Using hash table implementation: " << endl; //printing most visited files
    for (int i = 0; i <= 9; i++) {
        cout <<"Filename" << i+1 << ": " << arr[i].name << " Visits: " << arr[i].count << endl;
    }
    
    
    
    
    
    
}
