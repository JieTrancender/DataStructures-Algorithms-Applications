#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Github:www.github.com/JieTrancender
@Time:14th October
*/

#include "my_queue.h"
#include <iostream>
#include <sstream>
#include <algorithm>

//MAQ stand for My Array Queue
namespace MAQ
{
	template <typename anytype>
	class ArrayQueue : public MyQueue<anytype>
	{
	public:
		ArrayQueue(int initial_capacity = 10);
		~ArrayQueue();

		//抽象类ADT方法
		bool empty() const;
		int size() const;
		anytype & front();
		anytype & back();
		void pop();
		void push(const anytype &element);

	protected:
		void changeLength(anytype *queue, int old_length, int new_length);

	private:
		anytype *m_queue;
		int m_queue_front;
		int m_queue_back;	//队列尾，队列长度 = m_queue_back + 1,当队列为空时，m_queue_back = -1
		int m_queue_length;
	};

	//函数功能:构造函数
	template <typename anytype>
	ArrayQueue<anytype>::ArrayQueue(int initial_capacity)
	{
		m_queue_length = initial_capacity;
		m_queue = new anytype[m_queue_length];
		m_queue_front = m_queue_back = 0;
	}

	//函数功能:析构函数
	template <typename anytype>
	ArrayQueue<anytype>::~ArrayQueue()
	{
		delete[] m_queue;
	}

	//函数功能:返回true，当且仅当队列为空
	template <typename anytype>
	bool ArrayQueue<anytype>::empty() const
	{
		return m_queue_front == m_queue_back;
	}

	//函数功能:返回队列中元素个数
	template <typename anytype>
	int ArrayQueue<anytype>::size() const
	{
		return m_queue_back - m_queue_front;
	}

	//函数功能:返回头元素的引用
	template <typename anytype>
	anytype & ArrayQueue<anytype>::front()
	{
		return m_queue[m_queue_front % m_queue_length];
	}

	//函数功能:返回尾元素的引用
	template <typename anytype>
	anytype & ArrayQueue<anytype>::back()
	{
		return m_queue[m_queue_back % m_queue_length];
	}

	//函数功能：删除首元素
	template <typename anytype>
	void ArrayQueue<anytype>::pop()
	{
		if (m_queue_front == m_queue_back)
		{
			std::ostringstream os;
			os << "The queue is empty .";
			throw os.str();
		}
		m_queue_front = (m_queue_front + 1) % m_queue_length;
		m_queue[m_queue_front].~anytype();
	}

	//函数功能:将元素element加入队尾
	template <typename anytype>
	void ArrayQueue<anytype>::push(const anytype &element)
	{
		//判断如果插入元素使队列变慢，则数组增长
		if ((m_queue_back + 1) % m_queue_length == m_queue_front)
		{
			changeLength(m_queue, m_queue_length, 2 * m_queue_length);
		}

		m_queue_back = (m_queue_back + 1) % m_queue_length;
		m_queue[m_queue_back] = element;
	}

	//函数功能:数组队列长度增长
	template <typename anytype>
	void ArrayQueue<anytype>::changeLength(anytype *array, int old_length, int new_length)
	{
		if (new_length <= old_length)
		{
			std::ostringstream os;
			os << "Error,The new length should bigger than the old length .";
			throw os.str();
		}
		anytype *new_queue = new anytype[new_length];
		int start = (m_queue_front + 1) % m_queue_length;

		//判断原数组是否形成环
		if (start <= 1)
		{
			std::copy(m_queue + m_queue_front, m_queue + m_queue_back + 1, new_queue);
		}

		//原数组形成环
		else
		{
			std::copy(m_queue + m_queue_front, m_queue + m_queue_length, new_queue);
			std::copy(m_queue, m_queue + m_queue_back + 1, new_queue + m_queue_length - start);
		}

		//设置新队列的首尾元素位置
		m_queue_front = 2 * m_queue_length - 1;
		m_queue_back = m_queue_length - 2;
		m_queue_length *= 2;
		delete[] m_queue;
		m_queue = new_queue;
	}
}

#endif	//array_queue.hpp
