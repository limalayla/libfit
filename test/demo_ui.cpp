#include "../src/core/app.hpp"
#include "../src/ui/flabel.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
	// Create the app
    App ex(argn, argv);

	// Extract UI to perform action on it directly
    UI& console = ex.ui();

    // Adding widgets
    console.add("rect1" , new FWidget(FRect(0, 0, 3, 10)));
    console.add("rect2" , new FWidget(FRect(0, 50, 10, 50)));
    console.add("label1", new FLabel("hello world!", FRect(10, 2, 5, 7)));

    // Accessing a widget of the ui
    console["rect2"]->initPattern(FPattern::test);
  //console["rect1"]->hide();

    // Accessing directly the char grid
    console[5][2] = 'y';
    console[5][3] = 'a';
    console[5][4] = 'y';
    console.signalModif();

	// Debug
    std::cout << console["label1"]->toString() << std::endl;
    std::cout << console.toString() << std::endl;

	// The app has a state, settable by the user
    return ex.state();
}
