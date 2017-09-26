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

    //should return a vect(list(incident))
    P.pull_updates();

    return 0;
}