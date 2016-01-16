#include "flabel.hpp"

namespace fit
{
	
FLabel::FLabel(FString msg, const FRect& rect, const FTextAlign& textAlignement)
	: FWidget(rect, FPattern::none), m_str(msg), m_ta(textAlignement)
{
	if(width == 0) width = m_str.size() + 2;
}

FLabel::~FLabel()
{}

void FLabel::refresh()
{
	std::cout << "moui" << std::endl;
	FWidget::refresh();
	// Display String according to the alignement
	
	/* Temporary  */
		
		for(fuint16 i= 0; i< m_str.size() && i < width-2; i++) m_grid[1][1 + i] = m_str[i];
		
	/* /Temporary */
}

std::vector<std::vector<char> >& FLabel::getCharGrid()
{
	if(m_gridChanged) refresh();
	return m_grid;
}

}
