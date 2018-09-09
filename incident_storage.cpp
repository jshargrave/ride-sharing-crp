using namespace std;

IncidentStorage::IncidentStorage()
{

}

IncidentStorage::~IncidentStorage()
{

}

void IncidentStorage::clear()
{
    remove_file(INCIDENTS);
    remove_file(ACTIVE_INCIDENTS);
    remove_file(UNACTIVE_INCIDENTS);
}

void IncidentStorage::StoreIncidents(list<list<Incident> >& api_list)
{
    // Get current incidents data
    json j;
    GetJsonIncidents(j);

    // Adding all the incidents from all api's to json variable
    IncidentsToJson(j, api_list);

    // Write json to file
    WriteJsonIncidents(j);
}

void IncidentStorage::StoreAIncident(Incident& inc)
{
    // Get Incidents data
    json j;
    GetJsonIncidents(j);

    // Add new incident to json
    IncidentsToJson(j, inc);

    // Write json to file
    WriteJsonIncidents(j);
}

json IncidentStorage::ParseIncident(Incident& inc)
{
    json j;
    j["id"] = inc.GetID();
    j["f"] = inc.GetF();
    j["t"] = inc.GetT();
    j["r"] = inc.GetR();
    j["x"] = inc.GetX();
    j["y"] = inc.GetY();
    j["ic"] = inc.GetIC();
    j["ty"] = inc.GetTY();
    j["l"] = inc.GetL();
    j["dl"] = inc.GetDL();
    return j;
}

// ------------------------------- Write json File Functions -----------------
void IncidentStorage::IncidentsToJson(json &j, list<list<Incident> >& api_list)
{
    for(auto it = api_list.begin(); it != api_list.end(); it++)
    {
        // Calling function to store the list of incidents in a json file
        IncidentsToJson(j, *it);
    }
}

void IncidentStorage::IncidentsToJson(json &j, list<Incident>& inc_list)
{
    for(auto it = inc_list.begin(); it != inc_list.end(); it++)
    {
        // Calling a function to store the incident in a json file
        IncidentsToJson(j, *it);
    }
}

void IncidentStorage::IncidentsToJson(json &j, Incident& inc)
{
    // Parses and stores the incident into a json file
    j[inc.GetID()] = ParseIncident(inc);
}

void IncidentStorage::IncidentsToJson(json &j, string id)
{
    // Adds the incident id to a json file
    j[id] = id;
}


void IncidentStorage::WriteJson(json &j, string file)
{
    // Write incidents to INCIDENTS
    ofstream output(file);
    output << setw(4) << j << endl;
}

void IncidentStorage::WriteJsonIncidents(json &j)
{
    WriteJson(j, INCIDENTS);
}

void IncidentStorage::WriteJsonActiveIncidents(json &j)
{
    WriteJson(j, ACTIVE_INCIDENTS);
}

void IncidentStorage::WriteJsonUnactiveIncidents(json &j)
{
    WriteJson(j, UNACTIVE_INCIDENTS);
}

// -------------------------- json Function --------------------------
void IncidentStorage::GetJson(json &j, string file)
{
    // Check if INCIDENTS file exist
    if(DoesFileExist(file))
    {
        // Parse all information into a json object
        ifstream input(file);
        input >> j;
        input.close();
    }
}

void IncidentStorage::GetJsonIncidents(json &j)
{
    GetJson(j, INCIDENTS);
}

void IncidentStorage::GetJsonActiveIncidents(json &j)
{
    GetJson(j, ACTIVE_INCIDENTS);
}

void IncidentStorage::GetJsonUnactiveIncidents(json &j)
{
    GetJson(j, UNACTIVE_INCIDENTS);
}

// ---------------------------- Does Id Exist Functions ------------------
bool IncidentStorage::DoesIdExist(json &j, string id)
{
    j.at(id);
    return true;
}

bool IncidentStorage::DoesIncidentIdExist(string id)
{
    json j;
    GetJsonIncidents(j);
    return DoesIdExist(j, id);
}

bool IncidentStorage::DoesActiveIncidentIdExist(string id)
{
    json j;
    GetJsonActiveIncidents(j);
    return DoesIdExist(j, id);
}

bool IncidentStorage::DoesUnactiveIncidentIdExist(string id)
{
    json j;
    GetJsonUnactiveIncidents(j);
    return DoesIdExist(j, id);
}

// ----------------------------- File Functions ------------------
bool IncidentStorage::DoesFileExist(string file_path)
{
    ifstream input_file(file_path);
    if(input_file.is_open())
    {
        input_file.close();
        return true;
    }
    else
    {
        input_file.close();
        return false;
    }
}

bool IncidentStorage::DoesIncidentFileExist()
{
    return DoesFileExist(INCIDENTS);
}

bool IncidentStorage::DoesActiveIncidentFileExist()
{
    return DoesFileExist(ACTIVE_INCIDENTS);
}

bool IncidentStorage::DoesUnactiveIncidentFileExist()
{
    return DoesFileExist(UNACTIVE_INCIDENTS);
}

void IncidentStorage::remove_file(string file)
{
    // File does not exist
    if (!DoesFileExist(file))
    {
        cout<<"Does not exist: "<<file<<endl;
    }
    // Failed to remove
    else if (remove(file.c_str()) != 0)
    {
        cout<<"Remove Failed: "<<file<<endl;

    }
    // Removed sucessfully
    else
    {
        cout<<"Removed: "<<file<<endl;
    }
}
