// LinkStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test.hpp"
#include "link_stack.hpp"
#include <iostream>

int main()
{
	MLS::PC one = { "Admin_1", "123456" };
	MLS::PC two = { "Admin_2", "123456" };
	MLS::LinkStack<MLS::PC> test(2);
	test.push(one);
	test.push(two);
	try
	{
		std::cout << "The size of stack is " << test.size() << std::endl;
		test.pop();
		std::cout << "The size of stack is " << test.size() << std::endl;
		test.pop();
		std::cout << "The size of stack is " << test.size() << std::endl;
		test.pop();
	}
	catch (std::string str)
	{
		std::cout << str << std::endl;
	}
    return 0;
}

