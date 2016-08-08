#include "fobject.hpp"

namespace fit
{

fuint32 FObject::nextID = 0;

/*!
 * Base constructor.
 */
FObject::FObject()
	: m_id(nextID)
{
	nextID++;
}

/*!
 * Destructor.
 */
FObject::~FObject()
{

}

/**
 * Get the debug info about an object (if possible in all classes) coming from java.
 *
 * \return String containing useful informations about the object (meant to recursively call his parents)
 */
FString FObject::toString() const
{
	std::stringstream res;
	res << "FObject {" << m_id << " [" << this << "]}";

	return res.str();
}

}
