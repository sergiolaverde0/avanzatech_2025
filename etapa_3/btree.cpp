#include "btree.hpp"
#include <iostream>

using namespace std;

int main(void)
{
    BTNode<char>* a = new BTNode<char>('A');
    BTNode<char>* b = a->add_child('B', 0);
    BTNode<char>* c = a->add_child('C', 1);
    BTNode<char>* d = b->add_child('D', 0);
    BTNode<char>* e = b->add_child('E', 1);
    BTNode<char>* f = c->add_child('F', 1);
    BTNode<char>* g = e->add_child('G', 0);
    BTNode<char>* h = e->add_child('H', 1);
    BTNode<char>* i = f->add_child('I', 0);

    a->preorden(&BTNode<char>::print);
    cout << endl;
    a->inorden(&BTNode<char>::print);
    cout << endl;
    a->posorden(&BTNode<char>::print);
    cout << endl;
    cout << "Height: " << a->height() << endl;
    cout << "Is full?: " << a->full() << endl;
    cout << "Number of nodes: " << a->count() << endl;
}
