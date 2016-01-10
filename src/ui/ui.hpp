#ifndef UI_COMPILED
#define UI_COMPILED

#include "fwidget.hpp"
#include "../core/fthreadable.hpp"

namespace fit
{

class UI : public FWidget, public FThreadable
{
    public:
		// Constructors - Destructor
        UI(fuint16 height= 24, fuint16 width= 80);
        virtual ~UI();
        
        // Accessors Widgets
        bool add(const FString& name, FWidget* widget);
        std::shared_ptr<FWidget> get(const FString& name);
        bool del(const FString& name);
        
        // Display Functions
        virtual void refresh();
				void display();
				
        virtual void run(const bool* stop);
        
        FString output();
        
        // Operators Overloading
		std::shared_ptr<FWidget> operator[](const FString& name);
        

    protected:
		std::map<FString, std::shared_ptr<FWidget> > m_widgets;
};

}

#endif //UI_COMPILED