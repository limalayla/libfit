#include "fevent.hpp"

namespace fit
{

/*!
 * \brief FEvent::FEvent Constructor
 * \param type: Type of the event
 * \param arg:  Options for the event
 */
FEvent::FEvent(fuint16 type, void* arg)
	: FObject(), m_type(type), m_arg(arg)
{}

/*!
 * \brief FEvent::~FEvent Destructor
 */
FEvent::~FEvent()
{
	// ToDo
	if(m_arg != nullptr) delete m_arg;
}

}
