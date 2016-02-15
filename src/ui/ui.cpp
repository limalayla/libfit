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


///
/// \brief UI::add adds a new widget to the ui, mapping it with a name
/// \param name is the widget identifier
/// \param widget is a widget object
/// \return true if successful, false otherwise
///
bool UI::add(const FString& name, FWidget* widget)
{
    if(widget == nullptr)
    {
        // Error
        return false;
    }

    if(m_widgets.size() >= std::pow(2, 32) - 1)
	{
		//FObject::errstr = __FILE__ + " " + std::to_string(__LINE__) + " "  + __FUNCTION__ + " : maximum number of FWidgets reached for this ui";
        return false;
	}
	
	m_widgets[name] = std::shared_ptr<FWidget>(widget);
	m_gridChanged = true;
    return true;
}

///
/// \brief UI::get gets a widget object of the ui, matching the name passed
/// \param name is the name of the object wanted
/// \return a pointer to the widget matching the name
/// \exception throws a std::logic_error if no widget matches the name
///
std::shared_ptr<FWidget> UI::get(const FString& name)
{
	if(m_widgets.find(name) != m_widgets.end()) return m_widgets[name];
	
	MACRO_ERRNAMEMAP(name)
    return std::shared_ptr<FWidget>(new FWidget());
}

///
/// \brief UI::del deletes a widget object of the ui
/// \param name is the name of the object meant to be deleted
/// \return true if successful, false otherwise
///
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

FString UI::output() const
{
	return "";
}

void UI::run(const bool* stop)
{
	while(!stop) display();
}

std::shared_ptr<FWidget> UI::operator[](const FString& name) { return get(name); }
std::vector<char>& 		 UI::operator[](fuint16 index) { return m_grid[index]; }

FString UI::toString() const
{
	std::stringstream res;
	res << "UI {nbWidgets= " << m_widgets.size() << ", " << FRect::toString() << "}";
	
	return res.str();
}

void UI::clear() 
{
	m_widgets.clear();
	m_gridChanged = true;
}

#ifdef DEBUG
	void UI::d_dispWidgets() const
	{
		for(auto i= m_widgets.cbegin(); i != m_widgets.cend(); i++)
            std::cout << i->first << " : " << i->second->toString() << std::endl;
	}
#endif

}
