// Includes for RideSharing
#include "tomtom_api.h"
#include "pull_updates.h"
#include "config_parser.h"
#include "incident_storage.h"

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <iostream>
#include <stdexcept>

// Includes for osrm
#include "osrm/match_parameters.hpp"
#include "osrm/nearest_parameters.hpp"
#include "osrm/route_parameters.hpp"
#include "osrm/table_parameters.hpp"
#include "osrm/trip_parameters.hpp"

#include "osrm/coordinate.hpp"
#include "osrm/engine_config.hpp"
#include "osrm/json_container.hpp"

#include "osrm/osrm.hpp"
#include "osrm/status.hpp"

#include <exception>
#include <iostream>
#include <string>
#include <utility>

#include <cstdlib>

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

    IncidentStorage IS = IncidentStorage();
    IS.StoreIncidents(all_inc);


    /*
    cout<<"Printing Updates..."<<endl;
    for(auto it = all_inc.begin(); it != all_inc.end(); it++)
    {
    	for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
    	{
    		cout<<(it2)->get_id()<<endl;
    	}
    }
    */





    return 0;
}
