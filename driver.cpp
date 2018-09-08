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
using namespace osrm;

void config_osrm(EngineConfig &config, char * argv[]);


int main(int argc, char * argv[])
{
    // Checking for the correct number of arguments
    if(argc != 3){
      cout<<"Usage: "<<argv[0]<<" [conifg] [data.osrm]"<<endl;
      throw invalid_argument("Error: invalid amount of arguments passed.");
    }

    // Parsing configuration file
    map<string, string> config_values = ConfigParser(argv[1]);

    // First initalization of curl, only needs to be done once
    curl_global_init(CURL_GLOBAL_ALL);

    // Interface for TomTom API
    TomTomAPI* TT = new TomTomAPI(config_values.at("TomTomAPI"));

    // Load traffic api into
    PullUpdates P = PullUpdates();
    P.load_api(TT);

    list<list<Incident> > all_inc;
    P.pull_updates(all_inc);

    IncidentStorage IS = IncidentStorage();
    IS.StoreIncidents(all_inc);

    IS.StoreIncidents(all_inc);

    cout<<"Printing Updates..."<<endl;
    cout.precision(17);
    // Incident list's
    for(auto it = all_inc.begin(); it != all_inc.end(); it++)
    {
      // Incident's
    	for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
    	{
    		cout<<(it2)->GetID()<<"\t"<<(it2)->GetX()<<"\t"<<(it2)->GetY()<<endl;
    	}
    }


    EngineConfig config;
    config_osrm(config, argv);

    //const OSRM osrm{config};
    /*
    MatchParameters params;
    params.overview = RouteParameters::OverviewType::False;
    params.steps = false;

    using osrm::util::FloatCoordinate;
    using osrm::util::FloatLatitude;
    using osrm::util::FloatLongitude;

    // The following shows how to use the Route service; configure this service

    params.coordinates.push_back(FloatCoordinate{FloatLongitude{521016.6875}, FloatLatitude{6886614}});

    auto NUM = 100;
    for (int i = 0; i < NUM; ++i)
    {
        json::Object result;
        const auto rc = osrm.Match(params, result);
        if (rc != Status::Ok || result.values.at("matchings").get<json::Array>().values.size() != 1)
        {
            return EXIT_FAILURE;
        }
    }
    std::cout << "ms/req at " << params.coordinates.size()
              << " coordinate" << std::endl;
    std::cout << params.coordinates.size() << "ms/coordinate"
              << std::endl;
    */
}

void config_osrm(EngineConfig &config, char * argv[])
{
  // Configuing OSRM
  config.storage_config = {argv[1]};
  config.use_shared_memory = true;

  // We support two routing speed up techniques:
  // - Contraction Hierarchies (CH): requires extract+contract pre-processing
  // - Multi-Level Dijkstra (MLD): requires extract+partition+customize pre-processing
  //
  // config.algorithm = EngineConfig::Algorithm::CH;
  config.algorithm = EngineConfig::Algorithm::MLD;
}
