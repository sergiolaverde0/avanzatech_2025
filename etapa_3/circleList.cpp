#include "circleList.hpp"
#include <iostream>

using namespace std;

template <class T>
CircleList<T>& CircleList<T>::append(const T& value)
{
    Node<T>* current = this->entry;
    while (current->next != this->entry) {
        current = current->next;
    }
    Node<T>* newNode = new Node<T>(value);
    newNode->next = this->entry;
    current->next = newNode;
    return *this;
}

template <class T>
CircleList<T>& CircleList<T>::prepend(const T& value)
{
    Node<T>* current = this->entry;
    while (current->next != this->entry) {
        current = current->next;
    }
    Node<T>* newNode = new Node<T>(value);
    newNode->next = this->entry;
    current->next = newNode;
    this->entry = newNode;
    return *this;
}

template <class T>
CircleList<T>& CircleList<T>::insertBefore(const T& anchor, const T& value)
{
    Node<T>* current = this->entry;
    Node<T>* prev = nullptr;
    while (true) {
        if (current->value == anchor) {
            Node<T>* newNode = new Node<T>(value);
            if (!prev) {
                Node<T>* last = this->entry;
                while (last->next != this->entry) {
                    last = last->next;
                }
                last->next = newNode;
                newNode->next = this->entry;
                this->entry = newNode;
            } else {
                prev->next = newNode;
                newNode->next = current;
            }
            return *this;
        }
        prev = current;
        current = current->next;
        if (current == this->entry) {
            return *this;
        }
    }
}

template <class T>
CircleList<T>& CircleList<T>::insertAfter(const T& anchor, const T& value)
{
    Node<T>* current = this->entry;
    while (true) {
        if (current->value == anchor) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current->next;
            current->next = newNode;
            return *this;
        }
        current = current->next;
        if (current == this->entry) {
            return *this;
        }
    }
}

template <class T>
CircleList<T>& CircleList<T>::remove(const T& value)
{
    Node<T>* current = this->entry;
    Node<T>* prev = nullptr;
    while (true) {
        if (current->value == value) {
            if (!prev) {
                Node<T>* last = this->entry;
                while (last->next != this->entry) {
                    last = last->next;
                }
                last->next = this->entry = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return *this;
        }
        prev = current;
        current = current->next;
        if (current == this->entry) {
            return *this;
        }
    }
}

template <class T>
bool CircleList<T>::search(const T& value)
{
    Node<T>* current = this->entry;
    while (true) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
        if (current == this->entry) {
            return false;
        }
    }
}

template <class T>
void CircleList<T>::print()
{
    Node<T>* current = this->entry;
    while (true) {
        cout << current->value;
        current = current->next;
        if (current == this->entry) {
            cout << endl;
            return;
        }
    }
}

int main()
{
    CircleList<char> a('A');
    a.append('B')
        .append('C')
        .append('D')
        .append('E')
        .prepend('0')
        .remove('C')
        .insertAfter('B', 'Z')
        .insertBefore('A', '9')
        .print();
    return 0;
}
