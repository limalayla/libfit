#include "fevent.hpp"

namespace fit
{

/*!
 * Default Constructor
 * \param Type of the event
 * \param Options for the event
 */
FEvent::FEvent(fuint16 type, void* arg)
	: FObject(), m_type(type), m_arg(arg)
{}

/*!
 * Destructor
 */
FEvent::~FEvent()
{
	if(m_arg != nullptr) delete m_arg;
}

}
