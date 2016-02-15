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

//#define DEBUG 1

// Macros définitions
#define MACRO_ERRINDEX(index, size)	throw std::logic_error("Index out of range (" + to_string(index) + "/" + to_string(size) + ") at line " + to_string(__LINE__) + " in " + __FILE__;
#define MACRO_ERRNAMEMAP(key)		throw std::logic_error("Key does not exist (" + key + ") at line " + std::to_string(__LINE__)  + " in " + __FILE__);
#define MACRO_TEMPLATED template<typename T>

namespace fit
{

// Temporary renaming, FString class should be done in the future 
typedef std::string FString;

// Standard types renaming
typedef unsigned char		fuint8;
typedef unsigned short int	fuint16;
typedef unsigned int		fuint32;
typedef unsigned long int	fuint64;

/*!
 * \brief The FObject class is the base class for all other in this lib
 *        It has an id, and implements a basic toString (inspired from java)
 */
class FObject
{
    public:
		// Constructors - Destructor
			FObject();
			virtual ~FObject();
        
        // To string member function inspired from java
			virtual FString toString() const;
        
    protected:
        fuint16 m_id;   /* Unique identifier for all objects */
    
    private:
        static fuint16 nextID;  /* Counter to keep unique trace of all objects */
};

/*!
 *  \brief to_string: Converts any kind of element into a string via a std::stringstream
 *          works well with basic type, but needs operator<< for objects
 *  \param elem is any kind of value,
 *  \return FString containing the elem under the form of a string
 */
MACRO_TEMPLATED
inline static FString to_string(const T& elem)
{
	std::stringstream res;
	res << elem;
	
	return res.str();
}

}

#endif //FOBJECT_COMPILED
