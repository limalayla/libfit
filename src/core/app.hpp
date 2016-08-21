#ifndef APP_HPP
#define APP_HPP

#include <thread>
#include <termios.h>
#include "../ui/ui.hpp"
#include "fevent.hpp"
#include "../ui/finputhandler.hpp"
#include "flog.hpp"
#include "fstringlist.hpp"

namespace fit
{

/*!
 * Class holding all infos and threads for the program to run on.
 */
class App : public FObject
{
    public:

        /*!
         * Enum used to implement easter eggs easily.
         */
        enum class EasterEgg
        {
            AmericanFlag
        };

        // Constructors - Destructor
        App(const fuint16 argn= 0, char* argv[]= nullptr);
        App(const EasterEgg& eEgg);
        virtual ~App();

        static void addEvent(fuint16 typeEvent, void* arg);
        static void delEvent(fuint32 id);
        static void setBlockingInput(bool enable);

        UI& ui();
        int  state() const;
        void setState(int state);

	private:
        // Input Handling
            //! Object meant to manage events related to input (keyboard etc). Reffer to the FInputHandler doc for further information.
            FInputHandler m_inputHandling;

            //! Boolean controlling the thread interuption.
            bool* m_stopInputThread;

            //! Thread checking the inputs alongside the app.
            std::thread m_inputThread;

		// UI Handling
            //! UI Object: Holds widget, refresh ui etc. Reffer to the UI doc for further information.
            UI m_ui;

            //! Boolean controlling the thread interuption.
            bool* m_stopUIThread;

            //! Thread running the UI alongside the app.
            std::thread m_UIThread;

        //! All event of the app.
        static std::map<FString, FEvent> m_events;

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
