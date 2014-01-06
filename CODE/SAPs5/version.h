#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "05";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] = "14.01";
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 3;
	static const long BUILD = 112;
	static const long REVISION = 596;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 313;
	#define RC_FILEVERSION 2,3,112,596
	#define RC_FILEVERSION_STRING "2, 3, 112, 596\0"
	static const char FULLVERSION_STRING[] = "2.3.112.596";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 11;
	

}
#endif //VERSION_H
