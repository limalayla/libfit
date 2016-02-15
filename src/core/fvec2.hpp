#ifndef FVEC2_COMPILED
#define FVEC2_COMPILED

#include "fobject.hpp"

namespace fit
{
	
	/*
	 *	Disclaimer: Implementation in .h (or .hpp) is dirty,
	 *  but is apparently the "best" way to do it. Meh. 
	 * 
	*/

/*!
 *  FVec2 is a class holding a couple of a certain value
 */
MACRO_TEMPLATED
class FVec2 : public FObject
{
    public:
		// Constructors - Destructor
        /*!
         * \brief FVec2 Default constructor
         * \param _x: 1st value of the couple
         * \param _y: 2nd value of the couple
         */
        FVec2(T _x= 0, T _y= 0)
			: FObject(), x(_x), y(_y)
		{
			if(x != 0) x--;
			if(y != 0) y--;
		}
		
        /*!
         * \brief FVec2 Deep copy constructor
         * \param other: Vector to copy
         */
		FVec2(const FVec2& other)
			: FObject(other), x(other.x), y(other.y)
		{}
		
        /*!
         * \brief ~FVec2 Destructor
         */
        virtual ~FVec2()
        {}
        
        /*!
         * \brief toString Overriding of FObject::toString()
         * \return FString containing a description of the object
         */
        FString toString() const override
        {
			std::stringstream res;
			res << "FVec2 {x= " << x << ", y= " << y << ", " << FObject::toString() << "}";
			
			return res.str();
		}

        T x;    /* 1st value of the couple */
        T y;    /* 2nd value of the couple */
};

}

#endif //FVEC2_COMPILED
