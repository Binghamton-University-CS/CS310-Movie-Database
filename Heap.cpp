#include<iostream>
#include "Heap.h"
using namespace std;

void Heap::Perlocateup(nodeIndex) {
   while (nodeIndex > 0) {
      int parentIndex = (nodeIndex - 1) / 2;
      if (arr[nodeIndex] <= arr[parentIndex])
        return;
      else {
        int temp = arr[nodeIndex];
        arr[nodeIndex] = arr[parentIndex];
        arr[parentIndex] = temp;
        return Perlocateup(parentIndex);
      }
   }
   return;
}

void Heap::Perlocatedown(nodeIndex) {
   childIndex = 2 * nodeIndex + 1;
   value = arr[nodeIndex];
   while (childIndex < arr.size()) {
      // Find the max among the node and all the node's children
      maxValue = value;
      maxIndex = -1;
      for (i = 0; i < 2 && i + childIndex < arr.size(); i++) {
         if (arr[i + childIndex] > maxValue) {
            maxValue = arr[i + childIndex];
            maxIndex = i + childIndex;
         }
      }

      if (maxValue == value) {
         return;
      }
      else {
         int temp = arr[nodeIndex];
         arr[nodeIndex] = arr[maxIndex];
         arr[maxIndex] = temp;
         return Perlocatedown(childIndex);
      }
   }
}
int Heap::Insert(int num){ //returns the index at where its inserted
   arr.push_back(num);
   Perlocateup(arr.size()-1);

}
void Heap::delete(int index){
   arr.at(index) = arr.at(arr.size()-1);
   erase(arr.size()-1);
   Perlocatedown(index);
}