#include "flabel.hpp"

namespace fit
{

/*!
 * \brief FLabel::FLabel
 * \param msg
 * \param rect
 * \param textAlignement
 */
FLabel::FLabel(FString msg, const FRect& rect, const FTextAlign& textAlignement)
    : FWidget(rect, FPattern::none), m_str(msg), m_ta(textAlignement)
{
    if(height == 0) height = 1;
    if(width  == 0) width  = m_str.size();
    m_gridChanged = true;
}

/*!
 * \brief FLabel::~FLabel
 */
FLabel::~FLabel()
{}

/*!
 * \brief FLabel::refresh Rebuilds the internal grid according to its content
 */
void FLabel::refresh()
{
	FWidget::refresh();
	// Display String according to the alignement
	
	/* Temporary  */

        if(height != 0 && width != 0)
        {
            for(fuint16 i= 0; i< m_str.size() && i < width; i++)
            {
                m_grid[0][i] = m_str[i];
            }
        }
		
	/* /Temporary */
}

FString FLabel::toString() const
{
	std::stringstream res;
	res << "FLabel {text= \"" << m_str << "\", " << FWidget::toString() << "}";
	
	return res.str();
}

}
