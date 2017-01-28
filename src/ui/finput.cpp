#include "finput.hpp"

namespace fit
{
	FInput::FInput(FString initstr, bool placehold, FWidget* parent, const FRect& rect)
		: FWidget(rect, parent), m_str(initstr), m_placehold(placehold)
	{
		if(height < 2) height = 3;
	    if(width  < 2) width  = 3;
	    m_gridChanged = true;
	}

	FInput::~FInput()
	{

	}

	/*! Internal
	 *
	 *  \todo Newline should go on another line
	*/
	void FInput::refresh_internal()
	{
		FWidget::refresh_internal();

		// Should take into account text alignment
		if(height > 2 && width > 2)
	    {
	        for(fuint16 i= 0; i< m_str.size() && i < width-2; i++)
	        {
	            m_grid[1][1+i] = m_str[i];
	        }
	    }
	}

	FString FInput::getStr() const
	{
		return m_placehold ? "" : m_str;
	}

    void FInput::setStr(const FString& str, const bool placehold)
    {
    	m_str = str;
    	m_placehold = false;
    	signalModif();
    }

    void FInput::putChar(const char c)
    {
       	if(c == 127)
	    {
	    	if(!m_str.empty()) m_str.pop_back();
	    }
	    else
	    {
	    	 if(!m_placehold) m_str += c;
	    	 else
	    	 {
	    	 	m_str = FString(&c, 1);
	    	 	m_placehold = false;
	    	 }
	    }

	    signalModif();
    }

	FString FInput::toString() const
	{
		std::stringstream ret;
		ret << "FLabel {text= \"" << m_str << "\", placehold=" << m_placehold << ", " << FWidget::toString() << "}";

		return ret.str();
	}
}
