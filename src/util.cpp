#pragma once
#include "util.h"

bool util::is_operator(std::string token) {
    return (token == "*" ||
        token == "/" ||
        token == "+" ||
        token == "-" ||
        token == "^" ||
        token == "(" ||
        token == ")");
}