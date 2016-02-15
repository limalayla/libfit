#ifndef FINPUTHANDLER_COMPILED
#define FINPUTHANDLER_COMPILED

#include "../core/fthreadable.hpp"

namespace fit
{

/*!
 * \brief The FInputHandler class handles all inputs (keyboard etc) and create adequate events
 */
class FInputHandler : public FThreadable
{
    public:
		// Constructors - Destructor
        FInputHandler();
        virtual ~FInputHandler();

		// Override of the start() function
        void run(const bool* stop) override;
};

}

#include "../core/app.hpp"

#endif // FINPUTHANDLER_COMPILED

