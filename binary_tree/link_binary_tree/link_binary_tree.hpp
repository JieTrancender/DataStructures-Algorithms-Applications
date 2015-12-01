#ifndef LINK_BINARY_TREE_HPP
#define LINK_BINARY_TREE_HPP

#include "my_binary_tree.h"
#include "binary_tree_node.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

//MBT stand for My Binary Tree
namespace MBT
{
	template<typename anytype>
	class LinkBinaryTree : public MBT::MyBinaryTree < MBT::BinaryTreeNode<anytype> >
	{

	public:

		//构造函数
		LinkBinaryTree() : m_root(nullptr){};

		//析构函数
		~LinkBinaryTree()
		{
			erase();
		}

		//创建二叉树
		void create()
		{
			create(&m_root);
		}

		//判断是否为空
		bool empty() const override
		{
			return m_tree_size == 0;
		}

		//获得节点数
		int size() const override
		{
			return m_tree_size;
		}

		//前序遍历
		void preOrder(void(*the_visit)(BinaryTreeNode<anytype> *))
		{
			visit = the_visit;
			preOrder(m_root);
			cout << endl;
		}

		//中序遍历
		void inOrder(void(*the_visit)(BinaryTreeNode<anytype> *))
		{
			visit = the_visit;
			inOrder(m_root);
			cout << endl;
		}

		//后序遍历
		void postOrder(void(*the_visit)(BinaryTreeNode<anytype> *))
		{
			visit = the_visit;
			postOrder(m_root);
			cout << endl;
		}

		//层次遍历
		void levelOrder(void(*the_visit)(BinaryTreeNode<anytype> *))
		{
			visit = the_visit;
			levelOrder(m_root);
		}

		//后序遍历删除二叉树
		void erase()
		{
			postOrder(dispose);
			m_root = nullptr;
			m_tree_size = 0;
		}

		//前序顺序输出二叉树
		void preOrderOutput()
		{
			preOrder(output);
			std::cout << std::endl;
		}

		//确定二叉树高度
		int height() const
		{
			return height(m_root);
		}

		//获得二叉树的根
		BinaryTreeNode<anytype>* getRoot()
		{
			return m_root;
		}

	private:
		BinaryTreeNode<anytype> *m_root;
		static int m_tree_size;
		static void (*visit)(BinaryTreeNode<anytype> *);
		static void preOrder(BinaryTreeNode<anytype> *);
		static void inOrder(BinaryTreeNode<anytype> *);
		static void postOrder(BinaryTreeNode<anytype> *);
		static void levelOrder(BinaryTreeNode<anytype> *);
		static int height(BinaryTreeNode<anytype> *);
		static void dispose(BinaryTreeNode<anytype> *tree)
		{
			delete tree;
		}
		static void output(BinaryTreeNode<anytype> *tree)
		{
			std::cout << tree->m_element;
		}
		static void create(BinaryTreeNode<anytype> **root);
	};

	//对静态访问函数指针初始化
	template <typename anytype>
	void (*LinkBinaryTree<anytype>::visit)(BinaryTreeNode<anytype> *) = nullptr;

	template <typename anytype>
	int LinkBinaryTree<anytype>::m_tree_size = 0;

	//类LinkBinaryTree的私有前序遍历算法
	template <typename anytype>
	void LinkBinaryTree<anytype>::preOrder(BinaryTreeNode<anytype> *tree)
	{
		if (tree != nullptr)
		{
			LinkBinaryTree<anytype>::visit(tree);
			preOrder(tree->m_left_child);
			preOrder(tree->m_right_child);
		}
	}

	//类LinkBinaryTree的私有中序遍历算法
	template <typename anytype>
	void LinkBinaryTree<anytype>::inOrder(BinaryTreeNode<anytype> *tree)
	{
		if (tree != nullptr)
		{
			preOrder(tree->m_left_child);
			LinkBinaryTree<anytype>::visit(tree);
			preOrder(tree->m_right_child);
		}
	}

	//类LinkBinaryTree的私有后序遍历算法
	template <typename anytype>
	void LinkBinaryTree<anytype>::postOrder(BinaryTreeNode<anytype> *tree)
	{
		if (tree != nullptr)
		{
			postOrder(tree->m_left_child);
			postOrder(tree->m_right_child);
			LinkBinaryTree<anytype>::visit(tree);
		}
	}

	//类LinkBinaryTree的层次遍历算法
	template <typename anytype>
	void LinkBinaryTree<anytype>::levelOrder(BinaryTreeNode<anytype> *tree)
	{
		std::queue<BinaryTreeNode<anytype> *>q;
		while (tree != nullptr)
		{
			LinkBinaryTree<anytype>::visit(tree);
			if (tree->m_left_child != nullptr)
				q.push(tree->m_left_child);
			if (tree->m_right_child != nullptr)
				q.push(tree->m_right_child);

			//提取下一访问结点
			if (q.empty())
				return;
			tree = q.front();
			q.pop();
		}
	}

	//确定二叉树高度算法
	template <typename anytype>
	int LinkBinaryTree<anytype>::height(BinaryTreeNode<anytype> *tree)
	{
		if (tree == nullptr)
			return 0;
		else
		{
			int height_left = height(tree->m_left_child);
			int height_right = height(tree->m_right_child);
			return height_left > height_right ? ++height_left : ++height_right;
		}
	}

	//创建二叉树
	template <typename anytype>
	void LinkBinaryTree<anytype>::create(BinaryTreeNode<anytype> **root)
	{
		anytype data;
		cin.clear();
		cin >> data;
		if (data != '#')
		{
			m_tree_size++;
			*root = new BinaryTreeNode<anytype>(data);
			if (*root != nullptr)
			{
				create(&(*root)->m_left_child);
				create(&(*root)->m_right_child);
			}
			else
			{
				cout << "内存申请失败" << endl;
			}
		}
		else
		{
			root = nullptr;
		}
	}
}

#endif	//link_binary_tree.hpp
