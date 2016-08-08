#include "../src/core/fmatrix.hpp"
#include "../src/core/flog.hpp"

using namespace fit;

int main(int argn, char* argv[])
{
    FLog log(FLog::LogLevel::Info, std::cout);
    FMatrix<double> mat(5, 3, 1.2);

    log.i() << mat.debug() << "height: " << mat.nrow() << " -- width: " << mat.ncol();
    mat[2][3] = 0;
    log.i() << mat.debug();
}
