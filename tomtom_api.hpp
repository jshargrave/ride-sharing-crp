using namespace std;

string TomTomAPI::retrieve_incidents()
{
	string str = "<apiKey>";
	int len_str = str.length();

	string url = TOM_TOM_URL.replace(TOM_TOM_URL.find(str), len_str, get_key());
	return http_get(url);
}

list<Incident*> TomTomAPI::pack_incidents(){
	list<Incident*> inc_list;

	return inc_list;
}