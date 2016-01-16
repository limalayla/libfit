#include "ftextalign.hpp"

namespace fit
{
	
FTextAlign FTextAlign::UpLeft(0);

FTextAlign::FTextAlign(fuint8 value)
	: FObject(), m_value(value)
{}

FTextAlign::~FTextAlign()
{}

}
