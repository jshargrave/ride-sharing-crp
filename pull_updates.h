#include <list>
#include "base_api.h"

using namespace std;

#ifndef PULL_UPDATES_H
#define PULL_UPDATES_H

class PullUpdates {
	private:
		list<BaseAPI*> api_list;


	public:
		PullUpdates(){};
		
		~PullUpdates();


		void load_api(BaseAPI* obj);

		list<list<Incident> > pull_updates(list<list<Incident> > &all_inc);

		void print_updates();


}; //PullUpdates

#include "pull_updates.hpp"
#endif