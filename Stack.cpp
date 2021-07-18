/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Header file for adjacency matrix implemented graph
*/
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack(){
    top = -1;
}

bool Stack::isEmpty() const{
    return top == -1;
}
int Stack::getSize(){
    return top + 1;
}
bool Stack::push(int newItem){
    if(top > STACK_SIZE){
        return false;
    }
    else{
        top++;
        indexes[top] = newItem;
        return true;
    }
}

bool Stack::pop(){
    if(isEmpty())
        return false;
    else{
        top--;
        return true;
    }
}

bool Stack::pop(int& stackTop){
    if(isEmpty())
        return false;
    else{
        stackTop = indexes[top];
        top--;
        return true;
    }
}

int Stack::getTop() const{
    if(isEmpty())
        return false;
    else{
        return  indexes[top];
    }
}

