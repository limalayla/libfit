#ifndef FPATTERN_COMPILED
#define FPATTERN_COMPILED

#include "../core/fobject.hpp"

namespace fit
{

// Class used to describe the look of a widget
// No deep copy
// Constructed once, never modified
class FPattern : public FObject
{
    public:
		// Constructors - Destructor
			FPattern(char background, char vertical, char horizontal, char corner);
			FPattern(char background, char top, char bottom, char left, char right, char cornerTL, char cornerTR, char cornerBL, char cornerBR);
			virtual ~FPattern();
        
        // Disallow deep copy
			FPattern(const FPattern&) = delete;
			FPattern(const FPattern*) = delete;
			FPattern& operator=(const FPattern&) = delete;
		
        // Static definition
			static FPattern none;
			static FPattern test;
			static FPattern defaultPattern;
        
        // Members accessors
			char background() const;
			
			char top() const;
			char bottom() const;
			
			char left() const;
			char right() const;
			
			char cornerTL() const;
			char cornerTR() const;
			char cornerBL() const;
			char cornerBR() const;
        
	private:
		char m_background;

		char m_top;
		char m_bottom;
		
		char m_left;
		char m_right;
		
		char m_cornerTL;
		char m_cornerTR;
		char m_cornerBL;
		char m_cornerBR;
};

}

#endif // FPATTERN_COMPILED

