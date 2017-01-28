#ifndef FLABEL_HPP
#define FLABEL_HPP

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
        FLabel(FString msg, const FRect& rect= FRect(1, 1, 3, 0), FWidget* parent = nullptr, const FTextAlign& textAlign = FTextAlign::UpLeft);
        virtual ~FLabel();

        void refresh_internal() override;

        FString toString() const override;

	protected:
        FString m_str;      /* String held and displayed by the label  */
        FTextAlign m_ta;    /* Text alignement for the text to display */
};

}

#endif // FLABEL_HPP
