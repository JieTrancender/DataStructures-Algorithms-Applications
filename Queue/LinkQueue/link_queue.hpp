/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Github:www.github.com/JieTrancender
@Time:20th October
*/

#include "stdafx.h"
#include "my_queue.h"
#include "chain_node.hpp"
#include <iostream>
#include <sstream>

//MLQ stand for My Link Queue
namespace MLQ
{
	template <typename anytype>
	class LinkQueue : public MLQ::MyQueue<anytype>
	{
	public:
		LinkQueue(int initial_capacity = 10);
		~LinkQueue();

		//抽象类ADT方法
		bool empty() const;
		int size() const;
		anytype & front();
		anytype & back();
		void pop();
		void push(const anytype &element);

	private:
		MLQ::ChainNode<anytype> *m_queue_front;
		MLQ::ChainNode<anytype> *m_queue_back;
		int m_queue_size;
	};

	//函数功能：构造函数
	template <typename anytype>
	LinkQueue<anytype>::LinkQueue(int initial_capacity)
	{
		m_queue_front = nullptr;
		m_queue_back = nullptr;
		m_queue_size = 0;
	}

	//函数功能： 析构函数
	template <typename anytype>
	LinkQueue<anytype>::~LinkQueue()
	{
		while (m_queue_front != nullptr)
		{
			MLQ::ChainNode<anytype> *next_node = m_queue_front->next;
			delete m_queue_front;
			m_queue_front = next_node;
		}
	}

	//函数功能： 判断队列是否为空
	template <typename anytype>
	bool LinkQueue<anytype>::empty() const
	{
		return m_queue_front == nullptr;
	}

	//函数功能： 返回队列元素个数
	template <typename anytype>
	int LinkQueue<anytype>::size() const
	{
		return m_queue_size;
	}

	//函数功能： 返回队列首元素的引用
	template <typename anytype>
	anytype & LinkQueue<anytype>::front()
	{
		if (0 == m_queue_size)
		{
			std::ostringstream os;
			os << "The queue is empty .";
			throw os.str();
		}
		return m_queue_front->element;
	}

	//函数功能： 返回队尾元素的引用
	template <typename anytype>
	anytype & LinkQueue<anytype>::back()
	{
		if (0 == m_queue_size)
		{
			std::ostringstream os;
			os << "The queue is empty .";
			throw os.str();
		}
		return m_queue_back->element;
	}

	//函数功能： 删除队列首元素
	template <typename anytype>
	void LinkQueue<anytype>::pop()
	{
		if (m_queue_front == nullptr)
		{
			std::ostringstream os;
			os << "The queue is empty .";
			throw os.str();
		}
		MLQ::ChainNode<anytype> *temp = m_queue_front->next;
		delete m_queue_front;
		m_queue_front = temp;
		--m_queue_size;
	}

	//函数功能： 队尾插入队列
	template <typename anytype>
	void LinkQueue<anytype>::push(const anytype &element)
	{
		//申请新元素内存
		MLQ::ChainNode<anytype> *next_node = new ChainNode<anytype>(element, nullptr);
		if (m_queue_front == nullptr)
		{
			m_queue_front = next_node;
		}
		else
		{
			m_queue_back->next = next_node;
		}
		m_queue_back = next_node;
		++m_queue_size;
	}
}
