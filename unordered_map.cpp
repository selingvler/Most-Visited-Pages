

#include "unordered_map.hpp"

#include <iostream>
#include <unordered_map>
#include <string>



void VisitCounter::incrementVisit(const std::string& filename) {
        fileVisits[filename]++; // if filename doesn't exist it's inserted with a count of 1
    }

void VisitCounter:: displayTopVisited(int count) {
        int displayed = 0;
        while (displayed < count) {
            int maxVisits = 0;
            std::string maxFilename = "";

            for (const auto& pair : fileVisits) {
                if (pair.second > maxVisits) { // foreach pair in fileVisits, it compares the count with the maxVisit count. if it is greater it updates the maxVisits and the respective filename
                    maxVisits = pair.second;
                    maxFilename = pair.first;
                }
            }
            
            
            std::cout << "Filename" << displayed+1 << ": " << maxFilename << " Visits: " << maxVisits << std::endl;
            fileVisits[maxFilename] = 0;
            displayed++;
        }
    }

