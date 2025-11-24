#include "dbl_linked_list.hpp"
#include "iostream"

using namespace std;

template <class T>
DblLinkedList<T>& DblLinkedList<T>::append(const T& value)
{
    Node<T>* current = this->head;
    while (current->next) {
        current = current->next;
    }
    Node<T>* newNode = new Node<T>(value);
    current->next = newNode;
    newNode->prev = current;
    this->tail = newNode;
    return *this;
}

template <class T>
DblLinkedList<T>& DblLinkedList<T>::prepend(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = this->head;
    this->head->prev = newNode;
    this->head = newNode;
    return *this;
}

template <class T>
DblLinkedList<T>& DblLinkedList<T>::insertBefore(const T& anchor, const T& value)
{
    Node<T>* current = this->head;
    while (current) {
        if (current->value == anchor) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            } else {
                this->head = newNode;
            }
            current->prev = newNode;
            return *this;
        }
        current = current->next;
    }
    return *this;
}

template <class T>
DblLinkedList<T>& DblLinkedList<T>::insertAfter(const T& anchor, const T& value)
{
    Node<T>* current = this->head;
    while (current) {
        if (current->value == anchor) {
            Node<T>* newNode = new Node<T>(value);
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next) {
                current->next->prev = newNode;
            } else {
                this->tail = newNode;
            }
            current->next = newNode;
            return *this;
        }
        current = current->next;
    }
    return *this;
}

template <class T>
T DblLinkedList<T>::first(void)
{
    return head->value;
}

template <class T>
T DblLinkedList<T>::last(void)
{
    return tail->value;
}

template <class T>
DblLinkedList<T>& DblLinkedList<T>::remove(const T& value)
{
    Node<T>* current = this->head;
    while (current) {
        if (current->value == value) {
            if (!current->prev) {
                this->head = current->next;
                current->next->prev = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return *this;
        }
        current = current->next;
    }
    return *this;
}

template <class T>
bool DblLinkedList<T>::search(const T& value)
{
    Node<T>* current = this->head;
    while (true) {
        if (current->value == value) {
            return true;
        }
        if (!current->value == value) {
            return false;
        }
        current = current->next;
    }
}

template <class T>
void DblLinkedList<T>::print()
{
    Node<T>* current = this->head;
    while (current) {
        cout << current->value;
        current = current->next;
    }
    cout << endl;
}

int main()
{
    DblLinkedList<char> a('A');
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
