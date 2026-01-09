#include "sergio_laverde_taller_4.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cout << "--- Begin test of the first implementation ---" << endl;
    Impl1 test_class_1 = Impl1();

    test_class_1.add("test_string_one");
    test_class_1.add("test_string_two");
    test_class_1.add("yet another test string");
    test_class_1.add("earlier string");
    test_class_1.add("middle string");

    cout << (test_class_1.check("test_string_one") ? "Success" : "Failure") << endl;
    cout << (test_class_1.check("earlier string") ? "Success" : "Failure") << endl;
    cout << (!test_class_1.check("missing string") ? "Success" : "Failure") << endl;
    cout << (!test_class_1.check("test") ? "Success" : "Failure") << endl;
    cout << "--- End test of the first implmentation ---" << endl
         << endl;

    cout << "--- Begin test of the second implementation ---" << endl;
    Impl2 test_class_2 = Impl2();
    test_class_2.add("test_string_one");
    test_class_2.add("test_string_two");
    test_class_2.add("yet another test string");
    test_class_2.add("earlier string");
    test_class_2.add("middle string");

    cout << (test_class_2.check("test_string_one") ? "Success" : "Failure") << endl;
    cout << (test_class_2.check("earlier string") ? "Success" : "Failure") << endl;
    cout << (!test_class_2.check("missing string") ? "Success" : "Failure") << endl;
    cout << (!test_class_2.check("test") ? "Success" : "Failure") << endl;
    cout << "--- End test of the second implmentation ---" << endl
         << endl;

    cout << "--- Begin test of the third implementation ---" << endl;
    Impl3 test_class_3 = Impl3();
    test_class_3.add("test_string_one");
    test_class_3.add("test_string_two");
    test_class_3.add("yet another test string");
    test_class_3.add("earlier string");
    test_class_3.add("middle string");

    cout << (test_class_3.check("test_string_one") ? "Success" : "Failure") << endl;
    cout << (test_class_3.check("earlier string") ? "Success" : "Failure") << endl;
    cout << (!test_class_3.check("missing string") ? "Success" : "Failure") << endl;
    cout << (!test_class_3.check("test") ? "Success" : "Failure") << endl;
    cout << "--- End test of the third implmentation ---" << endl
         << endl;

    return 0;
}
