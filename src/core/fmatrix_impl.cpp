#include "fobject.hpp"

namespace fit
{

TEMPLATE_ /* Constructor */
FMatrix<T>::FMatrix(fuint16 height, fuint16 width)
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

TEMPLATE_ /* Copy Constructor */
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
	catch (std::exception& e) { std::cerr << __FILE__ << ":" << __LINE__ << " Copy -> Error catched: " << e.what() << std::endl; }
}

TEMPLATE_ /* Destructor */
FMatrix<T>::~FMatrix()
{
	
}

TEMPLATE_ FMatrix<T>&
FMatrix<T>::operator=(const FMatrix<T>& other)
{
	m_mat.clear();
	
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
	catch (std::exception& e) { std::cerr << __FILE__ << ":" << __LINE__ << " Copy -> Error catched: " << e.what() << std::endl; }
	
	return *this;
}

TEMPLATE_ std::vector<T>&
FMatrix<T>::operator[](fuint16 index)
{
	return m_mat[index];
}

TEMPLATE_ void
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

TEMPLATE_ void
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

TEMPLATE_ fuint16
FMatrix<T>::height() const
{
	return m_mat.size();
}

TEMPLATE_ fuint16
FMatrix<T>::width () const
{
	return (height() == 0) ? 0 : m_mat[0].size();
}

TEMPLATE_
FMatrix<T>::operator bool() const
{
	return height() != 0 && width() != 0;
}
     
TEMPLATE_ bool
FMatrix<T>::operator!() const
{
	return !(bool)*this;
}

TEMPLATE_ FMatrix<T>&
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

TEMPLATE_ FMatrix<T>&
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

TEMPLATE_ FMatrix<T>&
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

TEMPLATE_ FMatrix<T>&
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

TEMPLATE_ FMatrix<T>&
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


TEMPLATE_ FMatrix<T>
operator+(const FMatrix<T>& a, const FMatrix<T>& b)
{
	return FMatrix<T>(a) += b;
}

TEMPLATE_ FMatrix<T>
operator-(const FMatrix<T>& a, const FMatrix<T>& b)
{
	return FMatrix<T>(a) -= b;
}

TEMPLATE_ FMatrix<T>
operator*(const FMatrix<T>& a, const FMatrix<T>& b)
{
	return FMatrix<T>(a) *= b;
}

TEMPLATE_ FMatrix<T>
operator*(const FMatrix<T>& a, double coef)
{
	return FMatrix<T>(a) *= coef;
}

TEMPLATE_ FMatrix<T>
operator/(const FMatrix<T>& a, double coef)
{
	return FMatrix<T>(a) /= coef;
}

}
