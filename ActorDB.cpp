#include "ActorDB.h"
#include "BST.h"
#include "Heap.h"
BST actorBST;
Heap praiseHeap;
ActorDB::ActorDB() {
}
bool ActorDB::removeActor(int actor_id){
  for(int i = 0; i < actors.size(); i++){
    if(actors[i].getID() == actor_id){
      return actors.erase(actors[i]);
    }
  }
  return false;
}

bool ActorDB::find(unsigned int actorid) {
	for (int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid)
			return true;
	}
	return false;
}

string ActorDB::getName(unsigned int actorid) {
	for (int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid)
			return actors[i].getName();
	}
	return "EMPTY";
}

bool ActorDB::addActor(Actor &actor) {
	
	for (int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actor.getID())
			return false;
	}
	actors.sort_push(actor);

	int index;
	for(int i = 0; i < actors.size(); i++){
		if(actors[i].getID() == actor.getID())
		index = i;
	}
	actorBST.insert(actor.last, index);
	actorBST.find(actor.last)->arrayIndex = index;



	
	return true;
}

bool ActorDB::praiseActor(string lastName, int praisePts){
	/*
	Update actor's praise points
	check if its in the heap or not if so update in heap, if not create new heap node.

	
	*/
	Node* actorNode = actorBST.find(lastName);
	int index = actorNode->arrayIndex;

	if(praisePts <= 0){ 
		actors[actorNode->arrayIndex] = praisePts;
	}
	else actors[actorNode->arrayIndex] += praisePts;

	if(index == -1){
		//create new heap node
		if(praiseHeap.Insert(praisePts)) {
			cout << "success " << endl; //UPDATE THIS
			return true;
		}

			
		else{
			cout << "fail " << endl; //UPDATE THIS
			return false;
		} 
	}
	else{ //already exists in the heap
		//return praiseHeap.updateNode(index, praisePts)
		return 1;
	}
}

