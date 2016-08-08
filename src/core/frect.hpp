#ifndef FRECT_COMPILED
#define FRECT_COMPILED

#include "fvec2.hpp"

namespace fit
{

/*!
 * Class holding a composition of 4 points.
 * Inherit FVec2 for the starting point, then the 3 others are obtainable with height and width.
 *
 * \todo Templated?
 */
class FRect : public FVec2<fuint16>
{
    public:
        FRect(fuint16 _x= 0, fuint16 _y= 0, fuint16 _height= 0, fuint16 _width= 0);
        FRect(const FRect& other);
        virtual ~FRect();

        //! Width of the rectangle
        fuint16 height;
        //! Width of the rectangle
        fuint16 width;

        FString toString() const override;
};

}

#endif //FRECT_COMPILED
