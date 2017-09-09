using namespace std;
#include <iostream>

void PullUpdates::load_api(BaseAPI* obj)
{
	api_list.push_back(obj);
}

list<string> PullUpdates::pull_updates()
{
	updates_list.clear();

	for(list<BaseAPI*>::iterator it = api_list.begin(); it != api_list.end(); it++){
		(*it)->set_updates((*it)->retrieve_incidents());
	}

	return updates_list;
}

void PullUpdates::print_updates()
{
	for(list<BaseAPI*>::iterator it = api_list.begin(); it != api_list.end(); it++){
		cout<<(*it)->get_updates()<<endl;
	}

}