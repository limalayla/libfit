#ifndef APP_HPP
#define APP_HPP

#include <thread>
#include <termios.h>
#include "../ui/ui.hpp"
#include "fevent.hpp"
#include "../ui/finputhandler.hpp"
#include "flog.hpp"
#include "../ui/finput.hpp"
#include "fstringlist.hpp"

namespace fit
{

class FInputHandler;
/*!
 * Class holding all infos and threads for the program to run on.
 */
class App : public FObject
{
    public:
        // Constructors - Destructor
        App(const fuint16 argn= 0, char* argv[]= nullptr);
        virtual ~App();

        void addEvent(FEvent::Type typeEvent, FObject& arg);
        void delEvent(fuint32 id);
        static void setBlockingInput(bool enable);
                    
        //! Bind a function to a specific type of event
        void registerEvent(FEvent::Type typeEvent, std::function<void(FObject&)> callback);

        UI& ui();
        int  state() const;
        void setState(int state);

	private:
        // Input Handling
            //! Object managing keyboard related events.
            FInputHandler m_inputHandler;

            //! Thread checking the inputs alongside the app.
            std::thread m_inputThread;
            
            //! Boolean controlling the thread interuption.
            bool m_stopInputThread;

		// UI Handling
            //! UI Object: Holds widget, refresh ui etc. Reffer to the UI doc for further information.
            UI m_ui;

            //! Thread running the UI alongside the app.
            std::thread m_UIThread;
            
            //! Boolean controlling the thread interuption.
            bool m_stopUIThread;


		// Event Handling
            //! meh.
            std::map<FEvent::Type, std::function<void(FObject&)> >m_registredFunctions;
            
            //! Event Handling Daemon
            void eventDaemon();

            //! Thread running the event daemon alongside the app.
            std::thread m_eventThread;
            
            //! Boolean controlling the thread interuption.
            bool m_stopEventThread;
            

        //! All event of the app.
        std::vector<FEvent> m_events;
        std::mutex m_eventMutex;

        // Links to the os
            //! State of the app (Equivalent to the main's return value).
            int m_state;

            //! Number of arguments of the command line (1st one being the command itself).
            fuint8 m_argn;

            //! Array of strings to those arguments.
            FStringList m_argv;

}; // Class App

} // Namespace fit

#endif // APP_HPP
