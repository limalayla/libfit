#include "../src/core/flinklist.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
    FLinkList<int> ll(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.display();

    ll.add(6, 2);
    ll.display();
    ll.add(7, 0);
    ll.display();

    std::cout << ll[0] << std::endl;
    std::cout << ll[1] << std::endl;
    std::cout << ll[2] << std::endl;
    std::cout << ll[3] << std::endl;
    std::cout << ll[4] << std::endl;
    std::cout << ll[5] << std::endl;
    std::cout << ll[6] << std::endl;
}
