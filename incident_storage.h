/*
  Description: Database file, used to store data.  Stores everything in json files.  The incidents recieved from the api are parsed.  Any that do not already exist get added to the active incidents file along with all properties.  After they are no longer active, they get removed from and their id's are stored in a file long term (can be specified).
*/

#include "json.hpp"
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
	private:

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
			Desc: Takes the id passed and makes the incident matching that id in the INCIDENTS file active by adding it to the ACTIVE_INCIDENTS file.
		*/
		void MakeActive(string id);

		/*

		*/
		void StoreAActiveIncident(string id);

		/*
			Desc: Takes the id passed and makes the incident matching that id in the ACTIVE_INCIDENTS file unactive by removing it from the ACTIVE_INCIDENTS file and adding it to the UNACTIVE_INCIDENTS.
		*/
		void MakeUnactive(string id);

		/*

		*/
		void StoreAUnactiveIncident(string id);

		/*

		*/
		bool DoesFileExist(string file_path);

		/*

		*/
		void CreateFile(string file_path);


}; // IncidentStorage

#include "incident_storage.hpp"
#endif // IncidentStorage_h
