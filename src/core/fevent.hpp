#ifndef FEVENT_HPP
#define FEVENT_HPP

#include "fobject.hpp"

namespace fit
{

/*!
 * Class representing any kind of evenement, along with some options (eg: keyPressed -> keyID)
 */
class FEvent : public FObject
{
public:
    enum Type
    {
    	keyPressed,
    	dummySize
    };

    // Constructors - Destructor
    FEvent(Type type, FObject& arg);
    virtual ~FEvent();

    Type     getType();
    FObject& getArg();

private:
    //std::mutex m_mutex;
    //std::condition_variable m_cv;
    Type m_type;
    FObject m_arg;      /* Options passed along with the event */

}; // Class FEvent

} // Namespace fit

#endif // FEVENT_HPP
