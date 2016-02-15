#include "frect.hpp"

namespace fit
{

/*!
 * \brief FRect::FRect Constructor
 * \param x
 * \param y
 * \param _height
 * \param _width
 */
FRect::FRect(fuint16 x, fuint16 y, fuint16 _height, fuint16 _width)
	: FVec2<fuint16>(x, y), height(_height), width(_width)
{}

/*!
 * \brief FRect::FRect
 * \param other
 */
FRect::FRect(const FRect& other)
	: FVec2<fuint16>(other), height(other.height), width(other.width)
{}

/*!
 * \brief FRect::~FRect
 */
FRect::~FRect()
{}

/*!
 * \brief FRect::toString
 * \return
 */
FString FRect::toString() const
{
	std::stringstream res;
	res << "FRect {h= " << height << ", w= " << width << ", " << FVec2::toString() << "}";
	
	return res.str();
}

}
