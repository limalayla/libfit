#include "ui.hpp"

namespace fit
{

UI::UI(fuint16 height, fuint16 width)
	: FWidget(FRect(0, 0, height, width))
{
	
}

UI::~UI()
{
	
}



bool UI::add(const FString& name, FWidget* widget)
{
	if(m_widgets.size() >= std::pow(2, 32) - 1)
	{
		//FObject::errstr = __FILE__ + " " + std::to_string(__LINE__) + " "  + __FUNCTION__ + " : maximum number of FWidgets reached for this ui";
		return false;
	}
	
	m_widgets[name] = std::shared_ptr<FWidget>(widget);
	m_gridChanged = true;
	return true;
}

std::shared_ptr<FWidget> UI::get(const FString& name)
{
	if(m_widgets.find(name) != m_widgets.end()) return m_widgets[name];
	
	MACRO_ERRNAMEMAP(name)
	return std::make_shared<FWidget>();
}

bool UI::del(const FString& name)
{
	
	if(m_widgets.find(name) != m_widgets.end())
	{
		m_widgets.erase(m_widgets.find(name));
		return true;
	}
	
	MACRO_ERRNAMEMAP(name)
	return false;
}

void UI::refresh()
{
	std::vector<std::vector<char> > widget;
	
	for(auto it= m_widgets.begin(); it!= m_widgets.end() ; ++it)
	{
		if(it->second->isVisible())
		{
			widget = it->second->getCharGrid();
			
			for(fuint16 i= 0; i< widget.size() && it->second->getx() + i< height-1; i++)
			{
				for(fuint16 j= 0; j< widget[i].size() && it->second->gety() + j< width-1; j++)
				{
					if(it->second->getx() + i != 0 && j + it->second->gety() != 0)
						m_grid[it->second->getx() + i][it->second->gety() + j] = widget[i][j];
				}
			}
			
			widget.clear();
		}
	}
	
	m_gridChanged = false;
}

void UI::display()
{
	if(m_gridChanged) refresh();
	
	for(fuint16 i= 0; i< height; i++)
	{
		for(fuint16 j= 0; j< width; j++)
		{
			std::cout << m_grid[i][j];
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
}

FString UI::output()
{
	return "";
}

void UI::run(const bool* stop)
{
	while(!stop) display();
}

std::shared_ptr<FWidget> UI::operator[](const FString& name) { return get(name); }

}
