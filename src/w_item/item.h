#pragma once

#include <string>

class player;

// Item base class
class item {
public:
    virtual ~item() = default;
    [[nodiscard]] virtual std::string getName() const = 0;
    virtual void use(player& player) = 0;
};