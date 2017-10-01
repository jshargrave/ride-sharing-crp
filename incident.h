/*
  Description: incident class used to represent traffic incidents
*/

using namespace std;

#ifndef INCIDENT_H
#define INCIDENT_H

class Incident {
	private:
		string id, f, t, r;
		float x, y;
		int ic, ty, l, dl;

	public:
		Incident(string id, string f, string t, string r, float x, float y, int ic, int ty, int l, int dl): id(id), f(f), t(t), r(r), x(x), y(y), ic(ic), ty(ty), l(l), dl(dl) {}
		
		string get_id(){return id;}

}; // Incident

#include "incident.hpp"
#endif // INCIDENT_H