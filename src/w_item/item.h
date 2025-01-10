#pragma once

#include <string>

class player;

class item {
public:
    virtual ~item() = default;
    virtual std::string getName() const = 0;
    virtual void use(player& player) = 0;
};