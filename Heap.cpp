#include<iostream>
#include "Heap.h"
using namespace std;

int Heap::Perlocateup(int nodeIndex) {
   int parentIndex = (nodeIndex - 1) / 2;
   if (arr.at(nodeIndex) <= arr.at(parentIndex) || nodeIndex <= 0)
      return nodeIndex;
   else {
      int temp = arr.at(nodeIndex);
      arr.at(nodeIndex) = arr.at(parentIndex);
      arr.at(parentIndex) = temp;
      nodeIndex = Perlocateup(parentIndex);
   }
   return nodeIndex;
}

int Heap::Perlocatedown(int nodeIndex) {
   int childIndex = 2 * nodeIndex + 1;
   int value = arr.at(nodeIndex);
   while (childIndex < arr.size()) {
      // Find the max among the node and all the node's children
      int maxValue = value;
      int maxIndex = -1;
      if(childIndex >= arr.size()){
         return nodeIndex;
      }
      for (int i = 0; i < 2 && i + childIndex < arr.size(); i++) {
         if (arr.at(i + childIndex) > maxValue) {
            maxValue = arr.at(i + childIndex);
            maxIndex = i + childIndex;
         }
      }

      if (maxValue == value) {
         return nodeIndex;
      }
      else {
         int temp = arr.at(nodeIndex);
         arr.at(nodeIndex) = arr.at(maxIndex);
         arr.at(maxIndex) = temp;
         nodeIndex = Perlocatedown(childIndex);
         return nodeIndex;
      }
   }
}
int Heap::Insert(int num){ //returns the index at where its inserted

   arr.push_back(num);
   return Perlocateup(arr.size()-1);

}
void Heap::Delete(int index){
   arr.at(index) = arr.at(arr.size()-1);
   arr.erase(arr.size()-1);
   Perlocatedown(index);
   return;
}

bool Heap::updateNode(int index, int num){
   if(arr.at(index) < num){
      arr.at(index) = num;
      return Perlocateup(index);
   }
   if(arr.at(index) > num){
      arr.at(index) = num;
      return Perlocatedown(index);
   }
   return index;
   
}