#ifndef FWIDGET_HPP
#define FWIDGET_HPP

#include "../core/frect.hpp"
#include "fpattern.hpp"

namespace fit
{

// Base class for all displayables objects
class FWidget : public FRect
{
    public:
		// Constructors - Destructor
			FWidget(const FRect& rect = FRect(0, 0, 0, 0), FWidget* parent = nullptr, const FPattern& pattern= FPattern::defaultPattern);
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
			void refresh();
			bool isChanged();

		// Returns a copy of the updated internal grid (useful while displaying)
			virtual std::vector<std::vector<char> >& getCharGrid();

		// Signal that a modification has occured
			virtual void signalModif();

		void setParent(FWidget* parent);


		void initPattern(const FPattern& pattern);

		// Parents accessors
            virtual fuint16 getx() const;
			virtual fuint16 gety() const;
			virtual fuint16 geth() const;
			virtual fuint16 getw() const;

			virtual void 	setx(fuint16 x);
			virtual void 	sety(fuint16 y);
			virtual void 	seth(fuint16 height);
			virtual void 	setw(fuint16 width );

			FString toString() const override;

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
		FWidget* m_parent;

		FString m_text;
		const FPattern& m_pattern;

		virtual void createGrid();
		virtual void refresh_internal();

}; // CLass FWidget

} // Namespace fit

#endif //FWIDGET_HPP
