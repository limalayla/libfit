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

        static void setBlockingInput(bool enable);

        //!
        void signal(FEvent::Type typeEvent, FObject& arg);

        //! Bind a function to a specific type of event
        void registerSlot(FEvent::Type typeEvent, std::function<void(FObject&)> callback);

        UI& ui();
        int  state() const;
        void setState(int state);

protected:

	// Event Handling
	    // When an event is received, a matching slot is called, this vector keeps record of those slots.
	    std::vector<std::pair<FEvent::Type, std::function<void(FObject&)>>> m_slots;

	    // Event handling thread.
	    std::thread m_eventThread;

	    // Function ran by the event thread.
	    void eventDaemon();

	    // Event thread control.
	    std::condition_variable m_wakeEventDaemon;
	    std::mutex m_eventMutex;
	    bool m_stopEventThread;

		// Link between the event's emitter thread and the event handling thread.
	    FEvent::Type m_curEventType;
	    FObject*     m_curEventArg;


	// Input Handling
		// Object managing keyboard related events.
		FInputHandler m_inputHandler;

		// Thread checking the inputs alongside the app.
		std::thread m_inputThread;

		// Boolean controlling the thread interuption.
		bool m_stopInputThread;

	// Input Handling
		// UI Object: Holds widget, refresh ui etc. Reffer to the UI doc for further information.
		UI m_ui;

		// Thread running the UI alongside the app.
		std::thread m_UIThread;

		// Boolean controlling the thread interuption.
		bool m_stopUIThread;


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
