// ArrayQueue.cpp : 定义控制台应用程序的入口点。
//

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Github:www.github.com/JieTrancender
@Time:14th October
*/

#include "stdafx.h"
#include "array_queue.hpp"
#include "test.hpp"
#include <iostream>


int main()
{
	try
	{
		MAQ::ArrayQueue<MAQ::PC> test;
		MAQ::PC pc_1 = { "admin_1","_Trancender" };
		MAQ::PC pc_2 = { "admin_2","ShaoJie@qq.com" };
		test.push(pc_1);
		test.push(pc_2);
		std::cout << test.size() << std::endl;
		std::cout << test.front() << std::endl;
		std::cout << test.back() << std::endl;
		test.pop();
		std::cout << test.size() << std::endl;
		std::cout << test.front() << std::endl;
		std::cout << test.back() << std::endl;
		test.pop();
		std::cout << test.front() << std::endl;
		std::cout << test.back() << std::endl;
		std::cout << test.size() << std::endl;
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
    return 0;
}
