#ifndef __ACTORDB_H_
#define __ACTORDB_H_

#include <iostream>
using namespace std;

#include <vector>
#include "Actor.h"
//#include "Array.h"
class MovieDB;

class ActorDB {
	private:
		Array<Actor> actors;		
	public:
  bool addMovie(unsigned int actorid, unsigned int movieid);
		ActorDB();
		bool find(unsigned int actorid) const;
		string getName(unsigned int actorid) const;
  bool addActor( Actor &actor);
  void showCareer(unsigned int actorid,  MovieDB &moviedb);
  bool removeActor(int actor_id);
};

#endif