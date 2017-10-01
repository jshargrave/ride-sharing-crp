#include "tomtom_api.h"
#include "pull_updates.h"
#include "config_parser.h"

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char * argv[])
{
    if(argc != 2){
        throw invalid_argument("Error: provide configuration file path.");
    }

    // Parsing configuration file
    map<string, string> config_values = ConfigParser(argv[1]);

    // First initalization of curl, only needs to be done once
    curl_global_init(CURL_GLOBAL_ALL);

    

    PullUpdates P = PullUpdates();
    TomTomAPI* T = new TomTomAPI(config_values.at("TomTomAPI"));


    P.load_api(T);
    T = NULL;

    list<list<Incident> > all_inc;
    P.pull_updates(all_inc);

    cout<<"Printing Updates..."<<endl;

    for(auto it = all_inc.begin(); it != all_inc.end(); it++)
    {
    	for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
    	{
    		cout<<(it2)->get_id()<<endl;
    	}
    }

    return 0;
}