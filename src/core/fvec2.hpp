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

// Class to hold a couple of a certain value
template<typename T>
class FVec2 : public FObject
{
    public:
		// Constructors - Destructor
        FVec2(T _x= 0, T _y= 0)
			: FObject(), x(_x), y(_y)
		{
			if(x != 0) x--;
			if(y != 0) y--;
		}
		
		FVec2(const FVec2& other)
			: FObject(other), x(other.x), y(other.y)
		{}
		
        virtual ~FVec2()
        {}

		T x;
		T y;
};

}

#endif //FVEC2_COMPILED
