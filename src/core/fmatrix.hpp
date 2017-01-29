#ifndef FMATRIX_HPP
#define FMATRIX_HPP

#include "fobject.hpp"

// Macro for throwing an exception when accessing ouside the boundaries of a matrix
#define MACRO_WRONGMATSIZE(a, b) throw std::logic_error("Wrong matrix size for a matrix product (" + to_string(a) + " != " + to_string(b) + ") at line " + to_string(__LINE__) + " in " + __FILE__);

// Macro for throwing an exception when accessing an empty matrix
#define MACRO_EMPTYMAT throw std::logic_error("Empty Matrix at line " + to_string(__LINE__) + " in " + __FILE__);

namespace fit
{

/*!
 * Utility class for 2D arrays - aka Matrix.
 * Allow easy access via functions and operator overloading.
 *
 * \todo Customize the exceptions with overriden ones.
 */
MACRO_TEMPLATED
class FMatrix : public FObject
{
    public:
		// Constructors - Destructor
			FMatrix(const fuint16 height= 0, const fuint16 width= 0, const T& data = T());
			FMatrix(const FMatrix<T>& other);
			virtual ~FMatrix();

			std::vector<T>& operator[](const fuint16 index);

			fuint16 ncol() const;
			fuint16 nrow() const;

            #ifdef DEBUG
			FString debug() const;
            #endif

			explicit operator bool() const;
			bool operator!() const;

			FMatrix<T>& operator=(const FMatrix<T>& other);

			FMatrix<T>& operator+=(const FMatrix& mat);
			FMatrix<T>& operator-=(const FMatrix& mat);
			FMatrix<T>& operator*=(const FMatrix& mat);
			FMatrix<T>& operator*=(const double coef);
			FMatrix<T>& operator/=(const double coef);

	private:
        //! 2D array storing the internal matrix
        std::vector<std::vector<T> > m_mat;
};

MACRO_TEMPLATED
class incompatible_fmatrices : public std::logic_error
{
protected:
	FString m_what;
	
public:
	incompatible_fmatrices(const FMatrix<T>& mat1, const FMatrix<T>& mat2/*, const FString& fileName, const fuint16 lineNumber*/)
	{
		bool wrongcol{mat1.ncol() != mat2.nrow()};
		bool wrongrow{mat1.nrow() != mat2.ncol()};

		std::stringstream ss{"Wrong matrices size for a matrix product: "};
		if(wrongcol)
		{
			ss << mat1.ncol() << " != " << mat2.nrow();
			if(wrongrow) ss << " and ";
		}

		if(wrongrow) ss << mat1.nrow() << " != " << mat2.ncol();
		
		m_what = ss.str();
	}

	virtual FString what()
	{
		return m_what;
	}
};


MACRO_TEMPLATED FMatrix<T> operator+(const FMatrix<T>& mat1, const FMatrix<T>& mat2);
MACRO_TEMPLATED FMatrix<T> operator-(const FMatrix<T>& mat1, const FMatrix<T>& mat2);
MACRO_TEMPLATED FMatrix<T> operator*(const FMatrix<T>& mat1, const FMatrix<T>& mat2);
MACRO_TEMPLATED FMatrix<T> operator*(const FMatrix<T>& mat,  const double coef);
MACRO_TEMPLATED FMatrix<T> operator/(const FMatrix<T>& mat,  const double coef);

//! Matrix of Doubles
typedef FMatrix<double> FDMat;

/*!
 * Base constructor.
 *
 * \param col: Number of columns of the matrix (default: 0).
 * \param row: Number of rows of the matrix (default: 0).
 * \param data: Piece of data that will fill all cell of the matrix (default: T()).
 */
MACRO_TEMPLATED
FMatrix<T>::FMatrix(const fuint16 col, const fuint16 row, const T& data)
	: FObject()
{
	m_mat.reserve(row);

	for(fuint16 i= 0; i< row; i++)
	{
		m_mat.push_back(std::vector<T>());
		m_mat[i].reserve(col);

		for(fuint16 j= 0; j< col; j++)
		{
			m_mat[i].push_back(data);
		}
	}
}

/*!
 * Copy constructor.
 *
 * \param Matrix to copy from.
 */
MACRO_TEMPLATED
FMatrix<T>::FMatrix(const FMatrix<T>& other)
	: FObject(other)
{
	try
	{
        fuint16 ncol(other.ncol());
        fuint16 nrow(other.nrow());

		m_mat.reserve(nrow);

		for(fuint16 i= 0; i< nrow; i++)
		{
			m_mat.push_back(std::vector<T>());
			m_mat[i].reserve(ncol);

			for(fuint16 j= 0; j< ncol; j++)
			{
				m_mat[i].push_back(T(other.m_mat[i][j]));
			}
		}
	}
    catch (std::exception& e) { std::cerr << __FILE__ << ":" << __LINE__ << " FMatrix Copy -> Error catched: " << e.what() << std::endl; }
}

/*!
 * Destructor.
 */
MACRO_TEMPLATED
FMatrix<T>::~FMatrix()
{

}

/*!
 * Deep assignement operator.
 *
 * \param other: FMatrix to assign.
 * \return Reference to itself.
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator=(const FMatrix<T>& other)
{
	m_mat.clear();

    this(other);

	return *this;
}

/*!
 * Row accessor.
 *
 * \param index: Row position in the matrix (out of range errors are left to std::vector).
 * \return Row (std::vector) associated.
 */
MACRO_TEMPLATED std::vector<T>&
FMatrix<T>::operator[](const fuint16 index)
{
	return m_mat[index];
}

#ifdef DEBUG
/*!
 * Gets a debug string of the FMatrix.
 *
 * \return String containing the output.
 */
MACRO_TEMPLATED FString
FMatrix<T>::debug() const
{
    std::stringstream ss;
    using std::endl;

    ss << endl;
	for(auto row = m_mat.cbegin(); row != m_mat.cend(); row++)
	{
		for(auto col = row->cbegin(); col != row->cend(); col++)
		{
			ss << *col << "\t";
		}
		ss << endl;
	}
	ss << endl;
    return ss.str();
}
#endif

/*!
 * Get the number of rows.
 *
 * \return Number of rows of the FMatrix.
 */
MACRO_TEMPLATED fuint16
FMatrix<T>::nrow() const
{
    return m_mat.size();
}

/*!
 * Get the number of cols.
 *
 * \return Number of columns of the FMatrix.
 */
MACRO_TEMPLATED fuint16
FMatrix<T>::ncol() const
{
	return (nrow() == 0) ? 0 : m_mat[0].size();
}

/*!
 * Bool operator.
 * Use the matrix as a boolean condition depending on it being empty or not.
 *
 * \return Boolean value: true if the matrix isn't empty, false otherwise.
 */
MACRO_TEMPLATED
FMatrix<T>::operator bool() const
{
	return nrow() != 0 && ncol() != 0;
}

/*!
 * Bool operator (Use the matrix as a boolean condition depending on it being empty or not)
 *
 * \return True if the matrix is empty, false otherwise.
 */
MACRO_TEMPLATED bool
FMatrix<T>::operator!() const
{
	return !(bool)*this;
}

/*!
 * Adds each values of another FMatrix to this one.
 *
 * \param m: Other matrix.
 * \return Reference to itself.
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator+=(const FMatrix& m)
{
	if(*this && m && m.nrow() == nrow() && m.ncol() == ncol())
	{
		for(fuint16 row= 0; row< nrow(); row++)
		{
			for(fuint16 col= 0; col< ncol(); col++)
			{
				m_mat[row][col] += m.m_mat[row][col];
			}
		}
	}

	return *this;
}

/*!
 * Substracts each values of another FMatrix to this one.
 *
 * \param m: Other matrix.
 * \return Reference to itself.
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator-=(const FMatrix& m)
{
    return operator+=(m * -1);
}

/*!
 * Matricial multiplication
 *
 * \param other: Other matrix
 * \return Reference to itself (for operation chaining)
 *
 * \exception Empty Matrix
 * \exception Matrices sizes not matching
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator*=(const FMatrix& other)
{
	if(!*this || !other) MACRO_EMPTYMAT;
	if(ncol() != other.nrow()) MACRO_WRONGMATSIZE(ncol(), other.nrow());

	FMatrix<T> formerThis(*this);
	*this = FMatrix(formerThis.nrow(), other.ncol());

	for(fuint16 i= 0; i< nrow(); i++)
	{
		for(fuint16 j= 0; j< ncol(); j++)
		{
			T sum = 0;

			for(fuint16 k= 0; k< other.nrow(); k++)
				sum += formerThis.m_mat[i][k] * other.m_mat[k][j];

			m_mat[i][j] = sum;
		}
	}

	return *this;
}

/*!
 * Coef multiplication
 *
 * \param coef: Coefficient to multiply to all elements of the matrix
 * \return Reference to itself (for operation chaining)
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator*=(const double coef)
{
	for(fuint16 row= 0; row< nrow(); row++)
	{
		for(fuint16 col= 0; col< ncol(); col++)
		{
			m_mat[row][col] *= coef;
		}
	}

	return *this;
}

/*!
 * Coef division
 *
 * \param coef: Coefficient to divise to all elements of the matrix
 * \return Reference to itself (for operation chaining)
 */
MACRO_TEMPLATED FMatrix<T>&
FMatrix<T>::operator/=(const double coef)
{
	for(fuint16 row= 0; row< nrow(); row++)
	{
		for(fuint16 col= 0; col< ncol(); col++)
		{
			m_mat[row][col] /= coef;
		}
	}

	return *this;
}

/*!
 * Addition operator
 *
 * \param mat1: Left operand
 * \param mat2: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator+(const FMatrix<T>& mat1, const FMatrix<T>& mat2)
{
	return FMatrix<T>(mat1) += mat2;
}

/*!
 * Substraction operator
 *
 * \param mat1: Left operand
 * \param mat2: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator-(const FMatrix<T>& mat1, const FMatrix<T>& mat2)
{
	return FMatrix<T>(mat1) -= mat2;
}

/*!
 * Matricial multiplication operator
 * \param mat1: Left operand
 * \param mat2: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator*(const FMatrix<T>& mat1, const FMatrix<T>& mat2)
{
	return FMatrix<T>(mat1) *= mat2;
}

/*!
 * Multiplication by an coefficient operator
 *
 * \param mat: Left operand
 * \param coef: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator*(const FMatrix<T>& mat, const double coef)
{
	return FMatrix<T>(mat) *= coef;
}

/*!
 * Division by an coefficient operator
 *
 * \param mat: Left operand
 * \param coef: Right operand
 * \return Matrix resulting
 */
MACRO_TEMPLATED FMatrix<T>
operator/(const FMatrix<T>& mat, double coef)
{
	return FMatrix<T>(mat) /= coef;
}

} // Namespace fit

#endif // FMATRIX_HPP
