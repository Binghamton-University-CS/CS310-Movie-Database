#ifndef __ACTORDB_H_
#define __ACTORDB_H_

#include <iostream>
using namespace std;

#include <vector>
#include "Actor.h"
//#include "Array.h"
class BST;
class Heap;


class ActorDB {
	
	private:
		Array<Actor> actors;
		
	public:
		ActorDB();
		bool find (int actorid);
		string getName(int actorid);
		bool addActor( Actor &actor);
		bool removeActor(int actor_id);
		bool praiseActor(string lastName, int praise_points);
		void showPraise();
		void awardActor();
};

#endif