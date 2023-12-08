#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <iostream>
using namespace std;
#include <vector>
#include "Array.h"



class Actor {
	private:
		unsigned int actor_id;	
	public:
		string last;
		string first;
		int heap_index;
		int praise_points;
		bool awarded;
		Actor();
		Actor( int act_id, string last, string first); 
		Actor& operator=(Actor& other);
		bool operator==(Actor& other);
		bool operator>(Actor& other);
		bool operator<(Actor& other);
		Actor(const Actor& other): actor_id(other.actor_id), last(other.last), first(other.first), praise_points(0), awarded(false){}
		string getName() const { 
			return first + " " + last;
		}
		int getID() const { return actor_id; }
};

#endif
