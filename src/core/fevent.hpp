#ifndef FEVENT_COMPILED
#define FEVENT_COMPILED

#include "fobject.hpp"

namespace fit
{

class FEvent : public FObject
{
    public:
		// Constructors - Destructor
        FEvent(fuint16 type, void* arg);
        virtual ~FEvent();
        
		enum KeyboardEvents
		{
			keyPressed = 1
		};
        
	private:
		fuint16 m_type;
		void* m_arg;
};

}

#endif // FEVENT_COMPILED

