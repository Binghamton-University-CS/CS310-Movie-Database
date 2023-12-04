#include "ActorDB.h"
#include "MovieDB.h"

//getPraise()


ActorDB::ActorDB() {
}
bool ActorDB::removeActor(int actor_id){
  for(unsigned int i = 0; i < actors.size(); i++){
    if(actors[i].getID() == actor_id){
      return actors.erase(actors[i]);
    }
  }
  return false;
}

bool ActorDB::find(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid)
			return true;
	}
	return false;
}

string ActorDB::getName(unsigned int actorid) const {
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid)
			return actors[i].getName();
	}
	return "EMPTY";
}

bool ActorDB::addActor(Actor &actor) {
	
	for (unsigned int i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actor.getID())
			return false;
	}
	actors.sort_push(actor);
	
	int index;
	for(int i = 0; i < actors.size(); i++){
		if(actors[i].getID() == actor.getID())
		index = i;
	}
	actorBST.insert(Node(actor.last, index));


	
	return true;
}


