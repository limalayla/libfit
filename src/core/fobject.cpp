#include "fobject.hpp"

namespace fit
{

/*!
 * \brief FObject::nextID keeps unique identifier of all object deriving from the FObject class
 */
fuint32 FObject::nextID = 0;

/*!
 * \brief FObject::FObject Default constructor
 */
FObject::FObject()
	: m_id(nextID)
{
	nextID++;
}

/*!
 * \brief FObject::~FObject Destructor
 */
FObject::~FObject()
{
	
}

/*!
 * \brief FObject::toString : get the debug info about an object (if possible in all classes) inspired by java
 * \return a string containing the useful informations about the object (recursively calls his parents)
 */
FString FObject::toString() const
{
	std::stringstream res;
	res << "FObject {" << m_id << " [" << this << "]}";

	return res.str();
}

}
