#ifndef FOBJECT_COMPILED
#define FOBJECT_COMPILED

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>

// Macros définitions
#define MACRO_ERRINDEX(index, size)	throw std::logic_error("Index out of range (" + to_string(index) + "/" + to_string(size) + ") at line " + to_string(__LINE__) + " in " + __FILE__;
#define MACRO_ERRNAMEMAP(key)		throw std::logic_error("Key does not exist (" + key + ") at line " + std::to_string(__LINE__)  + " in " + __FILE__);
#define TEMPLATE_ template<typename T>

namespace fit
{

// Temporary renaming, FString class should be done in the future 
typedef std::string FString;

// Standard type renaming
typedef unsigned char		fuint8;
typedef unsigned short int	fuint16;
typedef unsigned int		fuint32;
typedef unsigned long int	fuint64;

// Base class for all other classes
class FObject
{
    public:
		// Constructors - Destructor
			FObject();
			virtual ~FObject();
        
        // To string member function inspired from java
			virtual FString toString() const;
        
    protected:
        fuint16 m_id;
    
    private:
		// Counter to keep unique trace of all objects
        static fuint16 nextID;
};

// General to_string function
template<typename T>
inline static FString to_string(const T& elem)
{
	/* Return the result of putting the value in a iostream
	 * Works well with all standard type,
	 * but needs an overriding of operator<< in order to work with custom classes
	*/
	
	std::stringstream res;
	res << elem;
	
	return res.str();
}

}

#endif //FOBJECT_COMPILED
