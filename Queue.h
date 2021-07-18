/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Header file for queue
*/

const int QUEUE_SIZE = 5757;

class Queue{
public:
    Queue();
    bool isEmpty() const;
    bool enqueue(int );
    bool dequeue();
    int getFront();

private:
    int front, back, count;
    int queueIndex[QUEUE_SIZE];
};

