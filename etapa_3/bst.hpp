#ifndef BST_HPP
#define BST_HPP

#include "btree.hpp"

template <class T>
class BSTNode : public BTNode<T> {
public:
    explicit BSTNode(const T& value)
        : BTNode<T>(value)
    {
    }
    BSTNode* add_child(const T& value);
};

#endif // !BST_HPP
