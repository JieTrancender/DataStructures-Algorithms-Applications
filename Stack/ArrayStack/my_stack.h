#ifndef MY_STACK_H
#define MY_STACK_H

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Time:13th October
@Github:www.github.com/JieTrancender
*/

//MAS stand for MyArrayStack
namespace MAS
{
	//C++抽象类栈
	template <typename anytype>
	class MyStack
	{
	public:
		virtual ~MyStack() {};
		virtual bool empty() const = 0;
		virtual int size() const = 0;
		virtual anytype & top() = 0;
		virtual void pop() = 0;
		virtual void push(const anytype &element) = 0;
	};
}


#endif //my_stack.h
