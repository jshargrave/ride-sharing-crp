#include <list>
#include "base_api.h"

using namespace std;

#ifndef PULL_UPDATES_H
#define PULL_UPDATES_H

class PullUpdates {
	private:
		list<BaseAPI*> api_list;
		list<string> updates_list;


	public:
		void load_api(BaseAPI* obj);

		list<string> pull_updates();

		void print_updates();


}; //PullUpdates

#include "pull_updates.hpp"
#endif