#include "fobject.hpp"

namespace fit
{
	
fuint16 FObject::nextID = 0;

FObject::FObject()
	: m_id(nextID)
{
	nextID++;
}

FObject::~FObject()
{
	
}

FString FObject::toString() const
{
	/* Return a string describing the object
	 * Inspired of java
	 * Meant to be redefined in each inheriting class
	*/
	
	std::stringstream res;
	res << "FObject: " << m_id << " [" << this << "]";
	
	return res.str();
}

}
