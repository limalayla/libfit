#include "headers/Core"
#include "headers/UI"

using namespace fit;

int main(int argn, char* argv[])
{
	// Create the app
	App ex(argn, argv);
	
	// Extract the ui, to perform action on it directly
    UI& console = ex.ui();
    
    // Adding widgets is done this way
    console.add("rect1", new FWidget(FRect(0, 0, 3, 10)));
    console.add("rect2", new FWidget(FRect(0, 50, 10, 50)));
    console.add("rect3", new FWidget(FRect(20, 20, 20, 20)));
    
    // Accessing a widget of the ui is done this way
    console["rect2"]->initPattern(FWidget::testPattern);
    //console["rect1"]->hide();
    
    // Temporary workaround just to see a ui displayed
    // (The ui is supposed to update and display itself on its own)
    console.display();

	// Debug
	std::cout << console["rect1"]->toString() << std::endl;

	// The app has a state, which can be set at anytime by the user
    return ex.state();
}
