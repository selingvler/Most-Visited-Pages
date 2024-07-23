

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "hashTable.hpp"
#include "unordered_map.hpp"



using namespace std;
hashTable HT;
VisitCounter visitCounter;


void CalculateTimeHash(){
    
    ifstream infile;
    string line;
    infile.open("access_log");
    
    
    
    auto startHashTable = std::chrono::high_resolution_clock::now();
    
    //for reading access log file
    while(!infile.eof( )){ //until reached at the end of the file
        
        
        getline(infile,line);
        const int maxWords = 100;
        string words[maxWords];
        int wordCount = 0;
        
        size_t pos = 0;
        while ((pos = line.find(' ')) != std::string::npos) {
            words[wordCount++] = line.substr(0, pos); //
            line.erase(0, pos + 1);
        }
        
        words[wordCount++] = line; //the remained part at the end of line
        string filename=words[6];
        string statusCode=words[8];
        
        if(statusCode=="200"&&wordCount==10){
            HT.AddFile(filename);
        }
        
    }
    HT.MostVisitedPages();

    auto stopHashTable = std::chrono::high_resolution_clock::now();
    auto durationHashTable = std::chrono::duration_cast<std::chrono::microseconds>(stopHashTable - startHashTable);
    
    cout << "Calculated time using hash table: " << durationHashTable.count() << " microseconds" << endl << endl;
}


void CalculateT_Unordered(){
    ifstream infile2;
    string line2;
    infile2.open("access_log");
    
    
    
    auto startunordered = std::chrono::high_resolution_clock::now();
    while(!infile2.eof( )){ //until reached at the end of the file
        
        
        getline(infile2,line2);
        const int maxWords = 100;
        string words[maxWords];
        int wordCount = 0;
        
        size_t pos = 0;
        while ((pos = line2.find(' ')) != std::string::npos) {
            words[wordCount++] = line2.substr(0, pos);
            line2.erase(0, pos + 1);
        }
        
        words[wordCount++] = line2;
        string filename=words[6];
        string statusCode=words[8];
        
        if(statusCode=="200"&&wordCount==10){
            visitCounter.incrementVisit(filename);
        }
        
    }
    visitCounter.displayTopVisited(10);
    auto stopunordered = std::chrono::high_resolution_clock::now();
    auto durationunordered = std::chrono::duration_cast<std::chrono::microseconds>(stopunordered - startunordered);
    
    cout << "Calculated time using unordered map: " << durationunordered.count() << " microseconds"<< endl;
    
}


int main() {
    
    CalculateTimeHash();
    
    cout<<"Using unordered map : "<<endl;
    CalculateT_Unordered();
    
    
}

