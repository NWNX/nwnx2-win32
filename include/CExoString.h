#ifndef _H_CEXOSTRING_
#define _H_CEXOSTRING_

class CExoString {
public:
	char *text;
	unsigned __int32 len; // do NOT rely on the length of this for any comparison
						  // if a shorter string is assigned to a longer one (A = B), len will still be the original length 

	CExoString();
	CExoString(CExoString const &Source);
	CExoString(char const *Source);
	CExoString(char const *Source, int Length);
	CExoString(int Number);
	~CExoString();

	char *CStr();
	bool operator!=(CExoString const &Comp);
	bool operator!=(char const *Comp);
	bool operator==(CExoString const &Comp);
	bool operator==(char const *c);
	CExoString &operator=(CExoString const &Op);
	CExoString &operator=(char const *Op);
	CExoString operator+(CExoString const &Op);
	CExoString operator+(char const *Op);

	int	AsTAG(CExoString *ExoString);
	int StripNonAlphaNumeric(int a1, int a2, int a3);

};

#endif