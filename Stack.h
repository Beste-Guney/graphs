/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Header file for stack
*/

const int STACK_SIZE = 5757;
class Stack{
public:
    Stack();
    bool isEmpty() const;
    bool push(int newItem);
    bool pop();
    bool pop(int& stackTop);
    int getTop() const;
    int getSize();

private:
    int indexes[STACK_SIZE];
    int top;
};

