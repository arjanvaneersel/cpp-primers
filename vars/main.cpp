#include <iostream>
using namespace std;

int main() {
    int a = 10;
    float b = 3.4;
    char c = 'a';
    bool d = true;

    cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d;
    cout << "\nEnter a new number for a:" << endl;
    cin >> a;
    cout << "\nYou entered: " << a << endl; 
    
    int e = 0, f = 0, tmp = 0;
    cout << "Enter a value for e and f:" << endl;
    cin >> e >> f;

    tmp = e;
    e = f;
    f = tmp;
    cout << "e: " << e << " f: " << f << endl;

    return 0;
}