//
// Created by Elen Soghomonyan on 04.10.22.
//

#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

template<typename T=char>
class Queue {
private:
    T *m_arr;
    int m_size;
    int m_capacity;
    int m_front;
    int m_Rear;

public:
    explicit Queue(int);

    ~Queue();

    void enqueue(T);

    void dequeue();

    T peek() const;

    bool isEmpty() const;

    bool isFull() const;

    int size() const;

    void print();
};
#endif //QUEUE_QUEUE_HPP
