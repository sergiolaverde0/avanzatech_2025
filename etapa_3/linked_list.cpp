#include "linked_list.hpp"

using namespace std;

int main()
{
    LinkedList<char> a('A');
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
