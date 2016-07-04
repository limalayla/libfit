#include "../src/core/ftree.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
    FNode<int> node1(1);
    FNode<int> node2(2);
    FNode<int> node3(node2);
    node1.addChild(node2);
    node1.addChild(node3);
    node1.display();

    std::cout << std::endl << node1[1] << std::endl;
}
