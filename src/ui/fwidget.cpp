#include "fwidget.hpp"

namespace fit
{

FWidget::FWidget(const FRect& rect, const FPattern& pattern)
	: FRect(rect), m_visible(true), m_gridChanged(false), m_pattern(pattern)
{
	createGrid();
	initPattern(m_pattern);
}

FWidget::FWidget(const FWidget& other)
	: FRect(other), m_visible(other.m_visible), m_grid(other.m_grid), m_gridChanged(true), m_pattern(other.m_pattern)
{

}

FWidget::~FWidget()
{

}

// Visibility Accessors
void FWidget::setVisible(bool b) { if(m_visible != b) { m_visible = b; signalModif(); } }
void FWidget::hide()			 { setVisible(false); }
void FWidget::unhide()			 { setVisible(true ); }
bool FWidget::isVisible() const	 { return m_visible; }

 // Selectability Accessors
void FWidget::setSelectable(bool b) { if(m_selectable != b) { m_selectable = b; signalModif(); } }
bool FWidget::isSelectable() const  { return m_selectable; }

void FWidget::signalModif() const{} // Should be pure

void FWidget::initPattern(const FPattern& pattern)
{
	fuint16 t(0), l(0), b((height==0) ? height : height-1), r((width==0) ? width : width-1);

	for(fuint16 i= 0; i< height; i++)
	{
		for(fuint16 j= 0; j< width; j++)
		{
				 if(i == t && j == l) m_grid[i][j] = pattern.cornerTL();
			else if(i == t && j == r) m_grid[i][j] = pattern.cornerTR();
			else if(i == b && j == l) m_grid[i][j] = pattern.cornerBL();
			else if(i == b && j == r) m_grid[i][j] = pattern.cornerBR();

			else if(i == t)	m_grid[i][j] = pattern.top();
			else if(i == b)	m_grid[i][j] = pattern.bottom();

			else if(j == l)	m_grid[i][j] = pattern.left();
			else if(j == r)	m_grid[i][j] = pattern.right();
			else m_grid[i][j] = pattern.background();
		}
	}
}

void FWidget::createGrid()
{
	m_grid.reserve(height);

	for(fuint16 i= 0; i< height; i++)
	{
		m_grid.push_back(std::vector<char>());
		m_grid[i].reserve(width);

		for(fuint16 j= 0; j< width; j++)
		{
			m_grid[i].push_back('*');
		}
	}
}

void FWidget::refresh()
{
	m_grid.clear();
	createGrid();
	initPattern(m_pattern);
	m_gridChanged = false;
}

std::vector<std::vector<char> >& FWidget::getCharGrid()
{
	if(m_gridChanged) refresh();
	return m_grid;
}

fuint16 FWidget::getx() const { return x+1; }
fuint16 FWidget::gety() const { return y+1; }
fuint16 FWidget::geth() const { return height; }
fuint16 FWidget::getw() const { return width;  }

void FWidget::setx(fuint16 x) { if(x-1 != this->x) m_gridChanged = true; this->x = x-1; }
void FWidget::sety(fuint16 y) { if(y-1 != this->y) m_gridChanged = true; this->y = y-1; }
void FWidget::seth(fuint16 height) { if(height != this->height) m_gridChanged = true; this->height = height; }
void FWidget::setw(fuint16 width ) { if(width  != this->width ) m_gridChanged = true; this->width  = width ; }

FString FWidget::toString() const
{
	std::stringstream res;
	res << "FWidget {" << FRect::toString() << "}";

	return res.str();
}

}
