#include "frect.hpp"

namespace fit
{

/*!
 * Base Constructor.
 *
 * \param x: X Coordoante of the rectangle.
 * \param y: Y Coordoante of the rectangle.
 * \param _height: height of the rectangle.
 * \param _width: width of the rectangle.
 */
FRect::FRect(fuint16 x, fuint16 y, fuint16 _height, fuint16 _width)
	: FVec2<fuint16>(x, y), height(_height), width(_width)
{}

/*!
 * Copy Constructor.
 *
 * \param other: FRect to copy.
 */
FRect::FRect(const FRect& other)
	: FVec2<fuint16>(other), height(other.height), width(other.width)
{}

/*!
 * Destructor.
 */
FRect::~FRect()
{}

/*!
 * Override of the FObject's toString function.
 *
 * \return FString containing height and width + FVec2::toString.
 */
FString FRect::toString() const
{
	std::stringstream res;
	res << "FRect {h= " << height << ", w= " << width << ", " << FVec2::toString() << "}";

	return res.str();
}

}
