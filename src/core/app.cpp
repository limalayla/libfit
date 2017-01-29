#include "app.hpp"

namespace fit
{

/*!
 * App Default Constructor, launches the ui and input thread to start the application.
 *
 * \param argn: Number of arguments in command line (1st one is the command name itself)
 * \param argv: Array of strings to those arguments
 */
App::App(const fuint16 argn, char* argv[])
    :	FObject(),
        m_inputHandler(*this), m_stopInputThread(false),
        m_ui(*this), m_stopUIThread(false),
    	m_stopEventThread(false),
        m_state(0), m_argn(argn), m_argv(argv)
{
    setBlockingInput(false);
    m_inputThread = std::thread(&FInputHandler::run, &m_inputHandler, &m_stopInputThread);
    m_UIThread = std::thread(&UI::run, &m_ui, &m_stopUIThread);
    //m_eventThread = std::thread(&App::eventDaemon, this, &m_stopEventThread);
}

/*!
 * Desctructor
 */
App::~App()
{
    if(!m_stopInputThread && m_inputThread.joinable())
	{
		m_stopInputThread = true;
		m_inputThread.join();
	}

    if(!m_stopUIThread && m_UIThread.joinable())
	{
		m_stopUIThread = true;
		m_UIThread.join();
	}
	
    if(!m_stopEventThread && m_eventThread.joinable())
	{
		m_stopEventThread = true;
		m_eventThread.join();
	}

    setBlockingInput(true);
}

/*!
 * Toggles having to hit enter to input data.
 *
 * \param enable: Enable or disable it.
 */
void App::setBlockingInput(bool enable)
{
    struct termios ttystate;

    //get the terminal state
    tcgetattr(0, &ttystate);

    if (enable)
    {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON | ECHO;
    }

    else
    {
        //turn off canonical mode
        ttystate.c_lflag &= ~(ICANON | ECHO);

        //minimum of number input read.
        ttystate.c_cc[VMIN] = 1;
    }

    //set the terminal attributes.
    tcsetattr(0, TCSANOW, &ttystate);
}

/*!
 * Getter to the ui.
 *
 * \return A reference to the ui used by the application to work directly on it.
 */
UI& App::ui() { return m_ui; }

/*!
 * Add an event to a static list
 *
 * \todo Test
 */
void App::addEvent(FEvent::Type typeEvent, FObject& arg)
{
	m_eventMutex.lock();
	m_events.push_back(FEvent(typeEvent, arg));
	
	if(typeEvent == FEvent::keyPressed)
	{
		FChar&  tmp   = static_cast<FChar&>(arg);
		FInput* input = static_cast<FInput*>(m_ui["input1"].get());
		input->putChar(tmp.get());
	}
	else
	{
		m_ui.add("labeldebug", new FLabel("fg", FRect(6, 6, 6, 6)));
	}
	
	m_eventMutex.unlock();
}

void App::registerEvent(FEvent::Type typeEvent, std::function<void(FObject&)> callback)
{
	
}

/*!
 * Remove an event from the static list of events
 *
 * \todo Test
 */
void App::delEvent(fuint32 id)
{
	m_eventMutex.lock();
	m_events.erase(m_events.begin() + id);
	m_eventMutex.unlock();
}

/*!
 * State getter.
 *
 * \return Current application state.
 */
int App::state() const { return m_state; }

/*!
 * State setter.
 *
 * \param state: Value to set.
 */
void App::setState(int state) { m_state = state; }

}
