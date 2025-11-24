#include "prioQueue.hpp"
#include <iostream>

using namespace std;

template <class T>
void PrioQueue<T>::push(const T& value, const int& prio)
{
    Node<T>* newNode = new Node<T>(value, prio);
    // Empty queue
    if (!this->start) {
        this->start = newNode;
        this->end = newNode;
    } else if (this->start->priority < newNode->priority) {
        newNode->next = this->start;
        this->start = newNode;
    } else {
        Node<T>* current = this->start;
        Node<T>* nextNode = current->next;
        while (nextNode && nextNode->priority >= newNode->priority) {
            current = nextNode;
            nextNode = current->next;
        }
        current->next = newNode;
        newNode->next = nextNode;
        if (!nextNode) {
            this->end = newNode;
        }
    }
}

template <class T>
T PrioQueue<T>::pop()
{
    if (this->start) {
        Node<T>* current = this->start;
        T retVal = current->value;
        this->start = current->next;
        delete current;
        if (this->empty()) {
            this->end = nullptr;
        }
        return retVal;
    }
    throw std::runtime_error("You didn't check if stack was empty :(");
}

template <class T>
T& PrioQueue<T>::get()
{
    if (this->start) {
        return this->start->value;
    }
    throw std::runtime_error("You didn't check if stack was empty :(");
}

template <class T>
bool PrioQueue<T>::empty()
{
    return (!this->start);
}

template <class T>
void PrioQueue<T>::clean()
{
    while (!this->empty()) {
        this->pop();
    }
}

int main()
{
    PrioQueue<char> a = PrioQueue<char>();
    a.push('a', 1);
    a.push('0', 2);
    cout << a.get() << endl;
    a.push('E', 0);
    a.pop();
    cout << a.pop() << endl;
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    a.clean();
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    return 0;
}
