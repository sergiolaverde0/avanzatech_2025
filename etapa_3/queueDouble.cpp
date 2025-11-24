#include "queueDouble.hpp"
#include <iostream>

using namespace std;

template <class T>
void QueueDouble<T>::push_front(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->prev = this->front;
    if (this->front) {
        this->front->next = newNode;
    } else {
        this->back = newNode;
    }
    this->front = newNode;
}

template <class T>
void QueueDouble<T>::push_back(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = this->back;
    if (this->back) {

        this->back->prev = newNode;
    } else {
        this->front = newNode;
    }
    this->back = newNode;
}

template <class T>
T QueueDouble<T>::pop_front()
{
    if (!this->front) {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
    Node<T>* current = this->front;
    T retVal = current->value;
    // If last element
    if (this->front == this->back) {
        this->front = this->back = nullptr;
        // If there are remaining elements
    } else {
        this->front = current->prev;
        this->front->next =  nullptr;
    }
    delete current;
    return retVal;
}

template <class T>
T QueueDouble<T>::pop_back()
{
    if (!this->back) {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
    Node<T>* current = this->back;
    T retVal = current->value;
    // If last element
    if (this->front == this->back) {
        this->front = this->back = nullptr;
        // If there are remaining elements
    } else {
        this->back = current->next;
        this->back->prev = nullptr;
    }
    delete current;
    return retVal;
}

template <class T>
T& QueueDouble<T>::get_front()
{
    if (!this->back) {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
    return this->back->value;
}

template <class T>
T& QueueDouble<T>::get_back()
{
    if (!this->front) {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
    return this->front->value;
}

template <class T>
bool QueueDouble<T>::empty()
{
    return !this->front;
}

template <class T>
void QueueDouble<T>::clean()
{
    while (this->front) {
        this->pop_front();
    }
}

int main()
{
    QueueDouble<char> a = QueueDouble<char>();
    a.push_back('A');
    a.push_front('B');
    a.push_back('9');
    a.push_front('C');
    cout << a.pop_back() << endl;
    cout << a.pop_front() << endl;
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    a.clean();
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    return 0;
}
