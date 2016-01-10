#ifndef FRECT_COMPILED
#define FRECT_COMPILED

#include "fvec2.hpp"

namespace fit
{

// Class to hold a composition of 4 points
class FRect : public FVec2<fuint16>
{
    public:
		// Constructors - Destructor
        FRect(fuint16 _x= 0, fuint16 _y= 0, fuint16 _height= 0, fuint16 _width= 0);
        FRect(const FRect& other);
        virtual ~FRect();

		fuint16 height;
		fuint16 width ;
};

}

#endif //FRECT_COMPILED
