#ifndef MY_DIAGONA_MATRIX_HPP
#define MY_DIANONA_MATRIX_HPP

#include <iostream>

//MDM stand for My Diagona Matrix
namespace MDM
{
	template <typename anytype>
	class DiagonaMatrix
	{
	public:
		//构造函数
		DiagonaMatrix(int n = 10);

		//析构函数
		~DiagonaMatrix(){ delete[] m_element; }

		//返回矩阵(i, j)元素值
		anytype get(int, int) const;

		//设置(i, j)元素值
		void set(int, int, const anytype &);

	private:
		int m_n;	//矩阵维数
		anytype *m_element;
	};

	template <typename anytype>
	DiagonaMatrix<anytype>::DiagonaMatrix(int n)
	{
		if (n < 1)
		{
			ostream os;
			os << "The matrix size must be > 0";
			throw os.c_str();
		}

		m_n = n;
		m_element = new anytype[m_n];
	}

	template <typename anytype>
	anytype DiagonaMatrix<anytype>::get(int i, int j) const
	{
		if (i < 1 || i > n || j < 1 || j > n)
		{
			ostream os;
			os << "The index is not in bounds";
			throw os.c_str();
		}

		if (i == j)
			return m_element[i - 1];	//对角线上的元素
		else
			return 0;					//非对角线上的元素
	}

	template <typename anytype>
	void DiagonaMatrix<anytype>::set(int i, int j, const anytype &value)
	{
		if (i < 1 || i > n || j < 1 || j > n)
		{
			ostream os;
			os << "The index is not in bounds";
			throw os.c_str();
		}

		if (i == j)
			m_element[i - 1] = value;
		else
		{
			if (value != 0)
			{
				ostream os;
				os << "Non-diagona elements must be zero";
				throw os.c_str();
			}
		}
	}
}

#endif //my_diagona_matrix.hpp
