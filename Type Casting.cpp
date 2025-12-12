#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() { cout << "Derived class\n"; }
};

int main() {

    cout << "=== Implicit Type Casting ===\n";
    int a = 10;
    float b = a;           // int → float (implicit)
    cout << "int: " << a << " -> float: " << b << "\n\n";


    cout << "=== Explicit Type Casting ===\n";
    float x = 5.75;
    int y = (int)x;        // float → int (explicit)
    cout << "float: " << x << " -> int: " << y << "\n\n";


    cout << "=== Dynamic Casting ===\n";
    Base *basePtr = new Derived();   // Upcast
    Derived *derivedPtr = dynamic_cast<Derived*>(basePtr);  // Downcast

    if (derivedPtr)
        cout << "dynamic_cast successful (Base* -> Derived*)\n";
    else
        cout << "dynamic_cast failed\n";

    return 0;
}
