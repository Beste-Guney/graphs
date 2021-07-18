/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Implementation file for queue
*/
#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

Queue::Queue(){
    front = 0;
    back = QUEUE_SIZE-1;
    count = 0;
}

bool Queue::isEmpty() const{
    return count == 0;
}

bool Queue::enqueue(int newItem){
    if(count == QUEUE_SIZE)
        return false;

    back = (back+1) % QUEUE_SIZE;
    queueIndex[back] = newItem;
    count++;
    return true;
}

bool Queue::dequeue(){
    if(count <= 0)
        return false;
    front = (front +1) % QUEUE_SIZE;
    count--;
    return true;
}

int Queue::getFront(){
    if(isEmpty())
        return false;
    return queueIndex[front];

}
