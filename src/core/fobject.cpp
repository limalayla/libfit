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

template<typename T>
FString to_string(const T& elem)
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
