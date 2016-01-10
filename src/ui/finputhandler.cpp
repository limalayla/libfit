#include "finputhandler.hpp"

namespace fit
{
	
FInputHandler::FInputHandler()
	: FObject()
{}

FInputHandler::~FInputHandler()
{
	
}

void FInputHandler::run(const bool* stop)
{
	char input(' ');
	
	while(!*stop)
	{
		input = std::cin.get();
		App::addEvent(FEvent::keyPressed, (void*) new char(input));
	}
}

}

