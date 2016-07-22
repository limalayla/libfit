#include "fpattern.hpp"

namespace fit
{

const FPattern FPattern::none				(' ', ' ', ' ', ' ');
const FPattern FPattern::test				('*', '*', '*', '*');
const FPattern FPattern::defaultPattern		(' ', '|', '-', '+');
const FPattern FPattern::band				('/', '/', '/', '/');

/*!
 * \brief FPattern::FPattern 1st constructor (light)
 */
FPattern::FPattern(char background, char vertical, char horizontal, char corner)
	: FObject(),
	  m_background(background),
	  m_top(horizontal),    m_bottom(horizontal),
	  m_left(vertical), m_right(vertical),
	  m_cornerTL(corner), m_cornerTR(corner), m_cornerBL(corner), m_cornerBR(corner)
{}

/*!
 * \brief FPattern::FPattern 2nd constructor (complete)
 */
FPattern::FPattern(char background, char top, char bottom, char left, char right, char cornerTL, char cornerTR, char cornerBL, char cornerBR)
	: FObject(),
	  m_background(background),
	  m_top(top),    m_bottom(bottom),
	  m_left(left), m_right(right),
	  m_cornerTL(cornerTL), m_cornerTR(cornerTR), m_cornerBL(cornerBL), m_cornerBR(cornerBR)
{}

/*!
 * \brief FPattern::~FPattern Destructor
 */
FPattern::~FPattern()
{}

char FPattern::background()	const { return m_background; }

char FPattern::top()		const { return m_top; }
char FPattern::bottom()		const { return m_bottom; }

char FPattern::left()		const { return m_left; }
char FPattern::right()		const { return m_right; }

char FPattern::cornerTL()	const { return m_cornerTL; }
char FPattern::cornerTR()	const { return m_cornerTR; }
char FPattern::cornerBL()	const { return m_cornerBL; }
char FPattern::cornerBR()	const { return m_cornerBR; }

/*!
 * \brief FPattern::iSolid checks if the pattern will look like one solid piece
 * \return true if all char composing the pattern are the same, false otherwise
 */
bool FPattern::iSolid()	const
{
    return FTools::areAllElementsEqual<char>({
                                                 m_background,
                                                 m_top, m_bottom, m_left, m_right,
                                                 m_cornerTL, m_cornerTR, m_cornerBL, m_cornerBR
                                             });
}

}
