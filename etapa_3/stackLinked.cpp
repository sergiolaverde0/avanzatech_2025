#include "stackLinked.hpp"
#include <iostream>

using namespace std;

template <class T>
void StackLinked<T>::push(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = this->peak;
    this->peak = newNode;
}

template <class T>
T StackLinked<T>::pop(void)
{
    if (this->peak) {
        Node<T>* current = this->peak;
        T retVal = current->value;
        this->peak = current->next;
        delete current;
        return retVal;
    }
    throw std::runtime_error("You didn't check if stack was empty :(");
}

template <class T>
T& StackLinked<T>::get()
{
    if (this->peak) {

        return this->peak->value;
    } else {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
}

template <class T>
bool StackLinked<T>::empty()
{
    return !(this->peak);
}

template<class T>
void StackLinked<T>::clean(){
    while (!this->empty()) {
        this->pop();
    }
}

int main()
{
    StackLinked<char> a = StackLinked<char>();
    a.push('A');
    a.push('B');
    cout << a.get() << endl;
    a.push('C');
    cout << a.pop() << endl;
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    a.clean();
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    return 0;
}
