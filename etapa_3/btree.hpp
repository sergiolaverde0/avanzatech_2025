#ifndef BTREE_HPP
#define BTREE_HPP

#include <iostream>

template <class T>
class BTNode {
protected:
    BTNode* parent;
    BTNode* left;
    BTNode* right;

public:
    T value;
    explicit BTNode(const T& value)
        : value(value)
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
    ~BTNode()
    {
        delete left;
        delete right;
        left = right = nullptr;
    }
    BTNode* add_child(const T& value, int pos)
    {
        BTNode* child = new BTNode(value);
        child->parent = this;
        if (pos) {
            right = child;
        } else {
            left = child;
        }
        return child;
    }
    void preorden(void (BTNode<T>::*method)(void))
    {
        (this->*method)();
        if (left) {
            left->preorden(method);
        }
        if (right) {
            right->preorden(method);
        }
    }
    void inorden(void (BTNode<T>::*method)(void))
    {
        if (left) {
            left->inorden(method);
        }
        (this->*method)();
        if (right) {
            right->inorden(method);
        }
    }
    void posorden(void (BTNode<T>::*method)(void))
    {
        if (left) {
            left->posorden(method);
        }
        if (right) {
            right->posorden(method);
        }
        (this->*method)();
    }
    int height(void)
    {
        int left_height = left ? left->height() : 0;
        int right_height = right ? right->height() : 0;
        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
    int count(void)
    {
        int left_count = left ? left->count() : 0;
        int right_count = right ? right->count() : 0;
        return 1 + left_count + right_count;
    }
    bool full(void)
    {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        return left->full() && right->full();
    }
    void print(void)
    {
        std::cout << *this << " ";
    }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const BTNode<U>& node);
};

template <class U>
std::ostream& operator<<(std::ostream& os, const BTNode<U>& node)
{
    os << node.value;
    return os;
}

#endif
