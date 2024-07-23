

#ifndef unordered_map_hpp
#define unordered_map_hpp

#include <iostream>
#include <unordered_map>
#include <string>



class VisitCounter {
private:
    std::unordered_map<std::string, int> fileVisits;

public:
    
    void incrementVisit(const std::string& filename);

   
    void displayTopVisited(int count);
};

#endif /* unordered_map_hpp */
