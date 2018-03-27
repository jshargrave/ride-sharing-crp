/*
  Description: incident class used to represent traffic incidents
*/

using namespace std;

#ifndef INCIDENT_H
#define INCIDENT_H

class Incident {
	private:
		string id, f, t, r;
		double x, y;
		int ic, ty, l, dl;

	public:
		/*
			Desc: Constructor used to initialize all values
		*/
		Incident(string id, string f, string t, string r, double x, double y,
						 int ic, int ty, int l, int dl):
						 id(id), f(f), t(t), r(r), x(x), y(y), ic(ic), ty(ty), l(l), dl(dl)
						 {}

		// ---------------- Accessor Functions ------------
		string GetID(){return id;}
		string GetF(){return f;}
		string GetT(){return t;}
		string GetR(){return r;}

		double GetX(){return x;}
		double GetY(){return y;}

		int GetIC(){return ic;}
		int GetTY(){return ty;}
		int GetL(){return l;}
		int GetDL(){return dl;}

		// ----------------- Setter Functions --------------
		void SetID(string ID){id = ID;}
		void SetF(string F){f = F;}
		void SetT(string T){t = T;}
		void SetR(string R){r = R;}

		void SetX(double X){x = X;}
		void setY(double Y){y = Y;}

		void SetIC(int IC){ic = IC;}
		void SetTY(int TY){TY = ty;}
		void SetL(int L){l = L;}
		void SetDL(int DL){dl = DL;}

}; // Incident

#endif // INCIDENT_H
