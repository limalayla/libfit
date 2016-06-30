#ifndef FTEXTALIGN_COMPILED
#define FTEXTALIGN_COMPILED

#include "../core/fobject.hpp"

namespace fit
{

/*!
 * \brief The FTextAlign class is used to
 */
class FTextAlign : public FObject
{
    public:
		// Constructors - Destructor
			FTextAlign(fuint8 value);
			virtual ~FTextAlign();
			
			static FTextAlign UpLeft;
	
	private:
        fuint8 m_value; /* Due to the small number of alignement possibilities, these are stocked in a single 8 bit integer */
};

}

#endif // FTEXTALIGN_COMPILED
