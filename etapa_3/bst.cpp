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
            return child;
        }
        return static_cast<BSTNode<T>*>(this->right)->add_child(value);
    } else {
        if (!this->left) {
            BSTNode* child = new BSTNode(value);
            child->parent = this;
            this->left = child;
            return child;
        }
        return static_cast<BSTNode<T>*>(this->left)->add_child(value);
    }
}

int main(void)
{
    BSTNode<int>* a = new BSTNode<int>(55);
    a->add_child(30);
    a->add_child(75);
    a->add_child(4);
    a->add_child(41);
    a->add_child(85);

    a->preorden(&BTNode<int>::print);
    cout << endl;
    a->inorden(&BTNode<int>::print);
    cout << endl;
    a->posorden(&BTNode<int>::print);
    cout << endl;
    cout << "Height: " << a->height() << endl;
    cout << "Is full?: " << a->full() << endl;
    cout << "Number of nodes: " << a->count() << endl;
}
