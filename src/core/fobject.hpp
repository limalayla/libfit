#ifndef FOBJECT_COMPILED
#define FOBJECT_COMPILED

#include <algorithm>
#include <cmath>
#include <cstring>
#include <condition_variable>
#include <chrono>
#include <iostream>
#include <memory>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

#define DEBUG

// Macros definitions
#define MACRO_ERRINDEX(index, size)	throw std::logic_error("Index out of range (" + to_string(index) + "/" + to_string(size) + ") at line " + to_string(__LINE__) + " in " + __FILE__;
#define MACRO_ERRNAMEMAP(key)		throw std::logic_error("Key does not exist (" + key + ") at line " + std::to_string(__LINE__)  + " in " + __FILE__);
#define MACRO_TEMPLATED template<typename T>

namespace fit
{

//! Temporary renaming, FString class should be done in the future
typedef std::string FString;

//! Renamed unsigned int 8b
typedef unsigned char		fuint8;
//! Renamed unsigned int 16b
typedef unsigned short int	fuint16;
//! Renamed unsigned int 32b
typedef unsigned int		fuint32;
//! Renamed unsigned int 64b
typedef unsigned long int	fuint64;

//! Renamed int 8b
typedef char		fint8;
//! Renamed int 16b
typedef short int	fint16;
//! Renamed int 32b
typedef int		    fint32;
//! Renamed int 64b
typedef long int	fint64;

/**
 * Base class for all other classes of the lib.
 * Inspired by the Qt's QObject structure, it has an id, and implements a basic toString function
 */
class FObject
{
    public:
		FObject();
		virtual ~FObject();

		virtual FString toString() const;

    protected:
        fuint32 m_id;   /* Unique identifier for all objects */

    private:
        static fuint32 nextID;  /* Counter to keep unique trace of all objects */
};

/*!
 * Converts any kind of element to a string.
 * Use std::stringstream so data needs to implement operator<<
 *
 *  \param data: Data to convert.
 *  \return The data turned into an FString .
 */
MACRO_TEMPLATED
inline static FString to_string(const T& data)
{
	std::stringstream res;
	res << data;

	return res.str();
}

}

#endif //FOBJECT_COMPILED
