using namespace std;

string TomTomAPI::retrieve_incidents()
{
	string str = "<apiKey>";
	int len_str = str.length();

	string url = TOM_TOM_URL.replace(TOM_TOM_URL.find(str), len_str, get_key());
	return http_get(url);
}

list<Incident*> TomTomAPI::parse_incidents(string incidents){
	list<Incident*> inc_list;
	//cout<<incidents<<endl;
	//json_error_t error;
	//json_t *root = json_loads(incidents, 0, &error);

	return inc_list;
}