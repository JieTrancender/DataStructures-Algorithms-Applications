#ifndef BINARY_TREE_NODE_HPP
#define BINARY_TREE_NODE_HPP

#include <iostream>

//MBT stand for My Binary Tree
namespace MBT
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
		BinaryTreeNode(const anytype &element) : BinaryTreeNode()
		{
			m_element = element;
		}

		//构造函数
		BinaryTreeNode(const anytype &element, BinaryTreeNode *left_child, BinaryTreeNode *right_child)
			: m_element(element), m_left_child(left_child), m_right_child(right_child){};
	};
}

#endif BINARY_TREE_NODE_HPP	//binary_tree_node.hpp
