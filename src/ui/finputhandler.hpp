#ifndef FINPUTHANDLER_COMPILED
#define FINPUTHANDLER_COMPILED

#include "../core/fthreadable.hpp"

namespace fit
{

// Class to handle inputs (only keyboard for now)
class FInputHandler : public FThreadable
{
    public:
		// Constructors - Destructor
        FInputHandler();
        virtual ~FInputHandler();

		// Override of the start() function
		virtual void run(const bool* stop);
};

}
#include "../core/app.hpp"

#endif // FINPUTHANDLER_COMPILED

