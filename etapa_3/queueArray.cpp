#include "queueArray.hpp"
#include <iostream>

using namespace std;

template <class T>
void QueueArray<T>::push(const T& value)
{
    if (this->used == this->capacity) {

        throw std::overflow_error("You didn't check if there was room :(");
    }
    this->array[this->tail++] = value;
    this->tail %= this->capacity;
    this->used += 1;
}

template <class T>
T QueueArray<T>::pop()
{
    if (this->used == 0) {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
    T retVal = this->array[this->head++];
    this->used -= 1;
    this->head %= this->capacity;
    return retVal;
}

template <class T>
T& QueueArray<T>::get()
{
    if (this->used == 0) {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
    return this->array[this->head];
}

template <class T>
bool QueueArray<T>::empty()
{
    return (this->used == 0);
}

template <class T>
bool QueueArray<T>::full()
{
    return (this->used == this->capacity);
}

template <class T>
void QueueArray<T>::clean()
{
    this->head = this->tail;
    this->used = 0;
}

int main()
{
    QueueArray<char> a = QueueArray<char>(32);
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
