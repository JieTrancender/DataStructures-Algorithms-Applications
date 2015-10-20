#ifndef MY_QUEUE_H
#define MY_QUEUE_H

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Github:www.github.com/JieTrancender
@Time:20th October
*/

//MLQ stand for My Link Queue
namespace MLQ
{
	template <typename anytype>
	class MyQueue
	{
	public:
		virtual ~MyQueue() {}
		virtual bool empty() const = 0;		//返回true，当且仅当队列为空
		virtual int size() const = 0;		//返回队列中元素的个数
		virtual anytype & front() = 0;		//返回头元素的引用
		virtual anytype & back() = 0;		//返回尾元素的引用
		virtual void pop() = 0;		//删除首元素
		virtual void push(const anytype &element) = 0;		//把元素element加入队列
	};
}

#endif	//my_queue.h
