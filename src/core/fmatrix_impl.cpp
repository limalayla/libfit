#include "fobject.hpp"

namespace fit
{

/*!
 * \brief FMatrix<T>::FMatrix
 * \param col: number of columns of the matrix (default: 0)
 * \param row: number of rows    of the matrix (default: 0)
 */
MACRO_TEMPLATED
FMatrix<T>::FMatrix(fuint16 col, fuint16 row)
	: FObject()
{
	m_mat.reserve(height);

	for(fuint16 i= 0; i< height; i++)
	{
		m_mat.push_back(std::vector<T>());
		m_mat[i].reserve(width);
		
		for(fuint16 j= 0; j< width; j++)
		{
			m_mat[i].push_back(T());
		}
	}
}

/*!
 * \brief FMatrix<T>::FMatrix deep copy constructor
 * \param other: matrix to copy
 */
MACRO_TEMPLATED
FMatrix<T>::FMatrix(const FMatrix<T>& other)
	: FObject(other)
{
	try
	{
		m_mat.reserve(other.height());

		for(fuint16 i= 0; i< other.height(); i++)
		{
			m_mat.push_back(std::vector<T>());
			m_mat[i].reserve(other.width());
			
			for(fuint16 j= 0; j< other.width(); j++)
			{
				m_mat[i].push_back(T(other.m_mat[i][j]));
			}
		}
	}
    catch (std::exception& e) { std::cerr << __FILE__ << ":" << __LINE__ << " FMatrix Copy -> Error catched: " << e.what() << std::endl; }
}

/*!
 * \brief FMatrix<T>::~FMatrix Destructor
 */
MACRO_TEMPLATED
FMatrix<T>::~FMatrix()
{
	
}

/*!
 * \brief FMatrix<T>::operator= Deep assignement
 * \param other: matrix to copy
 * \return Reference to itself (for operation chaining)
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator=(const FMatrix<T>& other)
{
	m_mat.clear();

    this(other);
	
	return *this;
}

/*!
 * \brief FMatrix<T>::operator[] accessor of a certain index
 * \param index: Col / Row position in the matrix (out of range errors are left to std::vector)
 * \return Row / Col std::vector associated
 */
MACRO_TEMPLATED std::vector<T>&
FMatrix<T>::operator[](fuint16 index)
{
	return m_mat[index];
}

/*!
 * \brief FMatrix<T>::dispDebug displays the matrix the "ol' way", without taking care of the actual ui, so only for debug purposes!
 */
MACRO_TEMPLATED void
FMatrix<T>::dispDebug() const
{	
	std::cout << std::endl;
	for(auto row = m_mat.cbegin(); row != m_mat.cend(); row++)
	{
		for(auto col = row->cbegin(); col != row->cend(); col++)
		{
			std::cout << *col << "\t";
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
}


/*!
 * \brief FMatrix<T>::init initialise the matrix with a specific value
 * \param val: Value to be set in all matrix
 */
MACRO_TEMPLATED void
FMatrix<T>::init(const T& val)
{
	for(auto row = m_mat.begin(); row != m_mat.end(); row++)
	{
		for(auto col = row->begin(); col != row->end(); col++)
		{
			*col = val;
		}
	}
}

/*!
 * \brief FMatrix<T>::height Height accessor
 * \return Height of the matrix
 */
MACRO_TEMPLATED fuint16
FMatrix<T>::height() const
{
	return m_mat.size();
}

/*!
 * \brief FMatrix<T>::width Width accessor
 * \return Width of the matrix
 */
MACRO_TEMPLATED fuint16
FMatrix<T>::width () const
{
	return (height() == 0) ? 0 : m_mat[0].size();
}

/*!
 * \brief FMatrix<T>::operator bool
 * \return Boolean value: true if the matrix isn't empty, false otherwise
 */
MACRO_TEMPLATED
FMatrix<T>::operator bool() const
{
	return height() != 0 && width() != 0;
}

/*!
 * \brief FMatrix<T>::operator bool
 * \return Boolean value: false if the matrix isn't empty, true otherwise
 */
MACRO_TEMPLATED bool
FMatrix<T>::operator!() const
{
	return !(bool)*this;
}

/*!
 * \brief FMatrix<T>::operator+= Adds the value of one matrix to the corresponding value of another
 * \param m: other matrix
 * \return Reference to itself (for operation chaining)
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator+=(const FMatrix& m)
{
	if(*this && m && m.height() == height() && m.width() == width())
	{	
		for(fuint16 row= 0; row< height(); row++)
		{
			for(fuint16 col= 0; col< width(); col++)
			{
				m_mat[row][col] += m.m_mat[row][col];
			}
		}
	}
	
	return *this;
}

/*!
 * \brief FMatrix<T>::operator-= Substracts the value of one matrix to the corresponding value of another
 * \param m: other matrix
 * \return Reference to itself (for operation chaining)
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator-=(const FMatrix& m)
{
	if(*this && m && m.height() == height() && m.width() == width())
	{	
		for(fuint16 row= 0; row< height(); row++)
		{
			for(fuint16 col= 0; col< width(); col++)
			{
				m_mat[row][col] -= m.m_mat[row][col];
			}
		}
	}
	
	return *this;
}

/*!
 * \brief FMatrix<T>::operator*= Matricial multiplication
 * \param other: other matrix
 * \return Reference to itself (for operation chaining)
 * \exception Empty Matrix
 * \exception Matrices sizes not matching
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator*=(const FMatrix& other)
{
	if(!*this || !other) MACRO_EMPTYMAT;
	if(width() != other.height()) MACRO_WRONGMATSIZE(width(), other.height());
	
	FMatrix<T> formerThis(*this);
	*this = FMatrix(formerThis.height(), other.width());
	
	for(fuint16 i= 0; i< height(); i++)
	{
		for(fuint16 j= 0; j< width(); j++)
		{
			T sum = 0;
			
			for(fuint16 k= 0; k< other.height(); k++)
				sum += formerThis.m_mat[i][k] * other.m_mat[k][j];
			
			m_mat[i][j] = sum;
		}
	}
	
	return *this; 
}

/*!
 * \brief FMatrix<T>::operator*= Coef multiplication
 * \param coef: coefficient to multiply to all elements of the matrix
 * \return Reference to itself (for operation chaining)
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator*=(double coef)
{
	for(fuint16 row= 0; row< height(); row++)
	{
		for(fuint16 col= 0; col< width(); col++)
		{
			m_mat[row][col] *= coef;
		}
	}
	
	return *this;
}

/*!
 * \brief FMatrix<T>::operator/= Coef division
 * \param coef: coefficient to divise to all elements of the matrix
 * \return Reference to itself (for operation chaining)
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator/=(double coef)
{
	for(fuint16 row= 0; row< height(); row++)
	{
		for(fuint16 col= 0; col< width(); col++)
		{
			m_mat[row][col] /= coef;
		}
	}
	
	return *this;
}

/*!
 * \brief FMatrix<T>::operator+ Addition operator
 * \param a: Left operand
 * \param b: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator+(const FMatrix<T>& a, const FMatrix<T>& b)
{
	return FMatrix<T>(a) += b;
}

/*!
 * \brief FMatrix<T>::operator- Substraction operator
 * \param a: Left operand
 * \param b: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator-(const FMatrix<T>& a, const FMatrix<T>& b)
{
	return FMatrix<T>(a) -= b;
}

/*!
 * \brief FMatrix<T>::operator* Matricial multiplication operator
 * \param a: Left operand
 * \param b: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator*(const FMatrix<T>& a, const FMatrix<T>& b)
{
	return FMatrix<T>(a) *= b;
}

/*!
 * \brief FMatrix<T>::operator- Multiplication by an coefficient operator
 * \param a: Left operand
 * \param b: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator*(const FMatrix<T>& a, double coef)
{
	return FMatrix<T>(a) *= coef;
}

/*!
 * \brief FMatrix<T>::operator- Division by an coefficient operator
 * \param a: Left operand
 * \param b: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator/(const FMatrix<T>& a, double coef)
{
	return FMatrix<T>(a) /= coef;
}

}
