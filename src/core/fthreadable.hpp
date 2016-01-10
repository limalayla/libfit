#ifndef FTHREADABLE_COMPILED
#define FTHREADABLE_COMPILED

#include "../core/fobject.hpp"

namespace fit
{

// Interface for all objects that can be runned into threads
class FThreadable : virtual public FObject
{
    public:
		// Constructors - Destructor
        FThreadable();
        virtual ~FThreadable();
        
        virtual void run(const bool* stop) = 0;
};

}

#endif // FTHREADABLE_COMPILED

