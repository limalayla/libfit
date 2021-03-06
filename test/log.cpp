#include "../src/core/flog.hpp"
//#include <libfit/all>

using namespace fit;

int main(int argn, char* argv[])
{
    FLog log(FLog::LogLevel::Warn);

    log.d() << "Debug";
    log.i() << "Info";
    log.w() << "Warning";
    log.e() << "Error: " << 6;
}
