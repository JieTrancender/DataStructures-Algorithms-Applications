#ifndef MY_BINARY_TREE_H
#define MY_BINARY_TREE_H

#include <iostream>

//MBT stand for My Binary Tree
namespace MBT
{
	//二叉树抽象类
	template <typename anytype>
	class MyBinaryTree
	{
	public:
		virtual ~MyBinaryTree(){};
		virtual bool empty() const = 0 ;
		virtual int size() const = 0;
		virtual void preOrder(void(*)(anytype *)) = 0;
		virtual void inOrder(void(*)(anytype *)) = 0;
		virtual void postOrder(void(*)(anytype *)) = 0;
		virtual void levelOrder(void(*)(anytype *)) = 0;
	};
}

#endif //my_binary_tree.h
