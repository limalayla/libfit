#include "../src/core/app.hpp"
#include "../src/ui/finput.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
    App a(argn, argv);
    UI& ui(a.ui());

    ui.add("input1" , new FInput("Ecrire Ici", true, &ui, FRect(5, 5, 3, 30)));
	std::this_thread::sleep_for(std::chrono::seconds(15));

	return a.state();
}
