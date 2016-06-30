#include "finputhandler.hpp"

namespace fit
{

/*!
 * \brief FInputHandler::FInputHandler Default constructor
 */
FInputHandler::FInputHandler()
	: FObject()
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
	char input(' ');
	
	while(!*stop)
	{
		input = std::cin.get();
        //App::addEvent(FEvent::Type::keyPressed, (void*) new char(input));
	}
}

}

