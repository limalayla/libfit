#ifndef FLABEL_COMPILED
#define FLABEL_COMPILED

#include "fwidget.hpp"
#include "ftextalign.hpp"

namespace fit
{

/*!
 * \brief The FLabel class is a widget to display text
 */
class FLabel : public FWidget
{
    public:
        // Constructors - Destructor
        FLabel(FString msg, const FRect& rect= FRect(1, 1, 3, 0), const FTextAlign& textAlign = FTextAlign::UpLeft);
        virtual ~FLabel();
        
        void refresh() override;

        FString toString() const override;
	
	private:
        FString m_str;      /* String held and displayed by the label  */
        FTextAlign m_ta;    /* Text alignement for the text to display */
};

}

#endif // FLABEL_COMPILED
