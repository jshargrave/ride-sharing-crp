/*
  Description: Database file, used to store data.  Stores everything in json files.  The incidents recieved from the api are parsed.  Any that do not already exist get added to the active incidents file along with all properties.  After they are no longer active, they get removed from and their id's are stored in a file long term (can be specified).
*/

#include "json.hpp"
#include "exceptions.h"
#include <fstream>
#include <iostream>
using namespace std;

#ifndef incident_storage_H
#define incident_storage_H

// Variables used to store the file of incidents
const string PATH = 							"../data/";
const string INCIDENTS = 					PATH+"incidents.json";
const string ACTIVE_INCIDENTS = 	PATH+"active_incidents.json";
const string UNACTIVE_INCIDENTS = PATH+"unactive_incidents.json";

class IncidentStorage
{
	public:
		/*
			Desc: IncidentStorage constructor.
		*/
		IncidentStorage();

		/*
			Desc: Used to add the incdents passed to the storage file INCIDENTS.
		*/
		void StoreIncidents(list<list<Incident> >& all_inc);

		/*
			Desc: This function takes one single incident as a paramater and adds it to the INCIDENTS file for storage.
		*/
		void StoreAIncident(Incident& inc);

		/*

		*/
		void StoreAActiveIncident(string id);

		/*

		*/
		void StoreAUnactiveIncident(string id);

	private:
		/*

		*/
		bool DoesFileExist(string file_path);

		/*

		*/
		json ParseIncident(Incident& inc);


}; // IncidentStorage

#include "incident_storage.hpp"
#endif // IncidentStorage_h
