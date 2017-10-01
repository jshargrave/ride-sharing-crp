#include "base_api.h"
#include <iostream>

using namespace std;

#ifndef TOMTOM_API_H
#define TOMTOM_API_H

string TOM_TOM_URL = "https://api.tomtom.com/traffic/services/4/incidentDetails/s3/6841263.950712,511972.674418,6886056.049288,582676.925582/11/1335294634919/json?key=<apiKey>";

class TomTomAPI : public BaseAPI {
	private:
		

	public:
		TomTomAPI(string key) {api_key = key;}

		string retrieve_incidents();
		list<Incident> parse_incidents(string incidents);



}; //TomTomAPI

#include "tomtom_api.hpp"
#endif // TOMTOM_API_H

