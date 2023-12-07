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
	actors.sort_push(actor);

	int index;
	for(int i = 0; i < actors.size(); i++){
		if(actors.at(i).getID() == actor.getID())
		index = i;
	}
	actorBST.insert(actor.last, index);
	actorBST.find(actor.last)->arrayIndex = index;



	
	return true;
}

bool ActorDB::praiseActor(string lastName, int praisePts) {
    Node* actorNode = actorBST.find(lastName);
    if (actorNode == nullptr) {
        cout << "Actor not found in BST" << endl;
        return false;
    }

    int index = actorNode->arrayIndex;
    Actor* actor = &actors.at(index);  // Get a pointer to the actor

    // Update praise points
    actor->praise_points += praisePts;

    // Check if actor is already in the heap
    if (actor->heap_index != -1) {
        // Update actor's position in the heap
        praiseHeap.updateNode(index, actor->praise_points);
    } else {
        // Insert the actor into the heap for the first time
        actor-> heap_index = praiseHeap.Insert(actor); // Mark the actor as present in the heap
    }

    return true;
}

void ActorDB::showPraise(){
	for(int i = 0; i < actors.size(); i ++){
		cout << actors.at(i).getName() << ": " << actors.at(i).praise_points << " praise points" << endl;
	}
}