#include <iostream>
#include <exception>
using namespace std;

class MyException: public exception {
public:
    virtual const char* what() {
        return "something bad happened";
    }
};

class Test {
public:
    void goesWrong() {
        throw MyException();
    }
};

void mightGoWrong() {
    //throw 8;
    //throw "this is an error";
    //throw string("something went wrong again");
    Test test;
    test.goesWrong();
}

int main() {
    try {
        mightGoWrong();
    } catch(int e) {
        cout << "received error: " << e << endl;
        return e;
    } catch(char const* e) {
        cout << "received error: " << e << endl;
        return 1;
    } catch(string& e) {
        cout << "received error: " << e << endl;
        return 1;
    } catch(MyException& e) {
        cout << "received error: " << e.what() << endl;
    }
    return 0;
}