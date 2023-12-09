#include "ActorDB.h"
#include "BST.h"
#include "Heap.h"
BST actorBST;
Heap praiseHeap;
ActorDB::ActorDB() {
}
bool ActorDB::removeActor(int actor_id){
  for(int i = 0; i < actors.size(); i++){
    if(actors.at(i).getID() == actor_id){
      actors.erase(i);
	  return true; //wrong logic
    }
  }
  return false;
}

bool ActorDB::find(int actorid) {
	for (int i = 0; i < actors.size(); i++) {
		if (actors.at(i).getID() == actorid)
			return true;
	}
	return false;
}

string ActorDB::getName(int actorid) {
	for (int i = 0; i < actors.size(); i++) {
		if (actors.at(i).getID() == actorid)
			return actors.at(i).getName();
	}
	return "EMPTY";
}

bool ActorDB::addActor(Actor &actor) {
	
	for (int i = 0; i < actors.size(); i++) {
		if (actors.at(i).getID() == actor.getID())
			return false;
	}
	actors.push_back(actor);
	actors.sort_push();

	int index;
	for(int i = 0; i < actors.size(); i++){
		if(actors.at(i).getID() == actor.getID())
		index = i;
	}
	actors.at(index).bst_pointer = actorBST.insert(actor.last, index);//index not being updated
	actorBST.find(actor.last)->arrayIndex = index;
	
	
	return true;
}

bool ActorDB::praiseActor(string lastName, int praisePts) {
    Node* actorNode = actorBST.find(lastName);
    if (actorNode == nullptr) {
        return false;
    }
	if(actors.at(actorNode->arrayIndex).awarded){
 		cout << "Actor has been awarded already :/ ";
		return false;
	}
    int index = actorNode->arrayIndex;
	
    Actor* actor = &actors.at(index);  // Get a pointer to the actor
	actor->praise_points += praisePts; // Update praise points in actor
    // Check if actor is already in the heap
    if (actor->heap_index != -1) {
        // Update actor's position in the heap
        actor-> heap_index = praiseHeap.updateNode(index, actor->praise_points);
		
    	
		cout << "Updating actor";
    } else {
		cout << "Inserting actor";
        // Insert the actor into the heap for the first time
        actor-> heap_index = praiseHeap.Insert(actor); // Mark the actor as present in the heap
    }

    return true;
}

void ActorDB::showPraise(){
	for(int i = 0; i < actors.size(); i ++){
		if(actors.at(i).awarded) cout << "*AWARD*:	";
		cout << actors.at(i).getName() << ": " << actors.at(i).praise_points << " praise points "<< actors.at(i).heap_index << endl;
	}
}

void ActorDB::awardActor(){
	cout << "on the way to praise";
	Actor* actor = praiseHeap.extractMax();
	if (actor == nullptr){
		cout << "not in heap";
		return;
	}
	cout << "Awarded " << actor->last << " " << actor->first;
	actor->awarded = true;
	actor->heap_index = -1;
}