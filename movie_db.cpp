#include <iostream>
#include <fstream>
using namespace std;
#include <getopt.h>
#include <assert.h>
#include "Parser.h"
#include "ActorDB.h"
ActorDB actordb;

void do_remove_actor(int actor_id){
  string name = actordb.getName(actor_id);
  if(actordb.removeActor(actor_id))
    cout << "Removed " << name << " from the program and all casts" << endl;
  else
    cout << "remove_actor: Error actor id " << actor_id <<
      "does not exist" << endl;
}
void do_register_actor(int actor_id, string actor_last, string actor_first) {
	/*
	cout << "do_register_actor()" << endl;
	cout << "   actor_id: " << actor_id << endl; 
	cout << " actor_last: " << actor_last << endl; 
	cout << "actor_first: " << actor_first << endl; 
	*/
	Actor a(actor_id, actor_last, actor_first);
	if (actordb.addActor(a)) 
		cout << "register_actor: Registered actor " << 
			a.getName() << endl;
	else
		cout << "register_actor: Error actor id " << actor_id << 
			" already in use" << endl;
	return;
}


bool expected(Parser &p, unsigned int howmany) {
   if (p.numArgs() < howmany) { 
      cout << std::endl << "Can't operate with " << MISSING_ARGS << endl;
      return false;
   }
   if (p.numArgs() > howmany) {
      cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
      return true;
   }
   return true;
}

bool assertInt(Parser &p, unsigned int argnum) {
   if (!Parser::isInteger(p.getArg(argnum))) {
      cout << "Error: field " << p.getArg(argnum) << 
              " is not an integer" << endl;
      return false;
   }
   return true;
}

bool accept_commands(istream &is, bool silent=false, bool echo=false) {
   string command;  
   string line;

   while (1) {
      if (!silent) {
      cout << endl << "Enter a command: " << endl;
      cout << "Choose from " << endl <<
      "   register_actor <actorid> <last> <first>" << endl <<
      "   remove_actor <actorid>" << endl <<
      "   quit" << endl; 
      cout << ": ";
      }
      getline(is, line);
      if (echo) {
         cout << endl;
         cout << "======================================================" << 
		 endl;
         cout << line << endl;
         cout << "======================================================" << 
		 endl;
      }

      Parser p(line);
      if (p.getOperation().empty()) {
         if (is.fail())
            return false;
         continue;
      }

      if (p.getOperation() == "quit") {
         expected(p, 0);
         return true;
      }

      else if(p.getOperation() == "remove_actor"){
      if(!expected(p, 1))
      continue;
      if(!assertInt(p, 1))
      continue;
      int actor_id = stoi(p.getArg(1));
      do_remove_actor(actor_id);
      }
      else if (p.getOperation() == "register_actor") {
      if (!expected(p, 3))  
            continue;
      if (!assertInt(p, 1))
               continue;
            int actor_id = stoi(p.getArg(1));
            do_register_actor(actor_id, p.getArg(2), p.getArg(3));
      }
      
      else {
         cout << std::endl << 
              "Command not recognized. Please try again." << endl; 
      }
   }
   return true;
}

int main()
{
  accept_commands(cin, true, false);
  return 0;
}