#include "Actor.h"
#include "MovieDB.h"

Actor& Actor::operator=(Actor& other) {
    if (this != &other) { 
        actor_id = other.actor_id;
        last = other.last;
        first = other.first;
        movies = other.movies;
    }
    return *this;
}
bool Actor::operator>(Actor& other){
  return actor_id > other.actor_id;
}
bool Actor::operator><Actor& other){
  return actor_id < other.actor_id;
}
bool Actor::operator==(Actor& other){
  if(actor_id == other.actor_id &&
     last == other.last &&
     first == other.first &&
     movies == other.movies) return true;
  return false;
}
Actor::Actor() {
	first = "";
	last = "";
	actor_id = 0;
}

Actor::Actor(unsigned int act_id, string lname, string fname) {
	first = fname;
	last = lname;
	actor_id = act_id;
}



