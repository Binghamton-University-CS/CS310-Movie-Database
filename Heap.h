#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include "Array.h"
#include "Actor.h"

using namespace std;
class Heap{
    private:
        Array<Actor*> arr; 
        
    public:
        int Perlocatedown(int index);
        int Perlocateup(int index); //returns the index where its inserted 
        void Extractmax();
        int Insert(Actor* actor); //returns the index where its inserted
        void Delete(int index); //should be bool
        int updateNode(int index, int num); //updates praise points, returns bool 
        Actor* extractMax();
        //int getArrayIndex(praise_points);
        

};
#endif