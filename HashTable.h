/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Header file for adjacency matrix implemented graph
*/
#include <iostream>
#include <string>
using namespace std;
class HashTable{
public:
    HashTable(int value);
    ~HashTable();

    int hashFunction(const string&, int tablesize);
    void insertItem(int index, string, int);
    int returnIndex(int index, string);
    int getSize();
    void displayHashTable();
    void displayIndex(int index);

private:
    struct Node{
        string key;
        int index;
        Node* next;
    };
    int size;
    Node** pointers;
};


