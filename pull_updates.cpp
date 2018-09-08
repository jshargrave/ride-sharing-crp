using namespace std;

PullUpdates::PullUpdates()
{

}

PullUpdates::~PullUpdates()
{
	clear();
}

void PullUpdates::clear()
{
	while(!api_list.empty()){
		delete api_list.front();
		api_list.pop_front();
	}
}

void PullUpdates::load_api(BaseAPI* obj)
{
	api_list.push_back(obj);
}

list<list<Incident> > PullUpdates::pull_updates(list<list<Incident> > &all_inc)
{
	string inc_str; //holds a sting representation of the incidents from each API
	list<Incident> inc_list;

	for(auto it = api_list.begin(); it != api_list.end(); it++){
		inc_str = (*it)->retrieve_incidents();
		inc_list = (*it)->parse_incidents(inc_str);
		all_inc.push_back(inc_list);
	}

	return all_inc;
}
