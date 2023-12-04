#ifndef __ACTOR_H_
#define __ACTOR_H_

#include <iostream>
using namespace std;
#include <vector>
#include "Array.h"

class MovieDB;

class Actor {
	private:
		unsigned int actor_id;
		
		Array<unsigned int> movies;		
	public:
		string last;
		string first;
		int heapIndex;
		int praise_points;
		Actor();
		Actor(unsigned int act_id, string last, string first); 
                Actor& operator=(Actor& other);
                bool operator==(Actor& other);
                bool operator>(Actor& other);
				bool operator<(Actor& other);
                Actor(const Actor& other) 
		  : actor_id(other.actor_id), last(other.last), first(other.first), movies(other.movies){}
		string getName() const { 
			return first + " " + last;
		}
		unsigned int getID() const { return actor_id; }
};

#endif
