#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "04";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] = "14.01";
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 1;
	static const long BUILD = 6;
	static const long REVISION = 18;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 12;
	#define RC_FILEVERSION 2,1,6,18
	#define RC_FILEVERSION_STRING "2, 1, 6, 18\0"
	static const char FULLVERSION_STRING[] = "2.1.6.18";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 5;
	

}
#endif //VERSION_H