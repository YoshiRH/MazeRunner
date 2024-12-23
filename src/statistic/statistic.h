#pragma once

#include <iostream>
#include <algorithm>

// Class wraper for individual stats
class statistic {
    int current_;
    int maximum_;

public:
    statistic(int initialValue, int maxValue);

    int get(std::string&& type) const; // Types: 'current' | 'max'
    void update(std::string&& type, int value); // Types: 'current' | 'max'

    [[nodiscard]] bool isZero() const; // Check if current stats is equal to 0
};