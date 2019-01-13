#include <iostream>
#include <fstream>
using namespace std;

int write_file() {
    string filename = "test.txt";

    /* Option 1 */
    //ofstream outFile;
    //outFile.open(filename);

    /* Option 2 */
    fstream outFile;
    outFile.open(filename, ios::out);

    if(!outFile.is_open()) {
        cout << "couldn't create " << filename << endl;
        return 1;
    }
    outFile << "Hello there!" << endl;
    outFile << 123456 << endl;
    outFile.close();

    return 0;
}

int read_file() {
    string filename = "test.txt";
    
    ifstream inFile;
    inFile.open(filename);
    if(!inFile.is_open()) {
        cout << "couldn't open " << filename << endl;
        return 1;
    }

    while(inFile) {
        string line;
        getline(inFile, line);
        cout << line << endl;
    }
    
    inFile.close();

    return 0;
}

int parse_file() {
    string filename = "population.txt";
    
    ifstream inFile;
    inFile.open(filename);
    if(!inFile.is_open()) {
        cout << "couldn't open " << filename << endl;
        return 1;
    }

    while(inFile) {
        string line;
        int population;

        getline(inFile, line, ':');
        inFile >> population;
        /* Ignore netline / whitespace */
        //inFile.get(); // ignore newline character
        inFile >> ws; // Works from C++ 11


        if(!inFile) {
            break;
        }
        
        cout << line << " is " << population << endl;        
    }
    
    inFile.close();

    return 0;
}

#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int write_read_binary() {
    string filename="test.bin";
    Person person = {"Test Person", 41, 1.80};
    
    cout << sizeof(Person) << endl;

    ofstream outFile;
    outFile.open(filename, ios::binary);
    if(!outFile.is_open()) {
        cout << "couldn't create " << filename << endl;
        return 1;
    }

    // outFile.write((char *)&person, sizeof(person)); // old way
    outFile.write(reinterpret_cast<char *>(&person), sizeof(Person)); // new way
    outFile.close();

    ifstream inFile;
    inFile.open(filename, ios::binary);
    if(!inFile.is_open()) {
        cout << "couldn't open " << filename << endl;
        return 1;
    }

    Person anotherPerson;
    // outFile.write((char *)&person, sizeof(person)); // old way
    inFile.read(reinterpret_cast<char *>(&anotherPerson), sizeof(Person)); // new way
    inFile.close();

    cout << anotherPerson.name << " is " << anotherPerson.age << " years old and " << anotherPerson.height << "m tall" << endl;

    return 0;
}

int main() {
    int err;

    err = write_file();
    if(err != 0) {
        return err;
    }

    err = read_file(); 
    if(err != 0) {
        return err;
    }

    err = parse_file(); 
    if(err != 0) {
        return err;
    }

    err = write_read_binary(); 
    if(err != 0) {
        return err;
    }
    
    return 0;
}