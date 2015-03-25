#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "03";
	static const char MONTH[] = "02";
	static const char YEAR[] = "2014";
	static const char UBUNTU_VERSION_STYLE[] = "14.02";
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 2;
	static const long MINOR = 3;
	static const long BUILD = 125;
	static const long REVISION = 650;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 214;
	#define RC_FILEVERSION 2,3,125,650
	#define RC_FILEVERSION_STRING "2, 3, 125, 650\0"
	static const char FULLVERSION_STRING[] = "2.3.125.650";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 24;
	

}
#endif //VERSION_H
