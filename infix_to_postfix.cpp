#include <iostream>
#include <string>

#include "Stack.hpp"

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int prior(char c) {
    if (c == '-' || c == '+') {
        return 2;
    }
    if (c == '*' || c == '/') {
        return 1;
    }

    // TODO throw an exception with a meaningful message
    std::exit(-1); // exiting with a code other than zero
}
static constexpr int maxSize = 30; // max capacity of the stack

std::string infToPostf(std::string inf) {
    std::string resPostf = "";
    Stack<char> ops(maxSize);
    for(int i = 0; i < inf.size(); i++) {
        if (isOperand(inf[i])) {
            resPostf += inf[i];
        }
        else if(inf[i] == '(') {
            ops.push(inf[i]);
        }
        else if(inf[i] == ')') {
            while (ops.top() != '(') {
                resPostf += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else {
            while (!ops.isEmpty() && prior(inf[i]) >= prior(ops.top())) {
                resPostf += ops.top();
                ops.pop();
            }
            ops.push(inf[i]);
        }
    }
    while (!ops.isEmpty()) {
        resPostf += ops.top();
        ops.pop();
    }
    return resPostf;
}

int main() {
    std::string inf = "2*3+4*5";
    std::cout << infToPostf(inf) << std::endl;
    return 0;
}
