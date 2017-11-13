/*
  Description: Database file, used to store data.  Stores everything in json files.  The incidents recieved from the api are parsed.  Any that do not already exist get added to the active incidents file along with all properties.  After they are no longer active, they get removed from and their id's are stored in a file long term (can be specified).
*/

#include "json.hpp"
using namespace std;

#ifndef incident_storage_H
#define incident_storage_H

class IncidentStorage
{
	private:

	public:
		IncidentStorage();
}; // DB

#include "incident_storage.hpp"
#endif // DB_h
