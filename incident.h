/*
  Description: incident class used to represent traffic incidents
*/

using namespace std;

#ifndef INCIDENT_H
#define INCIDENT_H

class Incident {
	private:
		// Incident variables being set to default values
		string id = "";
		string f = "";
		string t = "";
		string r = "";
		double x = 0;
		double y = 0;
		int ic = 0;
		int ty = 0;
		int l = 0;
		int dl = 0;

	public:
		/*
		Desc: Constructor used to initialize all values
		*/
		Incident(string id, string f, string t, string r, double x, double y,
			     int ic, int ty, int l, int dl)
		{
			SetID(id);
			SetF(f);
			SetT(t);
			SetR(r);
			SetX(x);
			SetY(y);
			SetIC(ic);
			SetTY(ty);
			SetL(l);
			SetDL(dl);
		}

		// ---------------- Accessor Functions -------------------------------
		// string
		string GetID(){return id;}
		string GetF(){return f;}
		string GetT(){return t;}
		string GetR(){return r;}
		// double
		double GetX(){return x;}
		double GetY(){return y;}
		// int
		int GetIC(){return ic;}
		int GetTY(){return ty;}
		int GetL(){return l;}
		int GetDL(){return dl;}

		// ----------------- Setter Functions -------------------------------
		// string
		void SetID(string ID){id = ID;}
		void SetF(string F){f = F;}
		void SetT(string T){t = T;}
		void SetR(string R){r = R;}
		// double
		void SetX(double X){x = X;}
		void SetY(double Y){y = Y;}
		// int
		void SetIC(int IC){ic = IC;}
		void SetTY(int TY){TY = ty;}
		void SetL(int L){l = L;}
		void SetDL(int DL){dl = DL;}

		// ------- Functions used to check if variables have been set --------
		bool isID(){return id != "";}
		bool isF(){return f != "";}
		bool isT(){return t != "";}
		bool isR(){return r != "";}
		bool isX(){return x != 0;}
		bool isY(){return y != 0;}
		bool isIC(){return y != 0;}
		bool isTY(){return y != 0;}
		bool isL(){return y != 0;}
		bool isDL(){return y != 0;}

}; // Incident

#endif // INCIDENT_H
