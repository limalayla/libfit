#include "../src/core/app.hpp"
#include "../src/ui/fwidget.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
    App ex(argn, argv);
    UI& console = ex.ui();

	console.add("stars", new FWidget(FRect( 1,  1, 10, 30), &console, FPattern::test));
	console.add("band1", new FWidget(FRect( 1, 30,  2, 50), &console, FPattern::band));
	console.add("band2", new FWidget(FRect( 5, 30,  2, 50), &console, FPattern::band));
	console.add("band3", new FWidget(FRect( 9, 30,  2, 50), &console, FPattern::band));
	console.add("band4", new FWidget(FRect(13,  1,  2, 80), &console, FPattern::band));
	console.add("band5", new FWidget(FRect(17,  1,  2, 80), &console, FPattern::band));
	console.add("band6", new FWidget(FRect(21,  1,  2, 80), &console, FPattern::band));

    return ex.state();
}
