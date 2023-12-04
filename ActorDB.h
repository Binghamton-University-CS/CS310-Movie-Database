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
		BST<Node> actorBST;
	public:
		
		ActorDB();
		bool find(unsigned int actorid) const;
		string getName(unsigned int actorid) const;
  bool addActor( Actor &actor);
  bool removeActor(int actor_id);
};

#endif