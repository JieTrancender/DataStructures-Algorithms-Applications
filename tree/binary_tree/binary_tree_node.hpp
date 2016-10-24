#pragma once

#include <iostream>

//mtl stand for My Test Library
namespace mtl
{
	template <typename anytype>
	struct BinaryTreeNode
	{
		anytype m_element;
		BinaryTreeNode<anytype> *m_left_child;
		BinaryTreeNode<anytype> *m_right_child;

		//构造函数
		BinaryTreeNode()
		{
			m_left_child = m_right_child = nullptr;
		}

		//构造函数
		BinaryTreeNode(anytype const& element) : BinaryTreeNode()  //委托构造函数
		{
			m_element = element;
		}

		//构造函数
		BinaryTreeNode(anytype const& element, BinaryTreeNode* left_child, BinaryTreeNode* right_child)
			: m_element(element), m_left_child(left_child), m_right_child(right_child) {}  //函数体无内容
	};
}
