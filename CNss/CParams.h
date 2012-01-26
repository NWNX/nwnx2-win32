#pragma once

//#include "stdafx.h"
#include <iostream>
#include <sstream>

using std::stringstream;
using std::string;

class CParams {
private:
	template <class T>
	static int HandleCHAR(stringstream &ss, T &P1) {
		if (typeid(P1) == typeid(unsigned char) || typeid(P1) == typeid(char)) {
			int p =0;
			ss >> p;
			P1 = static_cast<unsigned char>(p);
			return 1;
		}
		return 0;
	}

public:
	template <class T>
	static void ExtractP1(const char *Params, T &P1) {
		stringstream ss(Params);
		if (!HandleCHAR(ss, P1)) {
			ss >> P1;
		}
	}

	template <class T, class N>
	static void ExtractP2(const char *Params, T &P1, N &P2, char delim = ' ') {
		stringstream ss;
		string s(Params);
		s += delim;
		int start=0, ip=0;
		ip = s.find(delim);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P1)) {
			ss >> P1;
		}
		ss.clear();

		start = ip+1; ip = s.find(delim, start);
		ss << s.substr(start, ip-start); 
		if (!HandleCHAR(ss, P2)) {
			ss >> P2;
		}
	}

	template <class T, class N, class M>
	static void ExtractP3(const char *Params, T &P1, N &P2, M &P3, char delim = ' ') {
		stringstream ss;
		string s(Params);
		s += delim;
		int start=0, ip=0;
		ip = s.find(delim);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P1)) {
			ss >> P1;
		}
		ss.clear();

		start = ip+1; ip = s.find(delim, start);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P2)) {
			ss >> P2;
		}
		ss.clear();

		start = ip+1; ip = s.find(delim, start);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P3)) {
			ss >> P3;
		}
	}

	template <class T, class N, class M, class L>
	static void ExtractP4(const char *Params, T &P1, N &P2, M &P3, L &P4, char delim = ' ') {
		stringstream ss;
		string s(Params);
		s += delim;
		int start=0, ip=0;

		ip = s.find(delim);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P1)) {
			ss >> P1;
		}
		ss.clear();

		start = ip+1; ip = s.find(delim, start);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P2)) {
			ss >> P2;
		}
		ss.clear();

		start = ip+1; ip = s.find(delim, start);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P3)) {
			ss >> P3;
		}
		ss.clear();

		start = ip+1; ip = s.find(delim, start);
		ss << s.substr(start, ip-start);
		if (!HandleCHAR(ss, P4)) {
			ss >> P4;
		}
	}
};