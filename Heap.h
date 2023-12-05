#include<iostream>
#include "Array.h"
using namespace std;
class Heap{
    private:
        Array<int> arr; 
        
    public:
        int Perlocatedown(int index);
        int Perlocateup(int index); //returns the index where its inserted 
        void Extractmax();
        int Insert(int num); //returns the index where its inserted
        void Delete(int index);
        //bool updateNode(int index, int num); updates praise points, returns bool 
        //int getArrayIndex(praise_points);
        

};