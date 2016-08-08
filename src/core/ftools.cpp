#include "ftools.hpp"

namespace fit
{

/*!
 * \brief FTools::FTools Default constructor (quite useless)
 */
FTools::FTools()
    : FObject()
{

}

FString toUpper(const FString& str)
{
    FString res(str);

    for(fuint32 i= 0; i< str.size(); i++)
        if(std::isalpha(str[i]))
            res[i] = std::toupper(str[i]);

     App::log.d() << str << " " << res;

    return res;
}

FString trim(const FString& str)
{
    FString res(str);

    size_t first = res.find_first_not_of(' ');
    size_t last = res.find_last_not_of(' ');

    App::log.d()  << str << " " << res;
    return res.substr(first, (last-first+1));
}

} // namespace fit
