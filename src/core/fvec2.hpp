#ifndef FVEC2_COMPILED
#define FVEC2_COMPILED

#include "fobject.hpp"

namespace fit
{
/*!
 *  Class holding a couple of a any value.
 */
MACRO_TEMPLATED
class FVec2 : public FObject
{
    public:
        /*!
         * Base constructor.
		 *
         * \param _x: 1st value of the couple.
         * \param _y: 2nd value of the couple.
		 *
		 * \todo Find a way not to decrement x and y (certainly coming from FWidget)
         */
        FVec2(T _x= 0, T _y= 0)
			: FObject(), x(_x), y(_y)
		{
			if(x != 0) x--;
			if(y != 0) y--;
		}

        /*!
         * Copy constructor.
		 *
         * \param other: Vector to copy.
         */
		FVec2(const FVec2& other)
			: FObject(other), x(other.x), y(other.y)
		{}

        /*!
         * Destructor.
         */
        virtual ~FVec2()
        {

		}

        /*!
         * Override of FObject::toString().
		 *
         * \return FString containing a description of the object.
         */
        FString toString() const override
        {
			std::stringstream res;
			res << "FVec2 {x= " << x << ", y= " << y << ", " << FObject::toString() << "}";

			return res.str();
		}

		//! First value of the couple.
        T x;

		//! Second value of the couple.
        T y;

}; // Class FVec2

} // Namespace fit

#endif //FVEC2_COMPILED
