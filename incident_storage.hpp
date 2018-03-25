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
  j["test"] = 2;

  //
  ofstream output(INCIDENTS);
  output << setw(4) << j << endl;
}

void IncidentStorage::MakeActive(string id){

}

void IncidentStorage::StoreAActiveIncident(string id){

}

void IncidentStorage::MakeUnactive(string id){

}

void IncidentStorage::StoreAUnactiveIncident(string id){

}

bool IncidentStorage::DoesFileExist(string file_path){
  ifstream input_file(file_path);
  if(input_file.is_open()){
    return true;
  }
  else{
    return false;
  }
}

void IncidentStorage::CreateFile(string file_path){

}
