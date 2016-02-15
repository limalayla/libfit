#ifndef FRECT_COMPILED
#define FRECT_COMPILED

#include "fvec2.hpp"

namespace fit
{

/*!
 * \brief The FRect class holds a composition of 4 points
 */
class FRect : public FVec2<fuint16>
{
    public:
		// Constructors - Destructor
        FRect(fuint16 _x= 0, fuint16 _y= 0, fuint16 _height= 0, fuint16 _width= 0);
        FRect(const FRect& other);
        virtual ~FRect();

        fuint16 height; /* Height of the rectangle */
        fuint16 width ; /* Width  of the rectangle */
		
        FString toString() const override;
};

}

#endif //FRECT_COMPILED
