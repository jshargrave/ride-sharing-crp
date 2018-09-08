#include <list>
#include "base_api.h"

using namespace std;

#ifndef PULL_UPDATES_H
#define PULL_UPDATES_H

class PullUpdates {
	private:
		// Stores a list of pointers to BaseAPI's
		list<BaseAPI*> api_list;

	public:
		/*
		Desc: PullUpdates constructor.
		*/
		PullUpdates();

		/*
		Desc: PullUpdates deconstructor.
		*/
		~PullUpdates();

		/*
		Desc: Deallocates all the api_list variable.
		*/
		void clear();

		/*
		Desc: Add a BaseAPI pointer to the api_list variable.
		*/
		void load_api(BaseAPI* obj);

		/*
		Desc: Returns a list containng a list of incidents for each BaseAPI
			  stored in the api_list variable.
		*/
		list<list<Incident> > pull_updates(list<list<Incident> > &all_inc);

		/*
		Desc: Prints the incidents stored in the api_list variable.
		*/
		void print_updates();

}; //PullUpdates

#include "pull_updates.cpp"
#endif
