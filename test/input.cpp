#include "../src/core/app.hpp"
#include "../src/ui/finput.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
    App a(argn, argv);
	std::this_thread::sleep_for(std::chrono::seconds(20));

	return a.state();
}
