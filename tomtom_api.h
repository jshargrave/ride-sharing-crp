#include "base_api.h"
#include <iostream>

using namespace std;

#ifndef TOMTOM_API_H
#define TOMTOM_API_H

string TOM_TOM_URL = "http://api.tomtom.com/traffic/services/4/incidentDetails/s3/6841263.950712,511972.674418,6886056.049288,582676.925582/11/1335294634919/json?key=<apiKey>";

class TomTomAPI : public BaseAPI {
	private:


	public:
		/*
		Desc: TomTomAPI constructor.
		*/
		TomTomAPI(string key);

		/*
		Desc: TomTomAPI deconstructor.
		*/
		~TomTomAPI();

		/*
		Desc: Function to parse TOM_TOM_URL and then make API call and return
			  response.
		*/
		string retrieve_incidents();

		/*
		Desc: Takes the API response string as a paramater and returns a list
			  of incidents.
		*/
		list<Incident> parse_incidents(string incidents);

}; //TomTomAPI

#include "tomtom_api.cpp"
#endif // TOMTOM_API_H
