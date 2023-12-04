#include<iostream>
#include "Array.h"
using namespace std;
class Heap{
    private:
        Array<int> arr; 
    public:
        void Perlocatedown(int index);
        void Perlocateup(int index);
        void Extractmax();
        int Insert(int num);
        void Delete(int index);
};