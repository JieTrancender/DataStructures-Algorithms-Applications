// LinkQueue.cpp : 定义控制台应用程序的入口点。
//

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Github:www.github.com/JieTrancender
@Time:20th October
*/

#include "stdafx.h"
#include "link_queue.hpp"
#include "test.hpp"
#include <iostream>

int main()
{
	try
	{
		MTC::PC pc_1 = { "Admin","123456" };
		MTC::PC pc_2 = { "root", "654321" };
		MLQ::LinkQueue<MTC::PC> *test = new MLQ::LinkQueue<MTC::PC>;

		/*std::cout << "the queue size is " << test->size() << std::endl;
		std::cout << "the first element of the queue is : " << test->front() << std::endl;
		std::cout << "the last element of the queue is : " << test->back() << std::endl;*/

		test->push(pc_1);
		std::cout << "The queue size is " << test->size() << std::endl;
		std::cout << "The first element of the queue is : " << test->front() << std::endl;
		std::cout << "The last element of the queue is : " << test->back() << std::endl;

		test->push(pc_2);
		std::cout << "The queue size is " << test->size() << std::endl;
		std::cout << "The first element of the queue is : " << test->front() << std::endl;
		std::cout << "The last element of the queue is : " << test->back() << std::endl;

		test->pop();
		std::cout << "The queue size is " << test->size() << std::endl;
		std::cout << "The first element of the queue is : " << test->front() << std::endl;
		std::cout << "The last element of the queue is : " << test->back() << std::endl;

		test->pop();
		std::cout << "The queue size is " << test->size() << std::endl;
		std::cout << "The first element of the queue is : " << test->front() << std::endl;
		std::cout << "The last element of the queue is : " << test->back() << std::endl;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
    return 0;
}

