/*************************************************************************
    > File Name: binary_tree_interface.h
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Mon Oct 24 19:44:31 2016
 ************************************************************************/
#pragma once

namespace mtl
{
	template <typename anytype>
	class BinaryTreeInterface
	{
	public:
		//构造函数
		virtual ~BinaryTreeInterface() {}  //函数体无内容

		//判空
		virtual bool empty() const = 0;

		//查看元素个数
		virtual int size() const = 0;

		//前序遍历
		virtual void preOrder(void(*)(anytype *)) = 0;

		//中序遍历
		virtual void inOrder(void(*)(anytype *)) = 0;

		//后序遍历
		virtual void postOrder(void(*)(anytype *)) = 0;

		//按层遍历
		virtual void levelOrder(void(*)(anytype *)) = 0;
	};
}
