#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Test {
private:
    string name;
public:
    Test(string name): name(name) {}
    ~Test() {
        //cout << name << " destroyed" << endl;
    }

    void print() {
        cout << name << flush;
    }

    void println() {
        cout << name << endl;
    }
};

void stack_example() {
    // stack = last in, first out
    stack<Test> tests;

    tests.push(Test("Snoepie"));
    tests.push(Test("Jocelyn"));
    tests.push(Test("Charlie"));

    // stacks can't be iterated! values can only be popped off
    /* The code below is very BAD code, because we're using a reference to an object which has been destroyed
    Test &test1 = tests.top();
    tests.pop();
    test1.println(); */

    while(tests.size() > 0) {
        Test &test = tests.top();
        test.println();
        tests.pop();
    }
}

void queue_example() {
    // queue = first in, first out
    queue<Test> tests;

    tests.push(Test("Snoepie"));
    tests.push(Test("Jocelyn"));
    tests.push(Test("Charlie"));

    while(tests.size() > 0) {
        Test &test = tests.front();
        test.println();
        tests.pop();
    }
}

class Dog {
private:
    string name;
    int age;
public:
    //constructors
    Dog(): name(""), age(0) {} // Default constructor. Not ideal, better is to override the assignment operator
    Dog(string name, int age): name(name), age(age) {}
    Dog(const Dog &other) {
        //cout << "Copy constructor running" << endl;
        name = other.name;
        age = other.age;
    }

    // print function works, but better is to override the << operator
    // the const keyword matters to be able to use the class as a map key
    void print() const {
        cout << name << ": " << age << flush;
    }

    void println() const {
        cout << name << ": " << age << endl;
    }

    bool operator<(const Dog &other) const {
        if(name == other.name) {
            return age < other.age;
        }
        return name < other.name;
    }

    // through the friend keyword the older function gets access to private vars of dog
    friend bool by_age(const Dog& a, const Dog& b);
};

bool by_age(const Dog& a, const Dog& b) {
    return a.age < b.age;
}

void map_with_custom_objects() {
    map<int, Dog> dogs;
    dogs[0] = Dog("Snoepie", 5);
    dogs[1] = Dog("Jocelyn", 2);
    dogs[2] = Dog("Charlie", 9);
    dogs[3] = Dog(dogs[0]);

    for (map<int, Dog>::iterator it = dogs.begin(); it != dogs.end(); it++) {
        cout << "[" << it->first << "] " << flush;
        it->second.print();
        cout << endl;
    }

    map<Dog, string> toys;
    toys[Dog("Snoepie", 5)] = "octopus";
    toys[Dog("Jocelyn", 2)] = "whale";
    toys[Dog("Charlie", 9)] = "ball";
    toys[Dog("Charlie", 7)] = "frisbee";

    for (map<Dog, string>::iterator it2 = toys.begin(); it2 != toys.end(); it2++) {
        it2->first.print();
        cout << " years old and has a " << it2->second << endl;
    }
}

void multimap_example() {
    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Snoepie"));
    lookup.insert(make_pair(10, "Jocelyn"));
    lookup.insert(make_pair(40, "Charlie"));
    lookup.insert(make_pair(10, "Becky"));
    lookup.insert(make_pair(100, "Bobcho"));
    lookup.insert(make_pair(10, "Rolli"));

    for(multimap<int, string>::iterator it=lookup.begin(); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // Will not work as expected
    for(multimap<int, string>::iterator it=lookup.find(10); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // Default
    // pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(10);
    // from C++ 11 the auto keyword can be used
    auto its = lookup.equal_range(10);
    for(multimap<int, string>::iterator it=its.first; it != its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }
 }

 void set_example() {
    // sets only store unique elements and won't allow double values to be inserted.
    // if set is to be used with a custom type then the < operator needs to be overloaded
    set<int> numbers;

    numbers.insert(1);
    numbers.insert(3);
    numbers.insert(5);
    numbers.insert(3);
    numbers.insert(2);

    for(set<int>::iterator it=numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
 }

 void sorting_vectors_example() {
    vector<Dog> dogs;
    dogs.push_back(Dog("Snoepie", 5));
    dogs.push_back(Dog("Jocelyn", 2));
    dogs.push_back(Dog("Charlie", 9));

    // std::sort will work because of the < operator override
    sort(dogs.begin(), dogs.end());
    for(long unsigned int i=0; i < dogs.size(); i++) {
        dogs[i].println();
    }

    cout << endl;

    // use a function for sorting
    sort(dogs.begin(), dogs.end(), by_age);
    for(long unsigned int i=0; i < dogs.size(); i++) {
        dogs[i].println();
    }
 }

int main() {
    /* Vectors */
    // vector <string> strings(5);

    vector <string> strings;
    strings.push_back("bird");
    strings.push_back("dog");
    strings.push_back("donkey");

    for(vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }

    cout << endl;

    for(vector<string>::iterator it = strings.end(); it >= strings.begin(); it--) {
        cout << *it << endl;
    }

    cout << "-------------------------------------------------" << endl;

    /* Multi-dimentional vectors */
    vector<vector<int>> grid(3, vector<int>(4, 5)); // 3 rows, 4 columns with an initial value of 5 (optional)
    cout << "[2,3]: " << grid[2][3] << endl;

    cout << "-------------------------------------------------" << endl;

    /* Lists */
    // Lists have notes, which have a pointer to the previous node
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator it=numbers.begin();
    it++;
    numbers.insert(it, 5);

    for(it = numbers.begin(); it != numbers.end();) {
        cout << *it << endl;
        if(*it == 5) {
            it = numbers.erase(it);
        } else {
            it++;
        }
    }

    cout << endl;

    for(it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    cout << "-------------------------------------------------" << endl;

    /* Maps */
    map<string, int> dogs;
    dogs["charlie"] = 9;
    dogs["snoepie"] = 5;
    dogs["jocelyn"] = 2;
    cout << "Age of Snoepie: " << dogs["snoepie"] << endl;

    if(dogs.find("bobcho") == dogs.end()) {
        cout << "Bobcho isn't in the map" << endl;
    }

    dogs.insert(pair<string, int>("bobcho", 13));
    dogs.insert(make_pair("rolli", 7));

    for(map<string, int>::iterator it = dogs.begin(); it != dogs.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    for(map<string, int>::iterator it = dogs.begin(); it != dogs.end(); it++) {
        pair<string, int> data = *it;
        cout << data.first << ": " << data.second << endl;
    }

    cout << "-------------------------------------------------" << endl;

    map_with_custom_objects();

    cout << "-------------------------------------------------" << endl;

    multimap_example();

    cout << "-------------------------------------------------" << endl;

    set_example();

    cout << "-------------------------------------------------" << endl;

    stack_example();

    cout << "-------------------------------------------------" << endl;

    queue_example();

    cout << "-------------------------------------------------" << endl;

    sorting_vectors_example();

    return 0;
}