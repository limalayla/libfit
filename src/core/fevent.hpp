#ifndef FEVENT_COMPILED
#define FEVENT_COMPILED

#include "fobject.hpp"

namespace fit
{

/*!
 * \brief The FEvent class is meant to contain any kind of evenement, along with some options (eg: keyPressed - keyID)
 * \todo Instead of void*, should be templated ?
 */
class FEvent : public FObject
{
    public:
		// Constructors - Destructor
        FEvent(fuint16 type, void* arg);
        virtual ~FEvent();

        void wait();
        
    private:
        //std::mutex m_mutex;
        //std::condition_variable m_cv;
        fuint16 m_type;
        void*   m_arg;      /* Options passed along with the event */
};

}

#endif // FEVENT_COMPILED

