#pragma once

#include <iostream>

//mtl stand for My Test Library
namespace mtl
{
	template <typename anytype>
	struct BinarySearchTreeNode
	{
		anytype m_element;
		BinarySearchTreeNode<anytype> *m_left_child;
		BinarySearchTreeNode<anytype> *m_right_child;

		//构造函数
		BinarySearchTreeNode()
		{
			m_left_child = m_right_child = nullptr;
		}

		//构造函数
		BinarySearchTreeNode(anytype const& element) : BinarySearchTreeNode()  //委托构造函数
		{
			m_element = element;
		}

		//构造函数
		BinarySearchTreeNode(anytype const& element, BinarySearchTreeNode* left_child, BinarySearchTreeNode* right_child)
			: m_element(element), m_left_child(left_child), m_right_child(right_child) {}  //函数体无内容
	};
}
