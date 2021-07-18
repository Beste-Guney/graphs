/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Header file for adjacency matrix implemented graph
*/
#include <iostream>
#include "HashTable.h"
#include <string>
using namespace std;

HashTable::HashTable(int value){
    size = value;
    pointers = new Node*[value];
    for(int i = 0; i < value; i++){
        pointers[i] = NULL;
    }
}

HashTable::~HashTable(){
    for(int i = 0; i < size; i++){
        Node* cur = pointers[i];
        Node* prev = cur->next;
        while(prev != NULL){
            delete cur;
            cur = prev;
            prev = prev->next;

        }
        delete cur;
    }
    delete[] pointers;
}

int HashTable::getSize(){
    return size;
}
int HashTable::hashFunction(const string &key, int tableSize)
{
    int hashVal = 0;
    for (int i = 0; i < key.length(); i++)
    hashVal = 37 * hashVal + key[i];
    hashVal %=tableSize;
    if (hashVal < 0) /* in case overflows occurs */
        hashVal += tableSize;
    return hashVal;
};

int HashTable::returnIndex(int index, string key){
    Node* cur = NULL;;
    for(cur = pointers[index]; cur!= NULL; cur = cur->next){
        if(cur->key == key){
            return cur->index;
        }
    }
    return -1;
}

void HashTable::displayHashTable(){
    for(int i = 0; i < size; i++){
        if(pointers[i] != NULL)
        cout << pointers[i]->key << endl;

    }
}
void HashTable::displayIndex(int index){
    Node* cur = pointers[index];
    while(cur != NULL){
        cout << cur->key << endl;
        cur = cur->next;
    }
}
void HashTable::insertItem(int index, string key, int item){
    if(pointers[index] == NULL){
        pointers[index] = new Node;
        pointers[index]->index = item;
        pointers[index]->key = key;
        pointers[index]->next = NULL;
    }
    else{
        Node* cur = pointers[index];
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new Node;
        cur->next->index = item;
        cur->next->key = key;
        cur->next->next = NULL;
    }
}
