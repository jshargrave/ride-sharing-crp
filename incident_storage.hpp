using namespace std;

IncidentStorage::IncidentStorage(){

}

void IncidentStorage::StoreIncidents(list<list<Incident> >& all_inc){
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

void IncidentStorage::StoreAIncident(Incident& inc){
  // Getting json data
  json j = GetJsonFile(INCIDENTS);

  // Writing incident data to json
  j[inc.GetID()] = ParseIncident(inc);

  // Writing json to file
  WriteJsonToFile(INCIDENTS, j);
}

void IncidentStorage::StoreAActiveIncident(string id){
  // If the incident id cannot be found in INCIDENTS file, throw exception
  if(!DoesIDExistInFile(id, INCIDENTS))
  {
    throw IncIDDoesNotExist("Incident id: "+id+" does not exist");
  }

  // Get ACTIVE_INCIDENTS json and erase incident with id
  json j = GetJsonFile(ACTIVE_INCIDENTS);
  j[id] = true;
  WriteJsonToFile(ACTIVE_INCIDENTS, j);
}

void IncidentStorage::StoreAInactiveIncident(string id){
  // If the incident id cannot be found in INCIDENTS or ACTIVE_INCIDENTS file,
  // throw exception
  if(!DoesIDExistInFile(id, INCIDENTS) ||
     !DoesIDExistInFile(id, ACTIVE_INCIDENTS))
  {
    throw IncIDDoesNotExist("Incident id: "+id+" does not exist");
  }

  // Get INCIDENTS json and erase incident with id
  json j = GetJsonFile(INCIDENTS);
  j.erase(id);
  WriteJsonToFile(INCIDENTS, j);

  // Get ACTIVE_INCIDENTS json and erase incident id
  j = GetJsonFile(ACTIVE_INCIDENTS);
  j.erase(id);
  WriteJsonToFile(ACTIVE_INCIDENTS, j);

  // Get INACTIVE_INCIDENTS json and add id
  j = GetJsonFile(INACTIVE_INCIDENTS);
  j[id] = true;
  WriteJsonToFile(INACTIVE_INCIDENTS, j);
}

bool IncidentStorage::DoesIDExistInFile(string id, string file)
{
  json j = GetJsonFile(file);
  if(j.find(id) == j.end())
  {
    cout<<id<<": "<<file<<" false"<<endl;
    return false;
  }
  return true;
}

json IncidentStorage::GetJsonFile(string file)
{
  json j;
  // If no file, then retuen json {}
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

void IncidentStorage::WriteJsonToFile(string file, json j)
{
  // Writing to file
  ofstream output(file);
  output << setw(4) << j << endl;
  output.close();
}

bool IncidentStorage::DoesFileExist(string file_path){
  ifstream input_file(file_path);
  if(input_file.is_open()){
    input_file.close();
    return true;
  }
  else{
    input_file.close();
    return false;
  }
}

json IncidentStorage::ParseIncident(Incident& inc){
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
