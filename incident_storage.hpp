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
  json j;
  // Check if INCIDENTS file exist
  if(DoesFileExist(INCIDENTS)){
    // File does exist
    // Parse all information into a json object
    ifstream input(INCIDENTS);
    input >> j;
    input.close();
  }
  j[inc.GetID()] = ParseIncident(inc);

  // Writing to file
  ofstream output(INCIDENTS);
  output << setw(4) << j << endl;
}

void IncidentStorage::StoreAActiveIncident(string id){
  json j_inc;
  // Check if ACTIVE_INCIDENTS file exist
  if(DoesFileExist(INCIDENTS)){
    // File does exist
    // Parse all information into a json object
    ifstream input(INCIDENTS);
    input >> j_inc;
    input.close();
  }

  // If the incident id cannot be found
  if(j_inc.find(id) == j_inc.end()){
    throw IncIDDoesNotExist("Incident id: "+id+" does not exist");
  }

  json j_active;
  if(DoesFileExist(ACTIVE_INCIDENTS)){
    // File Does DoesFileExist
    // Parse all information into a json object
    ifstream input(ACTIVE_INCIDENTS);
    input >> j_active;
    input.close();
  }
  j_active[id] = true;

  // Writing to file
  ofstream output(ACTIVE_INCIDENTS);
  output << setw(4) << j_active << endl;
}

void IncidentStorage::StoreAUnactiveIncident(string id){

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
