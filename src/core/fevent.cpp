#include "fevent.hpp"

namespace fit
{

/*!
 * Default Constructor.
 *
 * \param type: Type of the event.
 * \param arg: Options for the event.
 */
FEvent::FEvent(FEvent::Type eventType, FObject& arg)
	: FObject(), m_type(eventType), m_arg(arg)
{}

/*!
 * Destructor.
 */
FEvent::~FEvent()
{

}

FEvent::Type     FEvent::getType() { return m_type; }
FEvent::FObject& FEvent::getArg()  { return m_arg; }

} // namespace fit
