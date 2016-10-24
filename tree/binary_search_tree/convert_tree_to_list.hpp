#pragma once

#include "./binary_search_tree_node.hpp"

#include <iostream>

template <typename anytype>
mtl::BinarySearchTreeNode<anytype>* treeToLinkedList(mtl::BinarySearchTreeNode<anytype> *root)
{
	mtl::BinarySearchTreeNode<anytype> *head, *tail;
	helper(head, tail, root);
	
	return head;
}

template <typename anytype>
void helper(mtl::BinarySearchTreeNode<anytype>* &head, mtl::BinarySearchTreeNode<anytype>*& tail, mtl::BinarySearchTreeNode<anytype>* root)
{
	mtl::BinarySearchTreeNode<anytype>* left_tail, right_head;

	if (nullptr == root)
	{
		head = tail = nullptr;
		return;
	}

	helper(head, left_tail, root->m_left_child);
	helper(right_head, tail, root->m_right_child);

	if (nullptr != left_tail)
	{
		left_tail->m_right_child = root;
		root->m_left_child = left_tail;
	}
	else
	{
		head = root;
	}

	if (nullptr != right_head)
	{
		root->m_right_child = right_head;
		right_head->m_left_child = root;
	}
	else
	{
		tail = root;
	}
}
