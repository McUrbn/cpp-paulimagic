//
//  elements.h
//  paulimagic
//
//  Created by Seifert on 18.04.15.
//  Copyright (c) 2015 Urban Seifert. All rights reserved.
//

#ifndef paulimagic_elements_h
#define paulimagic_elements_h

//#include "tensorproduct.h"
#include <vector>

auto IzH0zX (int power, const std::vector<int> &vec) -> int;

auto IzH0z1 (const std::vector<int> &vec) -> int;
auto IzH0z2 (const std::vector<int> &vec) -> int;
auto IzH0z3 (const std::vector<int> &vec) -> int;
auto IzH0z4 (const std::vector<int> &vec) -> int;
auto IzH0z5 (const std::vector<int> &vec) -> int;
auto IzH0z6 (const std::vector<int> &vec) -> int;
auto IzH0z7 (const std::vector<int> &vec) -> int;

#endif
