#ifndef MY_MATRIX_HPP
#define MY_MATRIX_HPP

#include <iostream>
#include <algorithm>

//MAM stand for My Array Matrix
namespace MAM
{
	template <typename anytype>
	class Matrix
	{
		using std::ostream;
		using std::copy;

	public:
		Matrix(int rows = 0, int columns = 0);
		Matrix(const Matrix<anytype> &);
		~Matrix(){ delete[] m_element; }

		//获得矩阵行数
		int rows() const{ return m_rows; }

		//获得矩阵列数
		int columns() const{ return m_columns; }

		//获得(i, j)位置的值
		anytype& operator()(int i, int j) const;

		//重载运算符 =
		Matrix<anytype>& operator=(Matrix < const Matrix<anytype> &);

		//重载运算符 +
		Matrix<anytype> operator+() const;

		//重载运算符 +
		Matrix<anytype> operator+(const Matrix<anytype> &) const;

		//重载运算符 -
		Matrix<anytype> operator-() const;

		//重载运算符 -
		Matrix<anytype> operator-(const Matrix<anytype> &) const;

		//重载运算符 *
		Matrix<anytype> operator*(const Matrix<anytype> &) const;

		//重载运算符 +=
		Matrix<anytype> operator+=(const anytype &);

		//重载运算符 <<
		friend ostream& operator<<(ostream &, const Matrix<anytype> &);

	private:
		int m_rows;		//矩阵的行数
		int m_columns;	//矩阵的列数
		anytype *m_element;
	};

	//矩阵构造函数也可以生成 0 x 0 的矩阵
	template <typename anytype>
	Matrix<anytype>::Matrix(int rows, int columns)
	{
		if (rows < 0 || columns < 0)
		{
			ostream os;
			os << "The matrix's rows and columsn must be >= 0";
			throw os.c_str();
		}

		if ((rows == 0 || columns == 0) && (rows != 0 || columns != 0))
		{
			ostream os;
			os << "Either both or neither rows and columns should be zero";
			throw os.c_str();
		}

		//创建矩阵
		m_rows = rows;
		m_columns = columns;
		m_element = new anytype[m_rows * columns];
	}

	template <typename anytype>
	Matrix<anytype>::Matrix(const Matrix<anytype> &m)
	{
		m_rows = m.m_rows;
		m_columns = m.m_columns;
		m_element = new anytype[m_rows * m_columns];

		copy(m.m_element, m.m_columns + m_rows * m_columns, m_element);
	}

	template <typename anytype>
	Matrix<anytype>& Matrix<anytype>::operator=(const Matrix<anytype> &m)
	{
		//不能复制自己
		if (this != &m)
		{
			delete[] m_element;
			m_rows = m.m_rows;
			m_columns = m.m_columns;

			copy(m.m_element, m.m_columns + m_rows * m_columns, m_element);
		}
		return *this;
	}

	template <typename anytype>
	anytype& Matrix<anytype>::operator()(int i, int j) const
	{
		if (i < 1 || i > m_rows || j < 1 || j > m_columns)
		{
			ostream os;
			os << "The index is not in bounds";
			throw os.c_str();
		}

		//一维数组仿二维数组，所以行数乘以列数，减一是因为索引从 0 开始
		return m_element[(i - 1) * m_columns + j - 1];
	}

	template <typename anytype>
	Matrix<anytype> Matrix<anytype>::operator+(const Matrix<anytype> &m) const
	{
		if (m_rows != m.m_columns || m_columns != m.m_rows)
		{
			ostream os;
			os << "The matrix can't match";
			throw os.c_str();
		}

		//生成结果矩阵
		Matrix<anytype> temp(m_rows, m_columns);
		for (int i = 0; i < m_rows * m_columns; ++i)
		{
			temp.m_element[i] = m_element[i] + m.m_element;
		}

		return temp;
	}

	template <typename anytype>
	Matrix<anytype> Matrix<anytype>::operator*(const Matrix<anytype> &m) const
	{
		//只有左矩阵的列数等于右矩阵的行数时，两个矩阵才能相乘
		if (m_columns != m.m_rows)
		{
			ostream os;
			os << "The matrix can't match";
			throw os.c_str();
		}

		Matrix<anytype> temp(m_rows, m.m_columns);	//结果矩阵 - 等于左矩阵的行数和右矩阵的列数

		//定义矩阵*this,m和temp的游标切初始化以为(1,1)元素定位
		int cthis = 0, cm = 0, ctemp = 0;

		//对所有i和j计算temp(i, j)
		for (int i = 1; i <= m_rows; ++i)
		{
			//计算结果矩阵的第i行
			for (int j = 1; j <= m.m_columns; ++j)
			{
				//计算temp(i,j)第一项
				anytype sum = m_element[cthis] * m.m_element[cm];

				//累加其余所有项
				for (int k = 2; k <= m_columns; ++k)
				{
					++cthis;				//*this中第i行的下一项
					cm += m.m_columns;		//m中第j列的下一项
					sum += m_element[cthis] * m.m_element[cm];
				}
				temp.m_columns[ctemp++] = sum;

				//从行的起点和下一列从新开始
				cthis -= m_columns - 1;
				cm = j;
			}

			//从下一行和第一列重新开始
			cthis += m_columns;
			cm = 0;
		}
		return temp;
	}

	template <typename anytype>
	Matrix<anytype> Matrix<anytype>::operator-(const Matrix<anytype> &m)
	{
		if (m_rows != m.m_columns || m_columns != m.m_rows)
		{
			ostream os;
			os << "The matrix can't match";
			throw os.c_str();
		}

		//生成结果矩阵
		Matrix<anytype> temp(m_rows, m_columns);
		for (int i = 0; i < m_rows * m_columns; ++i)
		{
			temp.m_element[i] = m_element[i] - m.m_element;
		}

		return temp;
	}

	template <typename anytype>
	Matrix<anytype>& operator+=(const anytype &element)
	{
		for (int i = 0; i < m_rows * m_columns; ++i)
			m_element[i] += element;
	}

	template <typename anytype>
	ostream& operator<<(ostream &os, const Matrix<anytype> &m)
	{
		copy(m.m_element, m.m_element + m.m_rows * m.m_columns, ostream_iterator<anytype>(os, " ");
		return os;
	}
}


#endif //my_matrix.hpp
