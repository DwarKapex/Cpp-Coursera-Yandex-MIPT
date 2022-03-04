//
//  test_runner.cpp
//  final_project
//
//  Created by Vladislav Kozlov on 6/28/19.
//  Copyright © 2019 Vladislav Kozlov. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include "test_runner.h"


void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}
