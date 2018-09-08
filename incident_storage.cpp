using namespace std;

IncidentStorage::IncidentStorage()
{

}

IncidentStorage::~IncidentStorage()
{

}

void IncidentStorage::StoreIncidents(list<list<Incident> >& all_inc)
{
    // Looping through all api's (most likely just one)
    for(auto it = all_inc.begin(); it != all_inc.end(); it++)
    {
        // Looping through all incidents
        for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            // Calling a function to store the incident in a json file
            StoreAIncident(*it2);
        }
    }
}

void IncidentStorage::StoreAIncident(Incident& inc)
{
    // Get Incidents data
    json j = GetJsonIncidents();

    // Add new incident to json
    j[inc.GetID()] = ParseIncident(inc);

    // Write json to file
    WriteJsonIncidents(j);
}

void IncidentStorage::MakeActive(string id)
{
    // Need to define function
}

void IncidentStorage::StoreAActiveIncident(string id)
{
    // Need to define function
}

void IncidentStorage::MakeUnactive(string id)
{
    // Need to define function
}

void IncidentStorage::StoreAUnactiveIncident(string id)
{
    // Need to define function
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
void IncidentStorage::WriteJson(json j, string file)
{
    // Write incidents to INCIDENTS
    ofstream output(file);
    output << setw(4) << j << endl;
}

void IncidentStorage::WriteJsonIncidents(json j)
{
    WriteJson(j, INCIDENTS);
}

void IncidentStorage::WriteJsonActiveIncidents(json j)
{
    WriteJson(j, ACTIVE_INCIDENTS);
}

void IncidentStorage::WriteJsonUnactiveIncidents(json j)
{
    WriteJson(j, UNACTIVE_INCIDENTS);
}

// -------------------------- Get json Function --------------------------
json IncidentStorage::GetJson(string file)
{
    json j;
    // Check if INCIDENTS file exist
    if(DoesFileExist(file))
    {
        // File does exist
        // Parse all information into a json object
        ifstream input(file);
        input >> j;
        input.close();
    }
    return j;
}

json IncidentStorage::GetJsonIncidents()
{
    return GetJson(INCIDENTS);
}

json IncidentStorage::GetJsonActiveIncidents()
{
    return GetJson(ACTIVE_INCIDENTS);
}

json IncidentStorage::GetJsonUnactiveIncidents()
{
    return GetJson(UNACTIVE_INCIDENTS);
}

// ---------------------------- Does Id Exist Functions ------------------
bool IncidentStorage::DoesIdExist(json j, string id)
{
    j.at(id);
    return true;
}

bool IncidentStorage::DoesIncidentIdExist(string id)
{
    return DoesIdExist(GetJsonIncidents(), id);
}

bool IncidentStorage::DoesActiveIncidentIdExist(string id)
{
    return DoesIdExist(GetJsonActiveIncidents(), id);
}

bool IncidentStorage::DoesUnactiveIncidentIdExist(string id)
{
    return DoesIdExist(GetJsonUnactiveIncidents(), id);
}

// ----------------------------- Does File Exist Functions ------------------
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
