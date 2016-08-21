#include "../src/core/fstringlist.hpp"
#include "../src/core/flog.hpp"

using namespace fit;

int main(int argn, char* argv[])
{
    FLog log(FLog::LogLevel::Info);

    FStringList strList(argv);
    log.i() << std::endl << strList.debug();

    strList.add("test1", strList.size());
    strList.add("test2", strList.size());
    strList.add("test3", strList.size());
    log.i() << std::endl << strList.debug();

    strList.del(2);
    log.i() << std::endl << strList.debug();


    log.i() << std::endl << strList.get(1, 3).debug();
    log.i() << strList.get(2) << " " << strList[2];

    return 0;
}
