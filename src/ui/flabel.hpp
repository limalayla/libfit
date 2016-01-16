#ifndef FLABEL_COMPILED
#define FLABEL_COMPILED

#include "fwidget.hpp"
#include "ftextalign.hpp"

namespace fit
{

class FLabel : public FWidget
{
    public:
		// Constructors - Destructor
			FLabel(FString msg, const FRect& rect= FRect(1, 1, 3, 0), const FTextAlign& textAlign = FTextAlign::UpLeft);
			virtual ~FLabel();
        
        // Rebuild the internal grid according to its content
			virtual void refresh() override;
		
		// Returns a copy of the updated internal grid (useful while displaying)
			virtual std::vector<std::vector<char> >& getCharGrid() override;
	
	private:
		FString m_str;
		FTextAlign m_ta;
};

}

#endif // FLABEL_COMPILED
