#ifndef FTHREADABLE_COMPILED
#define FTHREADABLE_COMPILED

#include "../core/fobject.hpp"

namespace fit
{

/*!
 * Interface for all classes that can be runned into threads
 */
class FThreadable : virtual public FObject
{
    public:
        FThreadable();
        virtual ~FThreadable();
        
        virtual void run(const bool* stop) = 0;
};

}

#endif // FTHREADABLE_COMPILED
