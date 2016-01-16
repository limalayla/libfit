#include "app.hpp"

namespace fit
{

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

App::~App()
{
	if(m_stopInputThread != NULL && !m_stopInputThread && m_inputThread.joinable())
	{
		*m_stopInputThread = true;
		m_inputThread.join();
	}
	
	if(m_stopUIThread != NULL && !m_stopUIThread && m_UIThread.joinable())
	{
		*m_stopUIThread = true;
		m_UIThread.join();
	}
	
	if(m_stopInputThread != NULL) delete m_stopInputThread;
	if(m_stopUIThread != NULL)    delete m_stopUIThread;
	
	setBlockingInput(true);
}

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

UI& App::ui() { return m_ui; }

void App::addEvent(fuint16 typeEvent, void* arg)
{
	//App::m_events.push_back(FEvent(typeEvent, arg));
}

void App::delEvent(fuint32 id)
{
	//App::m_events.erase(m_events.begin() + id);
}

int  App::state()          const { return m_state; }
void App::setState(int state)    { m_state = state; }

}
