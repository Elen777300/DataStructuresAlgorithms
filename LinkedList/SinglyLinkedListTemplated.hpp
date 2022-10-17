//
// Created by Elen Soghomonyan on 17.10.22.
//

#ifndef LINKEDLIST_LINKEDLIST_HPP
#define LINKEDLIST_LINKEDLIST_HPP


#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T value; //Data Item
    Node<T> *next; //Pointer to the next item of the List

    T getValue() {
        return value;
    }
};

/*-------------------------Singly Linked List-------------------------*/
template<typename T>
class List {

private:
    Node<T> *head;

public:
    // Default Constructor
    List() {
        head = nullptr;
    }

    // Copy Constructor
    List(const List<T> &otherList) {
        //If the other list is empty then make the current list empty too.
        if (otherList.head == nullptr) {
            head = nullptr;
        }
            //If the other List isn't empty:
        else {
            Node<T> *current1 = otherList.head;  //current1 points to the other list.

            head = new Node<T>;
            head->value = current1->value;

            current1 = current1->next;

            if (current1 == nullptr)
                head->next = nullptr;

            else {
                Node<T> *current2 = head;    //current2 keeps track of the list being created.

                while (current1 != nullptr) {
                    current2->next = new Node<T>;
                    current2 = current2->next;

                    current2->value = current1->value;
                    current1 = current1->next;
                }

                current2->next = nullptr;
            }
        }

    }

    //Overloaded Assignment Operator
    List<T> &operator=(const List<T> &otherList) {
        if (&otherList != this) {
            if (head != nullptr)                   //If list isn't empty then delete the whole list.
            {
                Node<T> *current = head;

                while (current != nullptr) {
                    Node<T> *temp = current;
                    current = current->next;
                    delete temp;
                }

                head = nullptr;
            }

            //If the other list is empty then make the current list empty too.
            if (otherList.head == nullptr) {
                head = nullptr;
            }

                //If the other List isn't empty:
            else {
                Node<T> *current1 = otherList.head;  //current1 points to the other list.

                head = new Node<T>;
                head->value = current1->value;

                current1 = current1->next;

                if (current1 == nullptr)
                    head->next = nullptr;

                else {
                    Node<T> *current2 = head;    //current2 keeps track of the list being created.

                    while (current1 != nullptr) {
                        current2->next = new Node<T>;
                        current2 = current2->next;

                        current2->value = current1->value;
                        current1 = current1->next;
                    }

                    current2->next = nullptr;
                }
            }

        }

        return *this;
    }


    // Destructor
    ~List() {
        if (head != nullptr) //If list is empty then do nothing.
        {
            Node<T> *current = head;

            while (current != nullptr) {
                Node<T> *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }


    /*------------------- Insertion Functions -------------------*/
    void insertAtHead(T item) {
        auto *temp = new Node<T>;
        temp->value = item;

        temp->next = head;
        head = temp;
    }


    void insertAtTail(T item) {
        auto *temp = new Node<T>;
        temp->value = item;


        Node<T> *current = head;

        if (current == nullptr)  //If the list is empty.
        {
            head = temp;
        } else {
            while (current->next != nullptr)  //Reach the end of the list.
            {
                current = current->next;
            }

            current->next = temp;
        }

        temp->next = nullptr;   //The end item of the list always points to null.
    }


    void insertSorted(T item) {
        auto *temp = new Node<T>;
        temp->value = item;

        Node<T> *current = head;
        Node<T> *previous = nullptr;

        while (current != nullptr && current->value > item) {
            previous = current;
            current = current->next;
        }

        temp->next = current;

        if (current == head) {
            head = temp;
        } else
            previous->next = temp;
    }


    /*------------------- Lookup Functions -------------------*/
    Node<T> *getHead() {
        return head;
    }


    Node<T> *getTail() {
        if (head == nullptr) {
            return nullptr;
        } else {
            Node<T> *current = head;

            while (current->next != nullptr)  //Traverses the whole list till the end is reached.
            {
                current = current->next;
            }

            return current;
        }
    }


    Node<T> *searchFor(T item) {
        if (head == nullptr) {
            return nullptr;
        } else {
            Node<T> *current = head;

            while (current != nullptr && current->value >= item) {
                if (current->value == item) {
                    return current;
                }

                current = current->next;
            }

            return nullptr;
        }
    }


    /*------------------- Deletion Functions -------------------*/

    void deleteElement(T item) {
        if (head != nullptr) //If the list isn't empty.
        {
            Node<T> *current = head;
            Node<T> *previous = head;

            while (current->next != nullptr && current->value > item) {
                previous = current;
                current = current->next;
            }

            //If the element is found.
            if (current->value == item) {
                if (current == head) {
                    head = head->next;
                } else {
                    previous->next = current->next;
                }

                delete current;
            }
        }
    }


    void deleteHead() {
        if (head != nullptr) {
            Node<T> *temp = head->next;
            delete head;
            head = temp;
        }
    }


    void deleteTail() {
        if (head != nullptr) {
            Node<T> *current = head;
            Node<T> *previous = nullptr;

            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }

            if (current == head) {
                head = nullptr;
            } else {
                previous->next = nullptr;
            }

            delete current;
        }
    }


    /*------------------- Utility Functions -------------------*/
    int length() {
        int length = 0;
        Node<T> *current = head;

        while (current != nullptr) {
            length++;
            current = current->next;
        }

        return length;
    }


    void Print() {
        if (head != nullptr) {
            Node<T> *current = head;

            cout << endl << "The list contains: " << endl;

            while (current != nullptr) {
                cout << current->value << endl;
                current = current->next;
            }
        } else
            cout << "\nList is empty.";
    }

    //Overloaded + operator
    List operator+(List<T> &rhs) {
        Node<T> *current1;
        List tempList;
        //Chooses that list which is larger than the other one
        if (length() >= rhs.length()) {
            tempList = *this;

            current1 = rhs.head;
        } else {
            tempList = rhs;

            current1 = head;
        }

        Node<T> *tempPtr = nullptr;

        while (current1 != nullptr)  //Current1 will always keep track of the shorter list
        {
            tempPtr = tempList.searchFor(current1->value);

            if (tempPtr != nullptr) {
                tempPtr->value = (tempPtr->value) + (current1->value);
            } else
                tempList.insertSorted(current1->value);

            current1 = current1->next;
        }

        return tempList;
    }

    //Adds the duplicate values in a list and de-allocates the space consumed by the duplicate
    void addDuplicates() {
        Node<T> *current = head;
        Node<T> *previous = nullptr;

        if (current != nullptr && current->next != nullptr) {
            while (current->next != nullptr) {
                previous = current;
                current = current->next;

                if (previous->value == current->value) {
                    current->value = current->value + previous->value;
                    deleteElement(previous->value);
                }
            }
        }
    }

    //Get element at the desired position, eg 3rd element of list etc
    Node<T> *getDesiredElement(int n) {
        Node<T> *current = head;

        if (n <= length()) {
            while (n != 1) {
                current = current->next;
                n--;
            }
        }

        return current;
    }
};

#endif //LINKEDLIST_LINKEDLIST_HPP
