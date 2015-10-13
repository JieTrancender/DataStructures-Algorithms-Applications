#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Time:13th October
@Github:www.github.com/JieTrancender
*/

#include "my_stack.h"
#include <sstream>
#include <algorithm>

//MAS stand for MyArrayStack
namespace MAS
{
	template <typename anytype>
	class ArrayStack : public MyStack<anytype>
	{
	public:
		ArrayStack(int initial_capacity = 10);
		virtual ~ArrayStack();

		//抽象类ADT方法
		bool empty() const;
		int size() const;
		anytype & top();
		void pop();
		void push(const anytype &element);

	private:
		int m_stack_top;	//当前栈顶
		int m_array_length;		//栈容量
		anytype *stack;		//元素数组
	};

	//改变数组element的内存长度
	template <typename anytype>
	void ChangeLength(anytype *element, int old_length, int new_length)
	{
		anytype *temp = new anytype[new_length];
		std::copy(element, element + old_length, temp);
		delete[] element;
		element = temp;
	}

	//构造函数
	template <typename anytype>
	ArrayStack<anytype>::ArrayStack(int initial_capacity)
	{
		if (initial_capacity < 1)
		{
			std::ostringstream os;
			os << "Initial capacity = " << initial_capacity << " must be > 0";
			throw os.str();
		}
		m_array_length = initial_capacity;
		stack = new anytype[m_array_length];
		m_stack_top = -1;
	}

	//析构函数
	template <typename anytype>
	ArrayStack<anytype>::~ArrayStack()
	{
		delete[] stack;
	}

	//判断栈是否为空
	template <typename anytype>
	bool ArrayStack<anytype>::empty() const
	{
		return m_stack_top == -1;
	}

	//返回栈的长度
	template <typename anytype>
	int ArrayStack<anytype>::size() const
	{
		return m_stack_top + 1;
	}

	//返回栈顶值
	template <typename anytype>
	anytype & ArrayStack<anytype>::top()
	{
		if (m_stack_top == -1)
		{
			std::ostringstream os;
			os << "The stack is empty .";
			throw os.str();
		}
		return stack[m_stack_top];
	}

	//出栈尾
	template <typename anytype>
	void ArrayStack<anytype>::pop()
	{
		if (m_stack_top == -1)
		{
			std::ostringstream os;
			os << "The stack is empty .";
			throw os.str();
		}
		stack[m_stack_top--].~anytype();	//anytype的析构函数
	}

	//将元素element压入栈
	template <typename anytype>
	void ArrayStack<anytype>::push(const anytype &element)
	{
		//数组空间已满，容量加倍
		if (m_stack_top == m_array_length - 1)
		{
			ChangeLength(stack, m_array_length, 2 * m_array_length);
			m_array_length *= 2;
		}
		//在栈顶插入
		stack[++m_stack_top] = element;
	}
}

#endif //array_stack.h
