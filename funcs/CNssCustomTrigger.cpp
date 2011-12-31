#include "stdafx.h"
#include "CNssCustomTrigger.h"
#include <math.h>

CNssCustomTrigger::CNssCustomTrigger(void) {
	bUseAbsoluteCoordinates = false;
	bUseCustomTriggerGeometry = false;

	AddFunction("SETCUSTOMGEOMETRY", L_CAST(&CNssCustomTrigger::SetCustomGeometry));
	AddFunction("ROTATECUSTOMGEOMETRY", L_CAST(&CNssCustomTrigger::RotateCustomGeometry));
	AddFunction("GETTRIGGERGEOMETRY", L_CAST(&CNssCustomTrigger::GetTriggerGeometry));
}

bool CNssCustomTrigger::CreateCustomGeometry(CNWSTrigger *pTHIS, CScriptLocation *Loc, CNWSArea *Area) {
	if (bUseCustomTriggerGeometry) {
		CreateGeometry(pTHIS, Loc, Area);
		bUseCustomTriggerGeometry = false;
		Coordinates.clear();
		return true;
	}
	return false;
}


void CNssCustomTrigger::CreateGeometry(CNWSTrigger *Trigger, CScriptLocation *Loc, CNWSArea *Area) {
	Vector *Position;
	Vector *v8;
	int nVertex;
	Vector *v10;

	int nCoordinates = (Coordinates.size() / 2)+1; // Loc holds the first coordinate

	Position = Trigger->geometry_vectors;
	Trigger->VerticesCount = nCoordinates;
	Trigger->Geometry_len = nCoordinates;
	if ( Position )	{
		delete[] Position;
		Trigger->geometry_vectors = 0;
	}
	if ( Trigger->Vertices ) {
		delete[] Trigger->Vertices;
		Trigger->Vertices = 0;
	}

	if ( Area && !Coordinates.empty()) {
		float x, y;

		v8 = new Vector[nCoordinates];
		// zero all coords
		if ( v8 ) {
			v10 = (Vector *)((char *)v8 + 8);
			nVertex = nCoordinates;
			do {
				*((DWORD *)v10 - 2) = 0;
				*((DWORD *)v10 - 1) = 0;
				v10->x = 0;
				++v10;
				--nVertex;
			}
			while ( nVertex );
		}
		else {
			v8 = 0;
		}

		Trigger->geometry_vectors = v8;
		Trigger->Vertices = new unsigned int[4*nCoordinates];// Why times 4?

		Trigger->geometry_vectors[0].x = Loc->loc_position.x;
		Trigger->geometry_vectors[0].y = Loc->loc_position.y;
		Trigger->geometry_vectors[0].z = static_cast<float>(Area->ComputeHeight(
			Trigger->geometry_vectors[0].x,
			Trigger->geometry_vectors[0].y,
			Trigger->geometry_vectors[0].z));
		Trigger->Vertices[0] = 0;

		int i=1;
		std::vector<float>::iterator it = Coordinates.begin();
		while (it != Coordinates.end()) {
			x = *it + !bUseAbsoluteCoordinates * Loc->loc_position.x;
			it++;
			y = *it + !bUseAbsoluteCoordinates * Loc->loc_position.y;
			it++;



			Trigger->geometry_vectors[i].x = x;
			Trigger->geometry_vectors[i].y = y;
			Trigger->geometry_vectors[i].z = static_cast<float>(Area->ComputeHeight(
				Trigger->geometry_vectors[i].x,
				Trigger->geometry_vectors[i].y,
				Trigger->geometry_vectors[i].z));
			Trigger->Vertices[i] = i;

			++i;
		}
	}
}

int CNssCustomTrigger::SetCustomGeometry(CGameObject *oObject, char *Params) {
	std::string floats = Params, sTemp;

	int iStart = 0;
	int iP = floats.find("¬", iStart);
	float f;

	if (iP != std::string::npos) {
		sTemp = floats.substr(iStart, iP-iStart);
		sscanf(sTemp.c_str(), "%d", &bUseAbsoluteCoordinates);
		
		iStart = iP+1; iP = floats.find("¬", iStart);

		if (Coordinates.size() > 0) {
			Coordinates.clear();
		}
		while (iP != std::string::npos) {
			sTemp = floats.substr(iStart, iP-iStart); iStart = iP+1; iP = floats.find("¬", iStart);
			sscanf(sTemp.c_str(), "%f", &f);
			Coordinates.push_back(f);
		}

		if (Coordinates.size() < 4 || (Coordinates.size() % 2) != 0) {
			_log(2, "o Error: invalid number of coordinates\n");
			Coordinates.clear();
			bUseCustomTriggerGeometry = false;
			sprintf(Params, "-1");
			return 0;
		}
		else {
			bUseCustomTriggerGeometry = true;
			_log(3, "coordinates valid\n");
		}
	}
	else {
		_log(2, "o Error: Invalid number of coordinates\n");
		Coordinates.clear();
		bUseCustomTriggerGeometry = false;
		return 0;
	}

	return 1;
}

int CNssCustomTrigger::RotateCustomGeometry(CGameObject *oObject, char *Params) {
	float fAngle = 0.0;

	if ((sscanf(Params, "%f", &fAngle) != 1)
		||Coordinates.empty()) {
			sprintf(Params, "-1");
			return 0;
	}

	std::vector<float> rotate;
	std::vector<float>::iterator it;

	float fx, fy, fx_n, fy_n, sini, cosi;
	for (it=Coordinates.begin(); it != Coordinates.end(); it++) {
		fx = *it;
		it++;
		fy = *it;

		sini = static_cast<float>(sin(fAngle*0.0174532925199));
		cosi = static_cast<float>(cos(fAngle*0.0174532925199));
		fx_n = fx * cosi + fy * sini;
		fy_n = -(fx * sini) + fy * cosi;
		rotate.push_back(fx_n);
		rotate.push_back(fy_n);
	}

	Coordinates.clear();
	Coordinates = rotate;

	return 1;
}

int CNssCustomTrigger::GetTriggerGeometry(CGameObject *oObject, char *Params) {
	CNWSTrigger *Trigger = (CNWSTrigger*)oObject;
	sprintf(Params, "");

	if (!Trigger || Trigger->obj_type2 != 7) {
		_log(3, "o Error: GetTriggerGeometry used on non Trigger object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	char c[40];
	int Verts = Trigger->VerticesCount;
	_log(3, "Verts: %d\n", Verts);

	std::string sReturn;

	Vector *v;
	if (Verts > 0) {
		for (int i=0; i<Verts; i++) {
			v = &Trigger->geometry_vectors[i];
			sprintf(c, "%.3f", v->x); sReturn += c; sReturn += "¬";
			sprintf(c, "%.3f", v->y); sReturn += c; sReturn += "¬";
		}
		sprintf(Params, "%s", sReturn.c_str());
	}
return 1;
}