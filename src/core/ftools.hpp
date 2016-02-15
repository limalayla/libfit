#ifndef FTOOLS_COMPILED
#define FTOOLS_COMPILED

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

        ///
        /// \brief FTools::areAllElementsEqual checks if a set of the same type contains the same value
        /// \param set is a vector of whatever (comparable) wich will be tested
        /// \return true if all the elements are the same, false otherwise
        ///
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

    protected:

};

}

#endif // FTOOLS_COMPILED
