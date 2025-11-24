#include <iostream>

using namespace std;

class Persona {
private:
    string name;
    int age;

public:
    static int num_instances;
    Persona(const string& nombre, int edad)
        : name(nombre)
        , age(edad)
    {
        this->num_instances += 1;
    }
    ~Persona()
    {
        this->num_instances -= 1;
    }
    void saludar()
    {
        cout << "Hello my name is " << name;
        cout << ", and I am " << age << " years old." << endl;
    }
};
int Persona::num_instances = 0;

int main(void)
{
    cout << Persona::num_instances << endl;
    Persona* diana = new Persona("Diana", 28);
    diana->saludar();
    cout << Persona::num_instances << endl;
    return 0;
}
