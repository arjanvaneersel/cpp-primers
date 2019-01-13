#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

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

    return 0;
}