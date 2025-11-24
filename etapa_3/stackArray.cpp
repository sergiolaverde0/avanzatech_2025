#include "stackArray.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
void StackArray<T>::push(const T& value)
{
    if (this->peak + 1 == this->capacity) {
        throw std::overflow_error("You didn't check if there was room :(");
    }
    this->array[++peak] = value;
}

template <class T>
T& StackArray<T>::pop()
{
    if (this->peak != -1) {
        return this->array[peak--];
    }
    throw std::underflow_error("You didn't check if stack was empty :(");
}

template <class T>
void StackArray<T>::clean()
{
    this->peak = -1;
}

template <class T>
T& StackArray<T>::get()
{
    if (this->peak != -1) {
        return this->array[peak];
    } else {
        throw std::runtime_error("You didn't check if stack was empty :(");
    }
}

template <class T>
bool StackArray<T>::empty()
{
    return (this->peak == -1);
}

int main()
{
    StackArray<char> a = StackArray<char>(32);
    a.push('A');
    a.push('B');
    cout << a.get() << endl;
    a.push('C');
    cout << a.pop() << endl;
    cout << (a.empty() ? "Empty" : "Not empty") << endl;
    a.clean();
    return 0;
}
