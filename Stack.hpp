//
// Created by Elen Soghomonyan on 16.10.22.
//

// Most of this implementation is copied from somewhere
// but is similar to the one we have implemented

// The definition and the implementation are in the same file for reasons
// For more read https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl

#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <iostream>

template<class T>
class Stack {
public :
    T *m_stack;
    int m_top;
    int m_size;

    explicit Stack(int inVal = 0) {
        if (inVal == 0) {
            std::cout << "\nEnter desired m_size of the m_stack:" << std::endl;
            std::cin >> m_size;
        } else {
            m_size = inVal;
        }
        m_top = -1;
        m_stack = new T[m_size];
    }

    bool isFull() {
        if (m_top == (m_size - 1)) {
            std::cout << "Error: The Stack is full" << std::endl;
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (m_top == -1) {
            std::cout << "Error: The stack is empty" << std::endl;
            return true;
        }
        return false;
    }

    void push(T inVal) {
        if (isFull()) {
            return;
        } else {
            m_stack[++m_top] = inVal;
            std::cout << "stack[" << m_top << "]=" << m_stack[m_top] << " added successfully" << std::endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            std::exit(-1);
        }
        std::cout << "stack[" << m_top << "]=" << m_stack[m_top] << " deleted successfully" << std::endl;
        m_top = m_top - 1;
    }

    T top() {
        if(isEmpty()) {
            std::exit(-1);
        }
        std::cout << "stack[" << m_top << "]=" << m_stack[m_top] << " deleted successfully" << std::endl;
        return m_stack[m_top];
    }
    void print() {
        if (isEmpty()) {
            return;
        }

        for (int i = m_top; i >= 0; i--) {
            if (i == m_top) {
                std::cout << "stack[" << i << "]: " << m_stack[m_top] << " m_top" << std::endl;
            } else if (i == 0) {
                std::cout << "stack[0]: " << m_stack[0] << " bottom" << std::endl;
            } else {
                std::cout << "stack[" << i << "]: " << m_stack[i] << std::endl;
            }
        }
    }
};

#endif //STACK_STACK_HPP
