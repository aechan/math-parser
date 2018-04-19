#include <stack>
#include <vector>
#include "syard.h"

using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int rank_operator(string op) {
    if(op == "^") return 4;
    if(op == "*") return 3;
    if(op == "/") return 3;
    if(op == "+") return 2;
    if(op == "-") return 2;
    return 0;
}
// compares the operator precedence of op1 and op2
// returns -1 if op1 < op2, 0 if equal and 1 if op1 > op2
int compare_precedence(string op1, string op2) {
    int rank1, rank2;
    
    rank1 = rank_operator(op1);
    rank2 = rank_operator(op2);
    
    if(rank1 < rank2) return -1;
    if(rank1 == rank2) return 0;
    if(rank1 > rank2) return 1;

    return 999;
}

// postfix algorithm: linear time complexity
vector<string> syard::postfix(vector<string> infix) {
    stack<string> operator_stack;
    vector<string> output_queue;
    while(!infix.empty()) {
        // consume token
        string token = infix.front();
        infix.erase(infix.begin());


        if(is_number(token)) {  // token is a number
            output_queue.push_back(token);
        } else if(token == "(") {   // token is left brace
            operator_stack.push(token);
        } else if(token == ")") {   // token is right brace
            while(operator_stack.top() != ")") {
                output_queue.push_back(operator_stack.top());
                operator_stack.pop();
            }
            if(operator_stack.top() != "(") {
                // mismatched braces throw error
                throw "Mismatched Braces!";
            } else {
                operator_stack.pop();
            }
        } else {    // token is any operator
            while(
                ((compare_precedence(operator_stack.top(), token) > 0) ||
                (compare_precedence(operator_stack.top(), token) == 0 && operator_stack.top() != "^")) &&
                (operator_stack.top() != "(")
            ) {
                output_queue.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(token);
        }
    }
    while(!operator_stack.empty()) {
        output_queue.push_back(operator_stack.top());
        operator_stack.pop();
    }
    return output_queue;
}

