#include "app.hpp"

namespace fit
{

/*!
 * App Default Constructor, launches the ui and input thread to start the application
 * \param Number of arguments in command line (1st one is the command name itself)
 * \param Array of strings to those arguments
 */
App::App(int argn, char* argv[])
    :	FObject(),
        m_inputHandling(), m_stopInputThread(new bool(false)),
        m_ui(), m_stopUIThread(new bool(false)),
        m_state(0),
        m_argn(argn), m_argv(argv)
{
    setBlockingInput(false);
    //m_inputThread = std::thread(m_inputHandling.run, m_stopInputThread);
    //m_UIThread = std::thread(m_ui.run, m_stopUIThread);
}

/*!
 * App Special Constructor
 * \param Identifier of the easter egg
 */
App::App(const EasterEgg& eEgg)
    :	App()
{
    if(eEgg == EasterEgg::AmericanFlag)
    {
        m_ui.add("stars", new FWidget(FRect( 1,  1, 10, 30), FPattern::test));
        m_ui.add("band1", new FWidget(FRect( 1, 30,  2, 50), FPattern::band));
        m_ui.add("band2", new FWidget(FRect( 5, 30,  2, 50), FPattern::band));
        m_ui.add("band3", new FWidget(FRect( 9, 30,  2, 50), FPattern::band));
        m_ui.add("band4", new FWidget(FRect(13,  1,  2, 80), FPattern::band));
        m_ui.add("band5", new FWidget(FRect(17,  1,  2, 80), FPattern::band));
        m_ui.add("band6", new FWidget(FRect(21,  1,  2, 80), FPattern::band));
    }
}

/*!
 * \brief Desctructor
 */
App::~App()
{
    setBlockingInput(true);

    if(m_stopInputThread != nullptr && !m_stopInputThread && m_inputThread.joinable())
	{
		*m_stopInputThread = true;
		m_inputThread.join();
	}

    if(m_stopUIThread != nullptr && !m_stopUIThread && m_UIThread.joinable())
	{
		*m_stopUIThread = true;
		m_UIThread.join();
	}

    if(m_stopInputThread != nullptr) delete m_stopInputThread;
    if(m_stopUIThread != nullptr)    delete m_stopUIThread;
}

/*!
 * Toggles having to hit enter to input data
 * \param Enable or disable it
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
 * Getter to the ui
 * \return A reference to the ui used by the application to work directly on it
 */
UI& App::ui() { return m_ui; }

/*!
 * \todo
 */
void App::addEvent(fuint16 typeEvent, void* arg)
{
	//App::m_events.push_back(FEvent(typeEvent, arg));
}

/*!
 * \todo
 */
void App::delEvent(fuint32 id)
{
	//App::m_events.erase(m_events.begin() + id);
}

/*!
 * State getter
 * \return Current application state
 */
int App::state() const { return m_state; }

/*!
 * State setter
 * \param Value to set
 */
void App::setState(int state) { m_state = state; }

}
