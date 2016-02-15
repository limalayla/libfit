#ifndef FMATRIX_COMPILED
#define FMATRIX_COMPILED

#include "fobject.hpp"

#define MACRO_WRONGMATSIZE(a, b) throw std::logic_error("Wrong matrix size for a matrix product (" + to_string(a) + " != " + to_string(b) + ") at line " + to_string(__LINE__) + " in " + __FILE__);
#define MACRO_EMPTYMAT			 throw std::logic_error("Empty Matrix at line " + to_string(__LINE__) + " in " + __FILE__);

namespace fit
{

MACRO_TEMPLATED
class FMatrix : public FObject
{
    public:
		// Constructors - Destructor
			FMatrix(fuint16 height= 0, fuint16 width= 0);
			FMatrix(const FMatrix<T>& other);
			virtual ~FMatrix();
			
			std::vector<T>& operator[](fuint16 index);
			
			fuint16 height() const;
			fuint16 width () const;
			
			void dispDebug() const;
			void init(const T& val);
			
			explicit operator bool() const;
			bool operator!() const;
			
			FMatrix<T>& operator=(const FMatrix<T>& other);
			
			FMatrix<T>& operator+=(const FMatrix&);
			FMatrix<T>& operator-=(const FMatrix&);
			FMatrix<T>& operator*=(const FMatrix&);
			FMatrix<T>& operator*=(double coef);
			FMatrix<T>& operator/=(double coef);
			
	private:
        std::vector<std::vector<T> > m_mat; /* 2D Array of any given type */
};

MACRO_TEMPLATED FMatrix<T> operator+(const FMatrix<T>& a, const FMatrix<T>& b);
MACRO_TEMPLATED FMatrix<T> operator-(const FMatrix<T>& a, const FMatrix<T>& b);
MACRO_TEMPLATED FMatrix<T> operator*(const FMatrix<T>& a, const FMatrix<T>& b);
MACRO_TEMPLATED FMatrix<T> operator*(const FMatrix<T>& a, double coef);
MACRO_TEMPLATED FMatrix<T> operator/(const FMatrix<T>& a, double coef);

typedef FMatrix<double> FDMat;

}

#include "fmatrix_impl.cpp"

#endif // FMATRIX_COMPILED
