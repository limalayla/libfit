#ifndef FINPUT_HPP
#define FINPUT_HPP

#include "fwidget.hpp"

namespace fit
{

/*!
 * \brief The FLabel class is a widget to display text
 */
class FInput : public FWidget
{
    public:
        // Constructors - Destructor
        FInput(FString initstr = "", bool placehold = true, FWidget* parent = nullptr, const FRect& rect= FRect(1, 1, 3, 10));
        virtual ~FInput();

        void refresh_internal() override;

        FString getStr() const;
        void    setStr(const FString& str, const bool placehold = false);
        void    putChar(const char c);

        FString toString() const override;

	private:
        FString m_str;
        bool m_placehold;
};

}

#endif // FINPUT_HPP
