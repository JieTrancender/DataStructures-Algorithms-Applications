// ArrayStack.cpp : 定义控制台应用程序的入口点。
//

/*
@Author:Jie Mo
@Email:582865471@vip.qq.com
@Time:13th October
@Github:www.github.com/JieTrancender
*/

#include "stdafx.h"
#include "array_stack.hpp"
#include "test.hpp"
#include <iostream>

int main()
{
	MAS::ArrayStack<PC> test;
	PC one = { "Admin_1","123456" };
	PC two = { "Admin_2","123456" };
	test.push(one);
	test.push(two);
	std::cout << "The size of stack is " << test.size() << std::endl;
	test.pop();
	std::cout << "The size of stack is " << test.size() << std::endl;
	test.pop();
	std::cout << "The size of stack is " << test.size() << std::endl;
    return 0;
}

