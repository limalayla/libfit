#include "fevent.hpp"

namespace fit
{

FEvent::FEvent(fuint16 type, void* arg)
	: FObject(), m_type(type), m_arg(arg)
{}

FEvent::~FEvent()
{
	// ToDo
	if(m_arg != nullptr) delete m_arg;
}

}
