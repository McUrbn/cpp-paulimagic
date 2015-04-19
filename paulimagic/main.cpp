//
//  main.cpp
//  paulifast
//
//  Created by Seifert on 12.04.15.
//  Copyright (c) 2015 Urban Seifert. All rights reserved.
//

#include <array>
#include <complex>
#include <sstream>
#include <string>
#include <vector>

#include <iostream>
#include <fstream>

#include "elements.h"

int main() {
    auto start = std::chrono::steady_clock::now();
    
    std::vector<int> couplings = {1,1,1,1,1};
    int val = 0;
    
    std::ofstream outputFile;
    outputFile.open("runtimesN5.txt", std::ios::app);
    
    for (int i = 1; i < 7; ++i) {
        std::cout << i << std::endl;
        start = std::chrono::steady_clock::now();
        val = IzH0zX(i, couplings);
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;
        outputFile << i << " " << std::chrono::duration <double, std::milli> (diff).count() << std::endl;
    }
    
    
    outputFile.close();

}
