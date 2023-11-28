#include "ActorDB.h"
#include "MovieDB.h"

ActorDB::ActorDB() {
}
bool ActorDB::removeActor(int actor_id){
  for(unsigned int i = 0; i < actors.size(); i++){
    if(actors[i].getID() == actor_id){
      return actors.remove(actors[i]);
    }
  }
  return false;
}
bool ActorDB::addMovie(unsigned int actorid, unsigned int movieid) {
  // cout << "MOVIES SIZE DURING addActor inMOVIEDB : " << movies.size() << endl;
	for (unsigned int i = 0; i < actors.size(); i++) 
	  if (actors[i].getID() == actorid)
			return actors[i].addMovie(movieid);
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
	actors.push_back(actor);
	
	return true;
}


void ActorDB::showCareer(unsigned int actorid, MovieDB &moviedb) {unsigned int i;
	for (i = 0; i < actors.size(); i++) {
		if (actors[i].getID() == actorid) {
		  cout << actors[i].getName() << " has acted in:" << 
				endl;
			break;
	}
	}
		if (i < actors.size()){
		  //cout << "actor.showCareer was reached" << endl;
	  /* for(int i = 0; i < moviedb.movies.size(); i++){
	    for(int k = 0; k < moviedb.movies[i].
	  }*/
	  //	  cout << "Movies.size() = " << moviedb.movies.size() << endl;
	  actors[i].showCareer(moviedb);}
	else 
		cout << "actor id " << actorid << " not found" << endl;
}