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
		// Stores the api_key used from making request from the API
		string api_key = "";

	public:
		/*
		Desc: Pure virtual constructor
		*/
		BaseAPI();

		/*
		Desc: Pure virtual deconstructor
		*/
		~BaseAPI();

		/*
		Desc: Pure virtual function used to pull incidents from API.
		*/
		virtual string retrieve_incidents() = 0;

		/*
		Desc: Pure virtual function used to parse api response into a list of
			  incident's.
		*/
		virtual list<Incident> parse_incidents(string incidents) = 0;

		/*
		Desc: Accessor for the api_key.
		*/
		const string get_key()const {return api_key;}

		/*
		Desc: Mutator for the api_key.
		*/
		void set_key(string key) {api_key = key;}

		/*
		Desc: Function used for making html request.  Main method used for
			  making API calls.
		*/
		virtual string http_get(string url);

		/*
		Desc: Function used for making a write callback to save the contents of
			  the curl html response into a string.
		*/
		static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

}; //BaseAPI

#include "base_api.cpp"
#include "json.hpp"
#endif // BASE_API_H
