#ifndef FTEXTALIGN_COMPILED
#define FTEXTALIGN_COMPILED

#include "../core/fobject.hpp"

namespace fit
{

class FTextAlign : public FObject
{
    public:
		// Constructors - Destructor
			FTextAlign(fuint8 value);
			virtual ~FTextAlign();
			
			static FTextAlign UpLeft;
	
	private:
		fuint8 m_value;
};

}

#endif // FTEXTALIGN_COMPILED
