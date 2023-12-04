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

bool Actor::addMovie(unsigned int movieid) {
	for (unsigned int i = 0; i < movies.size(); i++) {
		if (movies[i] == movieid)
			return false;
	}
	movies.push_back(movieid);
	return true;
}


void Actor::showCareer(MovieDB &moviedb){
	string movietitle;
	//cout << first << " " << last << " has acted in:" << endl;
	//	cout << "movies size at the end: " << movies.size() << endl;
	for (int i = 0; i < movies.size(); i++) {
	  //  cout << "for loop reached" << endl;
		if (moviedb.find(movies[i])) {
			movietitle = moviedb.getTitle(movies[i]);
			cout << "- " << movietitle << endl;
		}
	}
}