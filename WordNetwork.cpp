/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : İmplementation file for word network
*/
#include <iostream>
#include "WordNetwork.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

WordNetwork::WordNetwork(const string vertexFile, const string edgeFile){
    hashTable = new HashTable(571);
    graph = new Graph;
    wordArray = new string[MATRIX_SIZE];

    //fstream to open the file
    ifstream file;
    file.open(vertexFile);
    int lineNumber = 0;

    if(file.is_open()){
        string line;

        while(getline(file, line))
        {
            int index = hashTable->hashFunction(line,hashTable->getSize());
            hashTable->insertItem(index,line, lineNumber);
            wordArray[lineNumber] = line;
            lineNumber++;
        }
    }

    ifstream file2;
    file2.open(edgeFile);
    if(file2.is_open()){
        string line;

        while(getline(file2,line)){
            string rowWord = line.substr(0, line.find(","));
            string columnWord = line.substr(line.find(",")+1,line.length());

            //putting these words into hash function
            int rowIndex = hashTable->hashFunction(rowWord,hashTable->getSize());
            int columnIndex = hashTable->hashFunction(columnWord,hashTable->getSize());

            graph->makeConnection(hashTable->returnIndex(rowIndex,rowWord), hashTable->returnIndex(columnIndex,columnWord));
        }
    }
}

WordNetwork::~WordNetwork(){
    delete hashTable;
    delete graph;
    delete[] wordArray;
}
void WordNetwork::displayGraph(){
    graph->displayGraph();
}

void WordNetwork::listNeighbors ( const string word ){
    int index = hashTable->returnIndex(hashTable->hashFunction(word,hashTable->getSize()),word);
    if(index == -1){
        cout << "Word does not exist " << endl;
        return;
    }
    int arraySize = 0;
    int* neighbors = NULL;
    neighbors = graph->findNeighbours(index, arraySize);

    if(arraySize == 0){
        cout << "No neighbors " << endl;
        return;
    }
    cout << "Neighbors of " << word << endl;

    for(int i = 0; i < arraySize; i++){
        cout << wordArray[neighbors[i]] << endl;
    }
    delete[] neighbors;
}

void WordNetwork::listNeighbors(const string word, const int distance){
    int index = hashTable->returnIndex(hashTable->hashFunction(word,hashTable->getSize()),word);

    int predecessor[MATRIX_SIZE];
    int distances[MATRIX_SIZE];

    Queue myQueue;
    bool* isVisited = new bool[MATRIX_SIZE];

    for(int i = 0; i < MATRIX_SIZE; i++){
        isVisited[i] = false;
        predecessor[i] = -1;
    }

    isVisited[index] = true;
    myQueue.enqueue(index);
    distances[index] = 0;

    cout << "Neighbors at distance " << distance << " to " << word << ":" <<  endl;
    if(distance == 0){
        cout << word << endl;
    }


    while(!myQueue.isEmpty()){
        int value = myQueue.getFront();
        myQueue.dequeue();
        int neighborSize, *neighbors;
        neighbors = graph->findNeighbours(value,neighborSize);
        for(int i = 0; i < neighborSize; i++){
            if(!isVisited[neighbors[i]]){
                isVisited[neighbors[i]] = true;
                predecessor[neighbors[i]] = value;
                distances[neighbors[i]] = distances[predecessor[neighbors[i]]] + 1;
                myQueue.enqueue(neighbors[i]);


            if(distances[neighbors[i]] == distance){
                int value = neighbors[i];
                int index = predecessor[neighbors[i]];
                string str = "";

                while(index != -1){
                    str = wordArray[index] + "->" + str;
                    index = predecessor[index];
                }
                cout << str;
                cout << wordArray[neighbors[i]] << endl;
            }
        }
        }
        delete[] neighbors;
    }
    delete[] isVisited;
}

void WordNetwork::displayHash(){
    hashTable->displayHashTable();
}

void WordNetwork::listConnectedComponents(){
    bool* isVisited  = new bool[MATRIX_SIZE];
    for(int i = 0; i < MATRIX_SIZE; i++)
        isVisited[i] = false;
    int current = 0;
    for(int i = 0; i < MATRIX_SIZE; i++){

        if(!isVisited[i]){
            current++;
        cout << "Connected component " << current << endl;
            printDFT(i,isVisited);
            cout << endl;
        }
    }
    delete[] isVisited;
}
void WordNetwork::printDFT(int startPoint, bool* isVisited){
    isVisited[startPoint] = true;
    cout << wordArray[startPoint] << endl;

    for(int i = 0; i < MATRIX_SIZE; i++){
        if(graph->isConnected(startPoint, i) && !isVisited[i]){
            printDFT(i,isVisited);
        }
    }
}
void WordNetwork::printDFT(int startPoint){
    Stack myStack;
    bool* isVisited = new bool[MATRIX_SIZE];

    for(int i = 0; i < MATRIX_SIZE; i++){
        isVisited[i] = false;
    }

    isVisited[startPoint] = true;
    myStack.push(startPoint);

    cout << "Connected component " << startPoint+1 << endl;
    cout << wordArray[startPoint] << endl;

    while(!myStack.isEmpty()){
        int current;
        int i;

        current = myStack.getTop();

        for(i = 0; i < MATRIX_SIZE; i++){
            if(graph->isConnected(current, i) && !isVisited[i]){
                myStack.push(i);
                cout << wordArray[i] << endl;
                isVisited[i] = true;
            }
        }
        if(i == MATRIX_SIZE)
            myStack.pop();

    }

    delete []isVisited;
}



void WordNetwork::findShortestPath ( const string word1 , const string word2 ){
    int index1 = hashTable->returnIndex(hashTable->hashFunction(word1,hashTable->getSize()),word1);
    int index2 = hashTable->returnIndex(hashTable->hashFunction(word2,hashTable->getSize()),word2);

    if(index1 == index2)
    {
      cout << "Shortest path from "<< word1 <<  " to " << word2 << ": " << endl;
      cout << word1 << endl;
      return;
    }
    int predecessor[MATRIX_SIZE]; // holds the path
    bool found = false;
    Queue myQueue;
    bool* isVisited = new bool[MATRIX_SIZE];

    for(int i = 0; i < MATRIX_SIZE; i++){
        isVisited[i] = false;
        predecessor[i] = -1;
    }

    isVisited[index1] = true;
    myQueue.enqueue(index1);

    while(!myQueue.isEmpty()){
        int value = myQueue.getFront();
        myQueue.dequeue();
        int neighborSize,*neighbors;
        neighbors = graph->findNeighbours(value, neighborSize);

        for(int i = 0; i < neighborSize; i++){
            if(!isVisited[neighbors[i]]){
                isVisited[neighbors[i]] = true;
                predecessor[neighbors[i]] = value;
                myQueue.enqueue(neighbors[i]);

                if(neighbors[i] == index2){
                    found = true;
                    int path[MATRIX_SIZE];
                    int index = 0;
                    int dest = index2;
                    while(predecessor[dest] != -1){
                        path[index] = predecessor[dest];
                        dest = predecessor[dest];
                        index++;
                    }
                    int orgPath[index];
                    for(int i = 0; i < index; i++){
                        orgPath[i] = path[i];
                    }

                    cout << "Shortest path from "<< word1 <<  " to " << word2 << ": " << endl;
                    for(int i = index-1; i >= 0 ; i--){
                        cout << wordArray[orgPath[i]] << endl;
                    }
                    cout << word2 << endl;
                    i = neighborSize;
                }
            }

        }
        delete[] neighbors;

    }
    if(!found)
        cout << "No path exists " << endl;
    delete[] isVisited;
}
