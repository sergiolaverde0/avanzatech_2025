#include <iostream>
#include <ostream>

using namespace std;

int main(void)
{
    int value, sum = 0;
    cout << "Give numbers to sum:" << endl;
    while (cin >> value) {
        sum += value;
    }
    cout << "The sum of the given numbers is: " << sum << endl;
}
