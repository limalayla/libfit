#include "headers/Core"
#include "headers/UI"

using namespace fit;

int main(int argn, char* argv[])
{
#if 0
	// Create the app
    App ex(argn, argv);

	// Extract the ui, to perform action on it directly
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

    // Temporary workaround just to see a ui displayed
    // (The ui is supposed to update and display itself on its own)
	console.display();

	// Debug
    std::cout << console["label1"]->toString() << std::endl;
    std::cout << console.toString() << std::endl;

	// The app has a state, which can be set at anytime by the user
	std::cout << ex.state() << std::endl;

    return ex.state();
    }
#endif

    FNode<int> node1(1);
    FNode<int> node2(2);
    FNode<int> node3(node2);
    node1.addChild(node2);
    node1.addChild(node3);
    node1.display();

    std::cout << std::endl << node1[1] << std::endl;
}
