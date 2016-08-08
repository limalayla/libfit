#ifndef FEVENT_HPP
#define FEVENT_HPP

#include "fobject.hpp"

namespace fit
{

/*!
 * Class representing any kind of evenement, along with some options (eg: keyPressed - keyID)
 *
 * \todo Find a way of working (only that… *sigh*)
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

}; // Class FEvent

} // Namespace fit

#endif // FEVENT_HPP
