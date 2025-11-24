#include "Sales_item.h"
#include <iostream>

using namespace std;

int main()
{
    Sales_item total, current;
    if (cin >> total) {
        while (cin >> current) {
            if (current.isbn() == total.isbn()) {
                total += current;
            } else {
                cout << total << endl;
                total = current;
            }
        }
        cout << total << endl;
    } else {
        cerr << "No input!" << endl;
        return -1;
    }
    return 0;
}
