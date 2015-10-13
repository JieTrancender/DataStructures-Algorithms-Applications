#ifndef LINK_STACK_HPP
#define LINK_STACK_HPP

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Time:13th October
@Github:www.github.com/JieTrancender
*/

#include "chainnode.hpp"
#include "my_stack.h"
#include <sstream>

//MLS stand for MyLinkStack
namespace MLS
{
	template <typename anytype>
	class LinkStack : public MyStack<anytype>
	{
	public:
		LinkStack(int initial_capacity = 10);
		~LinkStack();

		//抽象数据类ADT方法
		bool empty() const;
		int size() const;
		anytype & top();
		void pop();
		void push(const anytype &element);

	private:
		ChainNode<anytype> *m_stack_top;
		int m_stack_size;	//栈中元素个数
	};

	//构造函数，但是并没有申请内存，仅仅是为了接口统一
	template <typename anytype>
	LinkStack<anytype>::LinkStack(int initial_capacity)
	{
		m_stack_top = nullptr;
		m_stack_size = 0;
	}

	//析构函数
	template <typename anytype>
	LinkStack<anytype>::~LinkStack()
	{
		while (m_stack_top != nullptr)
		{
			ChainNode<anytype> *temp = m_stack_top->next;
			delete m_stack_top;
			m_stack_top = temp;
		}
	}

	//判断栈是否为空
	template <typename anytype>
	bool LinkStack<anytype>::empty() const
	{
		return m_stack_size == 0;
	}

	//返回栈中元素个数
	template <typename anytype>
	int LinkStack<anytype>::size() const
	{
		return m_stack_size;
	}

	//返回栈顶元素
	template <typename anytype>
	anytype & LinkStack<anytype>::top()
	{
		if (m_stack_size == 0)
		{
			std::ostringstream os;
			os << "The size of stack is empty .";
			throw os.str();
		}
		return m_stack_top->element;
	}

	//栈尾出栈
	template <typename anytype>
	void LinkStack<anytype>::pop()
	{
		if (m_stack_size == 0)
		{
			std::ostringstream os;
			os << "The size of stack is empty .";
			throw os.str();
		}
		ChainNode<anytype> *temp = m_stack_top->next;
		delete m_stack_top;
		m_stack_top = temp;
		--m_stack_size;
	}

	//入栈
	template <typename anytype>
	void LinkStack<anytype>::push(const anytype &element)
	{
		m_stack_top = new ChainNode<anytype>(element, m_stack_top);
		++m_stack_size;
	}
}

#endif //link_stack.hpp
