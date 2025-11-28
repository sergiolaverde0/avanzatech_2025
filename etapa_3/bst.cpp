#include "bst.hpp"
#include <iostream>

using namespace std;

template <class T>
BSTNode<T>* BSTNode<T>::add_child(const T& value)
{
    if (this->value == value) {
        return this;
    }
    if (this->value < value) {
        if (!this->right) {
            BSTNode* child = new BSTNode(value);
            child->parent = this;
            this->right = child;
            return this;
        }
        return static_cast<BSTNode<T>*>(this->right)->add_child(value);
    } else {
        if (!this->left) {
            BSTNode* child = new BSTNode(value);
            child->parent = this;
            this->left = child;
            return this;
        }
        return static_cast<BSTNode<T>*>(this->left)->add_child(value);
    }
}

template <class T>
BSTNode<T>* BSTNode<T>::search(const T& value)
{
    BSTNode<T>* current = this;
    while (current) {
        if (current->value == value) {
            return current;
        }
        if (current->value > value) {
            current = static_cast<BSTNode<T>*>(current->left);
        } else {
            current = static_cast<BSTNode<T>*>(current->right);
        }
    }
    return nullptr;
}

int main(void)
{
    BSTNode<int>* a = new BSTNode<int>(5);
    a->add_child(4);
    a->add_child(7);
    a->add_child(1);
    a->add_child(3);
    a->add_child(6);
    a->add_child(9);
    a->add_child(8);
    a->add_child(10);

    a->preorden(&BTNode<int>::print);
    cout << endl;
    a->inorden(&BTNode<int>::print);
    cout << endl;
    a->posorden(&BTNode<int>::print);
    cout << endl;
    cout << "Height: " << a->height() << endl;
    cout << "Is full?: " << a->full() << endl;
    cout << "Number of nodes: " << a->count() << endl;
    a->search(1)->preorden(&BTNode<int>::print);
    cout << endl;
    delete a;
}
