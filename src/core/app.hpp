#ifndef APP_COMPILED
#define APP_COMPILED
	
#include <thread>
#include <termios.h>
#include "../ui/ui.hpp"
#include "fevent.hpp"
#include "../ui/finputhandler.hpp"

namespace fit
{
	

class App : public FObject
{
    public:
		// Constructors - Destructor
        App(int argn= 0, char* argv[]= nullptr);
        virtual ~App();
        
        static void addEvent(fuint16 typeEvent, void* arg);
        static void delEvent(fuint32 id);
        static void setBlockingInput(bool enable);
        
        UI& ui();
        int 	state() const;
        void setState(int state);
        
        
	private:
		// Input Handling
		FInputHandler m_inputHandling;
		bool* m_stopInputThread;
		std::thread m_inputThread;
		
		// UI Handling
		UI m_ui;
		bool* m_stopUIThread;
		std::thread m_UIThread;
		
		static std::vector<FEvent> m_events;
		
		int m_state;
		
		// ToDo argn & argv accessors
		int m_argn;
		char** m_argv;
};

}

#endif // APP_COMPILED

