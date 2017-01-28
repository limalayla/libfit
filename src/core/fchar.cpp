#include "fchar.hpp"

namespace fit {

FChar::FChar(char c) : m_char(c) {}
FChar::~FChar(){}

char FChar::get()       { return m_char; }
void FChar::set(char c) { m_char = c;    }

}
