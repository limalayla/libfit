#include "headers/Core"
#include "headers/UI"

using namespace fit;

int main(int argn, char* argv[])
{
	// Create the app
	App ex(argn, argv);
	
	// Extract the ui, to perform action on it directly
    UI& console = ex.ui();
    
    // Adding widgets
    console.add("rect1" , new FWidget(FRect(0, 0, 3, 10)));
    console.add("rect2" , new FWidget(FRect(0, 50, 10, 50)));
    console.add("label1", new FLabel("hello world!", FRect(20, 20, 20, 20)));
    
    // Accessing a widget of the ui
    console["rect2"]->initPattern(FPattern::test);
    //console["rect1"]->hide();
    
    // Accessing directly the char grid
    console[5][2] = 'y';
    console[5][3] = 'a';
    console[5][4] = 'y';
    
    // Temporary workaround just to see a ui displayed
    // (The ui is supposed to update and display itself on its own)
//	console.display();

	// Debug
//	std::cout << console["label1"]->toString() << std::endl;

	// The app has a state, which can be set at anytime by the user
//	std::cout << ex.state() << std::endl;

	FDMat mat1(5, 5);
	mat1.init(2);
	
	FDMat mat2(5, 5);
	mat2.init(20);
	
	mat2[1][3] = 9;
	
	FDMat mat3(mat1 * mat2);
	
	(mat3).dispDebug();
    return ex.state();
}
