#include "statistic.h"

// Constructor
statistic::statistic(int initialValue, int maxValue)
:current_{initialValue}, maximum_{maxValue}{

}

// Types: 'current' | 'max'
int statistic::get(std::string &&type) const {
    if(type == "current")
        return current_;
    else if(type == "max")
        return maximum_;
    else
        std::cerr << "Incorret type of statistic in get method.\n";
}

// Types: 'current' | 'max'
void statistic::update(std::string &&type, int value) {
    if(type == "current")
        current_ = std::clamp(current_+value, 0, maximum_);
    else if(type == "max")
        maximum_ = std::clamp(maximum_+value, 0,100);
    else
        std::cerr << "Incorret type of statistic in update method.\n";
}

bool statistic::isZero() const {
    return current_ <= 0;
}
