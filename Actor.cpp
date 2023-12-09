#include "Actor.h"


Actor& Actor::operator=(Actor& other) {
    if (this != &other) { 
        actor_id = other.actor_id;
        last = other.last;
        first = other.first;
        praise_points = other.praise_points;
        heap_index = other.heap_index;
        awarded = other.awarded;
        bst_pointer = other.bst_pointer;
    }
    return *this;
}
bool Actor::operator>(Actor& other){
  return actor_id > other.actor_id;
}
bool Actor::operator<(Actor& other){
  return actor_id < other.actor_id;
}
bool Actor::operator==(Actor& other){
  if(actor_id == other.actor_id &&
     last == other.last &&
     first == other.first &&
     praise_points == other.praise_points &&
     heap_index == other.heap_index &&
     awarded == other.awarded &&
     bst_pointer == other.bst_pointer) return true;
  return false;
}
Actor::Actor() {
	first = "";
	last = "";
	actor_id = 0;
  heap_index = -1;
  praise_points = 0;
  awarded = false;
  bst_pointer = nullptr;
}

Actor::Actor(int act_id, string lname, string fname) {
	first = fname;
	last = lname;
	actor_id = act_id;
  heap_index = -1;
  praise_points = 0;
  awarded = false;
  bst_pointer = nullptr;
}