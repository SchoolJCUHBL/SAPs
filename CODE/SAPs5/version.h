#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "06";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] = "14.01";
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 4;
	static const long BUILD = 185;
	static const long REVISION = 968;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 476;
	#define RC_FILEVERSION 2,4,185,968
	#define RC_FILEVERSION_STRING "2, 4, 185, 968\0"
	static const char FULLVERSION_STRING[] = "2.4.185.968";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 34;
	

}
#endif //VERSION_H
