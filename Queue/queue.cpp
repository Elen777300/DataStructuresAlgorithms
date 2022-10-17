//
// Created by Elen Soghomonyan on 04.10.22.
//
#include "queue.hpp"
#include <iostream>

template<typename T>
Queue<T>::Queue(int n) {
    m_capacity = n;
    m_size = 0;
    m_arr = new T[n];
    m_front = 0;
    m_Rear = -1;
}

template<typename T>
Queue<T>::~Queue() {
    delete[] m_arr;
}

template<typename T>
void Queue<T>::enqueue(T el) {
    if (isFull()) {
        throw 1;
    }
    m_size++;
    m_Rear = (m_Rear + 1) % m_capacity;
    m_arr[m_Rear] = el;
}

template<typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        throw 3;
    }
    m_size--;
    m_front = (m_front + 1) % m_capacity;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    if (m_size == 0) return true;
    return false;
}

template<typename T>
bool Queue<T>::isFull() const {
    return m_size == m_capacity;
}

template<typename T>
T Queue<T>::peek() const {
    if (isEmpty())throw 2;
    return m_arr[m_front];
}

template<typename T>
void Queue<T>::print() {
    for (int i = m_front; i <= m_Rear; i++) {
        std::cout << m_arr[i] << " ";
    }

    std::cout << std::endl;
}

// size-ը չէինք իրականացրել
template<typename T>
int Queue<T>::size() const {
    return m_size;
}

template class Queue<char>; // need to explicitly instantiate