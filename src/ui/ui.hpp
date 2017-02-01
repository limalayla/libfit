#ifndef UI_COMPILED
#define UI_COMPILED

#include "flabel.hpp"
#include "../core/fthreadable.hpp"

namespace fit
{

class App;

class UI : public FWidget, public FThreadable
{
    public:
		// Constructors - Destructor
        UI(App& parentApp, fuint16 height= 24, fuint16 width= 80);
        virtual ~UI();

        // Accessors Widgets
        bool add(const FString& name, FWidget* widget);
        std::shared_ptr<FWidget> get(const FString& name);
        bool del(const FString& name);

        // Display Functions
        void refresh_internal() override;
        void display();

        void run(const bool* stop) override;

        FString output() const;

        void clear();

        // Operators Overloading
		std::shared_ptr<FWidget> operator[](const FString& name);
		std::vector<char>& operator[](fuint16 index);

        virtual FString toString() const override;

    protected:
		std::map<FString, std::shared_ptr<FWidget> > m_widgets;
		App& m_parentApp;

		void onKeyPressed(FObject& arg);


	#ifdef DEBUG
		private: void d_dispWidgets() const;
	#endif
};

}

#include "../core/app.hpp"

#endif //UI_COMPILED
