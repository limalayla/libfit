#ifndef FWIDGET_COMPILED
#define FWIDGET_COMPILED

#include "../core/frect.hpp"
#include "fpattern.hpp"

namespace fit
{

// Base class for all displayables objects
class FWidget : public FRect
{
    public:
		// Constructors - Destructor
			FWidget(const FRect& rect = FRect(0, 0, 0, 0), FPattern& pattern= FWidget::defaultPattern);
			FWidget(const FWidget& other);
			virtual ~FWidget();
        
        // Visibility Accessors
			bool isVisible() const;
			void setVisible(bool b);
			void hide();
			void unhide();
        
        // Selectability Accessors
			bool isSelectable() const;
			void setSelectable(bool b);
		
		// Rebuild the internal grid according to its content
			virtual void refresh();
		
		// Returns a copy of the updated internal grid (useful while displaying)
			std::vector<std::vector<char> > getCharGrid();
			
		// Signal that a modification has occured
			void signalModif() const; // Should be pure, but not right now for debug purpose
		
		
		void initPattern(const FPattern& pattern);

		// Static definition
			static FPattern noPattern;
			static FPattern testPattern;
			static FPattern defaultPattern;
		
		// Parents accessors
			virtual fuint16 getx() const;
			virtual fuint16 gety() const;
			virtual fuint16 geth() const;
			virtual fuint16 getw() const;
			
			virtual void 	setx(fuint16 x);
			virtual void 	sety(fuint16 y);
			virtual void 	seth(fuint16 height);
			virtual void 	setw(fuint16 width );

    protected:
    
		// Redefining the parents (frect and fvec2)'s members as protected
			using FVec2::x;
			using FVec2::y;
			using FRect::height;
			using FRect::width;
			
   		bool m_visible;
		std::vector<std::vector<char> > m_grid;
		bool m_gridChanged;
		bool m_selectable;
		
		FString m_text;
		FPattern& m_pattern;
		
		virtual void createGrid();
};

}

#endif //FWIDGET_COMPILED
