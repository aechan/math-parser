#include <vector>
#include <deque>
#include "syard.h"
#include "token.h"
#include "util.h"

using namespace std;

// compares the operator precedence of op1 and op2
// returns -1 if op1 < op2, 0 if equal and 1 if op1 > op2
int compare_precedence(string op1, string op2) {
    int rank1, rank2;
    
    rank1 = util::rank_operator(op1);
    rank2 = util::rank_operator(op2);
    
    if(rank1 < rank2) return -1;
    if(rank1 == rank2) return 0;
    if(rank1 > rank2) return 1;

    return 999;
}

// postfix algorithm: linear time complexity
deque<Token> syard::postfix(deque<Token> infix) {
    vector<Token> operator_stack;
    deque<Token> output_queue;

    // While there are tokens to be read:
    for(auto token : infix) {
        // Read a token
        switch(token.type) {
        case Token::Type::Number:
            // If the token is a number, then add it to the output queue
            output_queue.push_back(token);
            break;

        case Token::Type::Operator:
            {
                // If the token is operator, o1, then:
                const auto o1 = token;

                // while there is an operator token,
                while(!operator_stack.empty()) {
                    // o2, at the top of stack, and
                    const auto o2 = operator_stack.back();

                    // either o1 is left-associative and its precedence is
                    // *less than or equal* to that of o2,
                    // or o1 if right associative, and has precedence
                    // *less than* that of o2,
                    if(
                        (! o1.rightAssociative && o1.precedence <= o2.precedence)
                    ||  (  o1.rightAssociative && o1.precedence <  o2.precedence)
                    ) {
                        // then pop o2 off the stack,
                        operator_stack.pop_back();
                        // onto the output queue;
                        output_queue.push_back(o2);

                        continue;
                    }

                    // @@ otherwise, exit.
                    break;
                }

                // push o1 onto the stack.
                operator_stack.push_back(o1);
            }
            break;

        case Token::Type::LeftParen:
            // If token is left parenthesis, then push it onto the stack
            operator_stack.push_back(token);
            break;

        case Token::Type::RightParen:
            // If token is right parenthesis:
            {
                bool match = false;
                while(! operator_stack.empty()) {
                    // Until the token at the top of the stack
                    // is a left parenthesis,
                    const auto tos = operator_stack.back();
                    if(tos.type != Token::Type::LeftParen) {
                        // pop operators off the stack
                        operator_stack.pop_back();
                        // onto the output queue.
                        output_queue.push_back(tos);
                    }

                    // Pop the left parenthesis from the stack,
                    // but not onto the output queue.
                    operator_stack.pop_back();
                    match = true;
                    break;
                }

                if(!match && operator_stack.empty()) {
                    // If the stack runs out without finding a left parenthesis,
                    // then there are mismatched parentheses.
                    printf("RightParen error (%s)\n", token.str.c_str());
                    exit(0);
                }
            }
            break;

        default:
            printf("error (%s)\n", token.str.c_str());
            exit(0);
            break;
        }
    }
    // When there are no more tokens to read:
    //   While there are still operator tokens in the stack:
    while(! operator_stack.empty()) {
        // If the operator token on the top of the stack is a parenthesis,
        // then there are mismatched parentheses.
        if(operator_stack.back().type == Token::Type::LeftParen) {
            printf("Mismatched parentheses error\n");
            exit(0);
        }

        // Pop the operator onto the output queue.
        output_queue.push_back(std::move(operator_stack.back()));
        operator_stack.pop_back();
    }
    return output_queue;
}

