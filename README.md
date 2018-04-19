# C++ Math Parser
### Simple math expression parser with support for basic operators and grouping.

## Flow
The parser consists of three parts, the lexer which takes in a string and tokenizes it, the shunting yard algorithm which converts the infix math expression into a postfix expression and then the math expression computer which will use the reverse polish notation expression to evaluate the expression.

## Operators
Supports ^ * / + - and integer numbers. Support for decimals and functions can be added in the future with small additions to the shunting yard algorithm and a partial rewrite of the math lexer to allow it to identify more complex tokens.