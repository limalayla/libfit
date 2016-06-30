#ifndef APP_COMPILED
#define APP_COMPILED
	
#include <thread>
#include <termios.h>
#include "../ui/ui.hpp"
#include "fevent.hpp"
#include "../ui/finputhandler.hpp"

namespace fit
{
	
/*!
 * \brief The App class holds all infos and threads for the program to run on
 *        Meant to be always accessible
 */
class App : public FObject
{
    public:

        /*!
         * \brief The EasterEgg enum is used to implement easter eggs easily
         */
        enum class EasterEgg
        {
            AmericanFlag
        };

        // Constructors - Destructor
        App(int argn= 0, char* argv[]= nullptr);
        App(const EasterEgg& ee);
        virtual ~App();
        
        static void addEvent(fuint16 typeEvent, void* arg);
        static void delEvent(fuint32 id);
        static void setBlockingInput(bool enable);
        
        UI& ui();
        int  state() const;
        void setState(int state);

	private:
        // Input Handling
        FInputHandler m_inputHandling;              /* Object meant to create and manage events related to all inputs (keyboard etc) */
        bool*         m_stopInputThread;            /* Boolean shared with the thread, stopping it when needed */
        std::thread   m_inputThread;                /* Thread meant to run along with the app, checking all inputs (keyboard etc) */
		
		// UI Handling
        UI            m_ui;                         /* Object managing the ui: contains it, refresh it, holds the widgets */
        bool*         m_stopUIThread;               /* Boolean shared with the thread, stopping it when needed */
        std::thread   m_UIThread;                   /* Thread meant to run along with the app, updating the ui when needed */
		
        static std::map<FString, FEvent> m_events;  /* All event of the app */
		
        // Links to the os
        int           m_state;                      /* State of the app, meant to be returned at the end of the program */
        int           m_argn;                       /* Number of arguments in command line (1st one is the command name itself) */
        char**        m_argv;                       /* Array of strings to those arguments */
};

}

#endif // APP_COMPILED

