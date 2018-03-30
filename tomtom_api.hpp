using namespace std;

string TomTomAPI::retrieve_incidents()
{
	string str = "<apiKey>";
	int len_str = str.length();

	string url = TOM_TOM_URL.replace(TOM_TOM_URL.find(str), len_str, get_key());
	return http_get(url);
}

list<Incident> TomTomAPI::parse_incidents(string incidents){
	list<Incident> inc_list;

	json j;
	try{
		j = json::parse(incidents)["tm"]["poi"];
	}
	// Error when loading incidents string into json
	catch(nlohmann::detail::parse_error e)
	{
		cout<<"Error: could not parse incidents into json."<<endl;
	}

	//Variables used to extract from the API response
	string id, f, t, r;
	float x, y;
	int ic, ty, l, dl;


	for(auto it = j.begin(); it != j.end(); it++)
	{

		id = it.value()["id"];
		x = it.value()["p"]["x"];
		y = it.value()["p"]["y"];
		ic = it.value()["ic"];
		ty = it.value()["ty"];
		l = it.value()["l"];

		//tags that may or may not be present
		try
		{
			f = it.value()["f"];
			t = it.value()["t"];
		}
		catch (nlohmann::detail::type_error e)
		{
			f = "";
			t = "";
		}

		try
		{
			dl = it.value()["dl"];
		}
		catch (nlohmann::detail::type_error e)
		{
			dl = -1;
		}

		try
		{
			r = it.value()["r"];
		}
		catch (nlohmann::detail::type_error e)
		{
			r = "";
		}

		Incident inc = Incident(id, f, t, r, x, y, ic, ty, l, dl);
		inc_list.push_back(inc);
	}

	return inc_list;
}
