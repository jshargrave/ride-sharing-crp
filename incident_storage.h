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
const string INACTIVE_INCIDENTS = PATH+"inactive_incidents.json";

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
			Desc: This function takes one single incident as a paramater and adds it
						to the INCIDENTS file for storage.
		*/
		void StoreAIncident(Incident& inc);

		/*
			Desc: This function takes a incident id, checks that it exist in the
						INCIDENTS file, then stores it in the ACTIVE_INCIDENTS file.
		*/
		void StoreAActiveIncident(string id);

		/*
			Desc: This function takes a incident id, checks if it exist in the
						INCIDENTS and ACTIVE_INCIDENTS files, then erases the incident id
						and attributes from both file, then stores the id in the
						INACTIVE_INCIDENTS file.
		*/
		void StoreAInactiveIncident(string id);

	private:

		/*
			Desc: This function takes a id and a file as paramater, then it sees if
						the id exist in the file.  If yes then true is returned, otherwise
						false is returned.
		*/
		bool DoesIDExistInFile(string id, string file);

		/*
			Desc: Function takes a file path as a string, then it reads the contents
						into a json object and returns it.
		*/
		json GetJsonFile(string file);

		/*
			Desc: Takes a file path and a json object as a paramater.  Write the json
						object to the file.
		*/
		void WriteJsonToFile(string file, json j);

		/*
			Desc: Checks to see if the file passed as a paramater exist.
		*/
		bool DoesFileExist(string file_path);

		/*
			Desc: Parses an incident into a json object, then returns the json object.
		*/

		json ParseIncident(Incident& inc);

}; // IncidentStorage

#include "incident_storage.hpp"
#endif // IncidentStorage_h
