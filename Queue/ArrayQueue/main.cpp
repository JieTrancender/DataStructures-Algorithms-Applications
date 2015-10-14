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
	MAQ::ArrayQueue<MAQ::PC> test;
	MAQ::PC pc_1 = { "admin_1","123456" };
	MAQ::PC pc_2 = { "admin_2","123456" };
	test.push(pc_1);
	test.push(pc_2);
    return 0;
}
