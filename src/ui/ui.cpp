#include "ui.hpp"

namespace fit
{

UI::UI(App& parentApp, fuint16 height, fuint16 width)
	: FWidget(FRect(0, 0, height, width)), m_parentApp(parentApp)
{
	std::cout << "\033[2J";

	using namespace std::placeholders;
	m_parentApp.registerSlot(FEvent::Type::keyPressed, std::bind(&UI::onKeyPressed, this, _1));
	m_gridChanged = true;
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

	// Really useful?
    if(m_widgets.size() >= std::pow(2, 32) - 1)
	{
		//FObject::errstr = __FILE__ + " " + std::to_string(__LINE__) + " "  + __FUNCTION__ + " : maximum number of FWidgets reached for this ui";
        return false;
	}

	widget->setParent(this);
	m_widgets[name] = std::shared_ptr<FWidget>(widget);
	this->signalModif();
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
		this->signalModif();
		return true;
	}

	MACRO_ERRNAMEMAP(name)
	return false;
}

void UI::refresh_internal()
{
	// Big overhead but assured to have good format
	FWidget::refresh_internal();

	//std::vector<std::vector<char> >& widget;

	// For all widgets
    for(auto it= m_widgets.begin(); it!= m_widgets.end(); ++it)
	{
		// If it isn't hid
        if(it->second->isVisible())
        {
	        // Then add its content to the UI
            std::vector<std::vector<char> >& widget = it->second->getCharGrid();

            for(fuint16 i= 0; i< widget.size() && it->second->getx() + i< height-1; i++)
			{
                for(fuint16 j= 0; j< widget[i].size() && it->second->gety() + j< width-1; j++)
				{
                    if(it->second->getx() + i != 0 && j + it->second->gety() != 0)
                        m_grid[it->second->getx() + i][it->second->gety() + j] = widget[i][j];
				}
			}

			// Empty the temporary variable for next loop
			// Useful?
			widget.clear();
		}
	}
}

void UI::display()
{
	if(m_gridChanged) this->refresh();

	std::cout << "\033[1;1H";
	//std::cout << std::endl << std::endl << std::endl;

	for(fuint16 i= 0; i< height; i++)
	{
		for(fuint16 j= 0; j< width; j++)
		{
			putchar(m_grid[i][j]);
		}
		std::cout << std::endl;
    }
}

FString UI::output() const
{
	std::stringstream ret;

	for(fuint32 i= 0; i< m_grid.size(); i++)
		for(fuint32 j= 0; j< m_grid[0].size(); j++)
			ret << m_grid[i][j];

	return ret.str();
}

void UI::onKeyPressed(FObject& arg)
{
	FChar& key = dynamic_cast<FChar&>(arg);

	if(!m_widgets["testInput"])
	{
		this->add("testInput" , new FInput("", false, this, FRect(5, 5, 3, 30)));
	}

	FInput* input = dynamic_cast<FInput*>(m_widgets["testInput"].get());
	input->putChar(key.get());
}

void UI::run(const bool* stop)
{
    while(!*stop)
    {
	    std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(m_gridChanged) display();
    }
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
