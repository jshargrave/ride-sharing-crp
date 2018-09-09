/*
  Description: Database file, used to store data.  Stores everything in json files.  The incidents recieved from the api are parsed.  Any that do not already exist get added to the active incidents file along with all properties.  After they are no longer active, they get removed from and their id's are stored in a file long term (can be specified).
*/

#include "json.hpp"
#include <fstream>
#include <iostream>
#include <cstdio>
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
	private:

	public:
		/*
		Desc: IncidentStorage constructor.
		*/
		IncidentStorage();

		/*
		Desc: IncidentStorage deconstructor.
		*/
		~IncidentStorage();

		/*
		Desc: Used to add the incdents passed to the storage file INCIDENTS.
		*/
		void StoreIncidents(list<list<Incident> >& api_list);

	private:

		/*
		Desc: This function deletes all files that were generated.  Normally
			  this function is never called.
		*/
		void clear();

		/*
		Desc: This function takes one single incident as a paramater and
		   	  adds it to the INCIDENTS file for storage.
		*/
		void StoreAIncident(Incident& inc);

		/*
		Desc:
		*/
		void StoreActiveIncidents();

		/*
		Desc:
		*/
		void StoreUnactiveIncidents();

		/*
		Desc: Function that is responsible for parsing the incident data into a
			  json variable.

		Post: Assumes that the incident is correctly populated with values.
		*/
		json ParseIncident(Incident& inc);

		/*
		Desc: Overloaded functions to convert a incident into a json variable.
			  The functions can handle several different cases.  A list of api's
			  that each contain a list of incidents, A list of incidents, a
			  single incident passed, or a incident's id passed as a string.
			  Each overloaded function also takes a json variable passed by
			  reference which stores the newly generated json data.
		*/
		void IncidentsToJson(json &j, list<list<Incident> >& api_list);
		void IncidentsToJson(json &j, list<Incident>& inc_list);
		void IncidentsToJson(json &j, Incident& inc);
		void IncidentsToJson(json &j, string id);

		/*
		Desc: Functions used to write json data to files.
		*/
		void WriteJson(json &j, string file);
		void WriteJsonIncidents(json &j);
		void WriteJsonActiveIncidents(json &j);
		void WriteJsonUnactiveIncidents(json &j);

		/*
		Desc: Functions used to fetch json data from files.
		*/
		void GetJson(json &j, string file);
		void GetJsonIncidents(json &j);
		void GetJsonActiveIncidents(json &j);
		void GetJsonUnactiveIncidents(json &j);

		/*
		Desc: Functions used to check if a incidents id exist.
		*/
		bool DoesIdExist(json &j, string id);
		bool DoesIncidentIdExist(string id);
		bool DoesActiveIncidentIdExist(string id);
		bool DoesUnactiveIncidentIdExist(string id);


		/*
		Desc: Functions used to check if a file exist.
		*/
		bool DoesFileExist(string file_path);
		bool DoesIncidentFileExist();
		bool DoesActiveIncidentFileExist();
		bool DoesUnactiveIncidentFileExist();
		void remove_file(string file);

}; // IncidentStorage

#include "incident_storage.cpp"
#endif // IncidentStorage_h
