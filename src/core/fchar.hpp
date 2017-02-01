#ifndef FCHAR_HPP
#define FCHAR_HPP

#include "fobject.hpp"

namespace fit
{

/*!
 * Char Wrapper
 */
class FChar : public FObject
{
public:
// Constructors - Destructor
	FChar(char c = '\0');
	virtual ~FChar();

	char get();
	void set(char c);

	FString toString() const override;

private:
	char m_char;

}; // Class FChar

} // Namespace fit

#endif // FCHAR_HPP
