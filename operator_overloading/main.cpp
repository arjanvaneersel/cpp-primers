#include <iostream>
using namespace std;

class Test {
    private:
        int id;
        string name;
    public:
        Test(): id(0), name("") {}
        Test(int id, string name): id(id), name(name) {}
        Test(const Test &other) { *this = other; }
        // Rule of 3 in C++: Copy initialiator, overloaded assign operator, destructor. Define all or none!
        ~Test() {}

    void print() {
        cout << id << ": " << name << flush;
    }

    void println() {
        cout << id << ": " << name << endl;
    }

    // assignment operator 
    // required when a shallow copy isn't good enough and a deep copy is needed
    // although a void declaration would do, because of the explicit type return
    // chaining is supported: test1 = test2 = test3;
    // const is used, because we're not changing anything at other
    // references are used to prevent copying the whole object
    const Test &operator=(const Test &other) {
        id = other.id;
        name = other.name;
        return *this;
    }
};

int main() {
    Test test1(10, "Snoepie");
    test1.println();
    
    Test test2(20, "Paris");
    test2.println();

    Test test3 = test2;
    test3.println();
    test3 = test1;
    test3.println();

    // Copy initialization
    Test test4 = test1;
    test4.println();

    return 0;
}