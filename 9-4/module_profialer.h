#pragma once
#include <iostream>
#include <vector>
#include <ctime>

void processTask() {
    for (int i = 0; i < 1000000; ++i) {
        std::vector<int> vec;
        for (int j = 0; j < 100; ++j) {
            vec.push_back(j);
        }
    }
}

