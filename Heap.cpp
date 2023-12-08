#include<iostream>
#include "Heap.h"
using namespace std;

int Heap::Perlocateup(int nodeIndex) {
   int parentIndex = (nodeIndex - 1) / 2;
   if (arr.at(nodeIndex)->praise_points <= arr.at(parentIndex)->praise_points || nodeIndex <= 0)
      return nodeIndex;
   else {
      Actor* temp = arr.at(nodeIndex);
      arr.at(nodeIndex) = arr.at(parentIndex);
      arr.at(parentIndex) = temp;
      nodeIndex = Perlocateup(parentIndex);
   }
   return nodeIndex;
}

int Heap::Perlocatedown(int nodeIndex) {
   int childIndex = 2 * nodeIndex + 1;
   int value = arr.at(nodeIndex)->praise_points;
   // Find the max among the node and all the node's children
   int maxValue = value;
   int maxIndex = -1;
   if(childIndex >= arr.size()){
      return nodeIndex;
   }
   for (int i = 0; i < 2 && i + childIndex < arr.size(); i++) {
      if (arr.at(i + childIndex)-> praise_points > maxValue) {
         maxValue = arr.at(i + childIndex)->praise_points;
         maxIndex = i + childIndex;
      }
   }

   if (maxValue == value) {
      return nodeIndex;
   }
   else {
      Actor* temp = arr.at(nodeIndex);
      arr.at(nodeIndex) = arr.at(maxIndex);
      arr.at(maxIndex) = temp;
      nodeIndex = Perlocatedown(childIndex);
      return nodeIndex;
   }

}
int Heap::Insert(Actor* actor){ //returns the index at where its inserted

   arr.push_back(actor);
   return Perlocateup(arr.size()-1);

}
void Heap::Delete(int index){
   arr.at(index) = arr.at(arr.size()-1);
   arr.erase(arr.size()-1);
   Perlocatedown(index);
   return;
}

bool Heap::updateNode(int index, int num) {
      if (index < 0 || index >= arr.size()) return false;
      if (arr.at(index)->praise_points < num) {
         arr.at(index)->praise_points = num;
         Perlocateup(index);
         return true;
      }
      if (arr.at(index)->praise_points > num) {
         arr.at(index)->praise_points = num;
         Perlocatedown(index);
         return true;
      }
      return false;
   }

Actor* Heap::extractMax() {
        if (arr.size() == 0) {
            return nullptr; // Heap is empty
        }

        Actor* maxActor = arr.at(0); // The actor with the maximum praise points
        // Replace the root of the heap with the last element
        arr.at(0) = arr.at(arr.size() - 1);
        arr.erase(arr.size()-1); // Remove the last element

        // Percolate down the new root to maintain the heap property
        Perlocatedown(0);

        return maxActor;
    }

