#include "queueLinked.hpp"
#include <iostream>

using namespace std;

template <class T>
void QueueLinked<T>::push(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if (this->end) {

        this->end->next = newNode;
    }
    this->end = newNode;
    if (!this->start) {
        this->start = newNode;
    }
}

template <class T>
T QueueLinked<T>::pop()
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
T& QueueLinked<T>::get()
{
    if (this->start) {
        return this->start->value;
    }
    throw std::runtime_error("You didn't check if stack was empty :(");
}

template <class T>
bool QueueLinked<T>::empty()
{
    return (!this->start);
}

template <class T>
void QueueLinked<T>::clean()
{
    while (!this->empty()) {
        this->pop();
    }
}

int main()
{
    QueueLinked<char> a = QueueLinked<char>();
    a.push('A');
    a.push('B');
    cout << a.get() << endl;
    a.push('C');
    a.pop();
    cout << a.pop() << endl;
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    a.clean();
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    return 0;
}
