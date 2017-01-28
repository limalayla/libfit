#include "finputhandler.hpp"

namespace fit
{

/*!
 * \brief FInputHandler::FInputHandler Default constructor
 */
FInputHandler::FInputHandler(App& parent)
	: FObject(), m_parent(parent)
{}

/*!
 * \brief FInputHandler::~FInputHandler Default desctructor
 */
FInputHandler::~FInputHandler()
{

}

/*!
 * \brief FInputHandler::run Implementation of the virtual FThreadable::run -> Infinite loop, waiting to end or to add an event when
 * \param stop: Boolean shared with the calling thread to tell the loop to end, so the thread can stop cleanly
 */
void FInputHandler::run(const bool* stop)
{
	FChar input;

	while(!*stop)
	{
		input.set(std::cin.get());
        m_parent.addEvent(FEvent::Type::keyPressed, input);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

}

