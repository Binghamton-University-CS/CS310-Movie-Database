#include<iostream>
#include "Heap.h"
using namespace std;

int Heap::Perlocateup(nodeIndex) {
   int parentIndex = (nodeIndex - 1) / 2;
   if (arr[nodeIndex] <= arr[parentIndex] || nodeIndex <= 0)
      return nodeIndex;
   else {
      int temp = arr[nodeIndex];
      arr[nodeIndex] = arr[parentIndex];
      arr[parentIndex] = temp;
      nodeIndex = Perlocateup(parentIndex);
   }
   return nodeIndex;
}

int Heap::Perlocatedown(nodeIndex) {
   childIndex = 2 * nodeIndex + 1;
   value = arr[nodeIndex];
   while (childIndex < arr.size()) {
      // Find the max among the node and all the node's children
      maxValue = value;
      maxIndex = -1;
      if(childIndex >= arr.size()){
         return nodeIndex;
      }
      for (i = 0; i < 2 && i + childIndex < arr.size(); i++) {
         if (arr[i + childIndex] > maxValue) {
            maxValue = arr[i + childIndex];
            maxIndex = i + childIndex;
         }
      }

      if (maxValue == value) {
         return nodeIndex;
      }
      else {
         int temp = arr[nodeIndex];
         arr[nodeIndex] = arr[maxIndex];
         arr[maxIndex] = temp;
         nodeIndex = Perlocatedown(childIndex);
         return nodeIndex;
      }
   }
}
int Heap::Insert(int num){ //returns the index at where its inserted

   arr.push_back(num);
   return Perlocateup(arr.size()-1);

}
void Heap::delete(int index){
   arr.at(index) = arr.at(arr.size()-1);
   erase(arr.size()-1);
   Perlocatedown(index);
}