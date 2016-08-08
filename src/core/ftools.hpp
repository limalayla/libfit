#ifndef FTOOLS_HPP
#define FTOOLS_HPP

#include "app.hpp"
#include "fobject.hpp"

namespace fit
{

/*!
 * \brief The FTools class holds a bunch of tools function that are static (so a FTools object is useless)
 */
class FTools : public FObject
{
    public:
        FTools();

        /*!
            \brief Checks if a set of the same type contains the same value
            \param set Vector of whatever (comparable) wich will be tested
            \return true if all the elements are the same, false otherwise
        */
        template<typename T>
        static bool areAllElementsEqual(const std::vector<T>& set)
        {
            if(set.size() < 2) return true;

            for(fuint32 i= 1; i< set.size(); i++)
            {
                if(set[i-1] != set[i])
                    return false;
            }

            return true;
        }

        template<typename keyT, typename valueT>
        static keyT keyByVal(const std::map<keyT, valueT> map_, const valueT& val)
        {
            keyT res;
            std::cout << "Enter (" << val << ")" << std::endl;
            std::cout.clear();

            for(auto it= map_.cbegin(); it != map_.cend(); ++it)
            {
                std::cout << it->first << "\t -- " << it->second << "\t-> ";
                if(it->second == val)
                {
                    std::cout << "Y" << std::endl;
                    res = it->first;
                    break;
                }
                else
                    std::cout << "N" << std::endl;
            }
            std::cout << "Exit (" << res << ")" << std::endl;

            return res;
        }

}; // Class FTools

FString toUpper(const FString& str);
FString trim(const FString& str);

} // Namespace fit

#endif // FTOOLS_HPP
