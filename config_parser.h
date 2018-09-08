#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

/*
Desc: Parses the config file into a map<string, stirng>.
*/
map<string, string> ConfigParser(string file_path)
{
	map<string, string> config_values;

	string line, key, value;
	ifstream file;
	file.open(file_path.c_str());

	if (file.is_open())
	{
		while(getline(file, line))
		{
			//Ignore lines starting with '#'
			if(line[0] == '#')
			{
				continue;
			}
			if(line.find('=') != string::npos)
			{
				key = line.substr(0, line.find('='));
				value = line.substr(line.find('=') + 1, line.length() - line.find('='));
				config_values.insert(pair<string, string>(key, value));
			}
		}
	}
	else{
		cout<<"Error: could not open file \""<<file_path<<"\""<<endl;
	}
	return config_values;
}
