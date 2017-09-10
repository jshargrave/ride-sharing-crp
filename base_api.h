#include <curl/curl.h>
#include <string>
#include <list>
#include "incident.h"

using namespace std;

#ifndef BASE_API_H
#define BASE_API_H

class BaseAPI {
	private:

	protected:
		string api_key;
		string updates;

	public:
		virtual string retrieve_incidents() = 0;
		virtual list<Incident*> pack_incidents() = 0;
	

		string get_key()const {return api_key;}
		string get_updates()const {return updates;}

		void set_key(string key) {api_key = key;}
		void set_updates(string upd) {updates=upd;}

		string http_get(string url);
		static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);


}; //BaseAPI

#include "base_api.hpp"
#endif // BASE_API_H