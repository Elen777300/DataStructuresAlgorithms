#include <iostream>
#include "queue.hpp"

int main() {
    Queue<char> q1(10);

    try {
        q1.enqueue('7');
        q1.print();

        std::cout << q1.peek() << std::endl;
        q1.enqueue('6');
        q1.enqueue('5');
        q1.enqueue('4');
        q1.enqueue('3');
        q1.enqueue('2');
        q1.print();
        std::cout << q1.size();

        q1.dequeue();
        std::cout << q1.peek() << std::endl;

        q1.print();
    } catch (...) {
        std::cout << "Something bad happened! To learn more make your error handling more informative\n";
    }
    return 0;
}