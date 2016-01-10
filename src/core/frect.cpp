#include "frect.hpp"

namespace fit
{

FRect::FRect(fuint16 x, fuint16 y, fuint16 _height, fuint16 _width)
	: FVec2<fuint16>(x, y), height(_height), width(_width)
{}

FRect::FRect(const FRect& other)
	: FVec2<fuint16>(other), height(other.height), width(other.width)
{}

FRect::~FRect()
{}

}
