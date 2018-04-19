#include <string>
#include "token.h"

class util {
public: 
    static bool is_operator(std::string token);
    static bool is_number(const std::string& s);
    static int rank_operator(std::string op);
    static int rank_operator(Token tok);
    static Token create_token(std::string op);
};