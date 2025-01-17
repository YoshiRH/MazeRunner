#pragma once

#include "iostream"

struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const std::pair<T1, T2> &pair) const;
};

template<typename T1, typename T2>
size_t pair_hash::operator()(const std::pair<T1, T2> &pair) const {
    auto hash1 = std::hash<T1>{}(pair.first);
    auto hash2 = std::hash<T2>{}(pair.second);
    return hash1 ^ (hash2 << 1);
}