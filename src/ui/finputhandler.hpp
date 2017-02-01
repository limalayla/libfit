#ifndef FINPUTHANDLER_COMPILED
#define FINPUTHANDLER_COMPILED

#include "../core/fthreadable.hpp"
#include "../core/fchar.hpp"
#include "../core/fevent.hpp"
//#include "../core/app.hpp"

namespace fit
{
class App;

/*!
 * \brief The FInputHandler class handles all inputs (keyboard etc) and create adequate events
 *
 * Quite simple as of now, but could get more complex as features are added
 */
class FInputHandler : public FThreadable
{
public:
	// Constructors - Destructor
	FInputHandler(App& parent);
	virtual ~FInputHandler();

	// Override of the start() function
	void run(const bool* stop) override;

private:
	App& m_parent;
};

}

#include "../core/app.hpp"

#endif // FINPUTHANDLER_COMPILED

