#pragma once

#include "./binary_tree_node.hpp"
#include "./binary_tree_interface.h"

#include <iostream>
#include <string>
#include <queue>
#include <sstream>

namespace mtl
{
	template <typename anytype>
	class BinaryTree : public BinaryTreeInterface< BinaryTreeNode<anytype> >
	{
	public:
		//构造函数
		BinaryTree() : m_root(nullptr) {}  //函数体无内容

		//析构函数
		~BinaryTree()
		{
			erase();
		}

		//创建二叉树
		void create()
		{
			create(&m_root);
		}

		//判空
		bool empty() const override
		{
			return 0 == m_size;
		}

		//获得节点数
		int size() const override
		{
			return m_size;
		}

		//前序遍历
		void preOrder(void(*func)(BinaryTreeNode<anytype> *))
		{
			visit = func;
			preOrder(m_root);
			std::cout << std::endl;
		}

		//中序遍历
		void inOrder(void(*func)(BinaryTreeNode<anytype> *))
		{
			visit = func;
			inOrder(m_root);
			std::cout << std::endl;
		}

		//后序遍历
		void postOrder(void(*func)(BinaryTreeNode<anytype> *))
		{
			visit = func;
			postOrder(m_root);
			std::cout << std::endl;
		}

		//层序遍历
		void levelOrder(void(*func)(BinaryTreeNode<anytype> *))
		{
			visit = func;
			levelOrder(m_root);
			std::cout << std::endl;
		}

		//获得高度(深度)
		int height() const
		{
			return height(m_root);
		}

		//获得根节点
		BinaryTreeNode<anytype>* getRoot()
		{
			return m_root;
		}

		//删除树
		void erase()
		{
			postOrder(dispose);
			m_root = nullptr;
			m_size = 0;
		}

	private:
		BinaryTreeNode<anytype> *m_root;
		static int m_size;

		static void (*visit)(BinaryTreeNode<anytype> *);
		static void preOrder(BinaryTreeNode<anytype> *);
		static void inOrder(BinaryTreeNode<anytype> *);
		static void postOrder(BinaryTreeNode<anytype> *);
		static void levelOrder(BinaryTreeNode<anytype> *);
		static int height(BinaryTreeNode<anytype> *);
		static void dispose(BinaryTreeNode<anytype> *);
		static void output(BinaryTreeNode<anytype> *);
		static void create(BinaryTreeNode<anytype> **);
	};

	//静态访问函数指针初始化
	template <typename anytype>
	void (*BinaryTree<anytype>::visit)(BinaryTreeNode<anytype> *) = nullptr;

	//静态元素个数size初始化
	template <typename anytype>
	int BinaryTree<anytype>::m_size = 0;

	//私有前序遍历算法
	template <typename anytype>
	void BinaryTree<anytype>::preOrder(BinaryTreeNode<anytype> *root)
	{
		if (nullptr != root)
		{
			BinaryTree<anytype>::visit(root);
			preOrder(root->m_left_child);
			preOrder(root->m_right_child);
		}
	}

	//私有中序遍历
	template <typename anytype>
	void BinaryTree<anytype>::inOrder(BinaryTreeNode<anytype> *root)
	{
		if (nullptr != root)
		{
			inOrder(root->m_left_child);
			BinaryTree<anytype>::visit(root);
			inOrder(root->m_right_child);
		}
	}

	//私有后序遍历
	template <typename anytype>
	void BinaryTree<anytype>::postOrder(BinaryTreeNode<anytype> *root)
	{
		if (nullptr != root)
		{
			postOrder(root->m_left_child);
			postOrder(root->m_right_child);
			BinaryTree<anytype>::visit(root);
		}
	}

	//私有按层遍历
	template <typename anytype>
	void BinaryTree<anytype>::levelOrder(BinaryTreeNode<anytype> *root)
	{
		std::queue< BinaryTreeNode<anytype> *> q;
		while (nullptr != root)
		{
			BinaryTree<anytype>::visit(root);

			if (nullptr != root->m_left_child)
			{
				q.push(root->m_left_child);
			}

			if (nullptr != root->m_right_child)
			{
				q.push(root->m_right_child);
			}

			if (q.empty())
			{
				return;
			}

			root = q.front();
			q.pop();
		}
	}

	//获得高度
	template <typename anytype>
	int BinaryTree<anytype>::height(BinaryTreeNode<anytype> *root)
	{
		if (nullptr == root)
		{
			return 0;
		}
		else
		{
			int height_left = height(root->m_left_child);
			int height_right = height(root->m_right_child);
			return height_left > height_right ? ++height_left : ++height_right;  //自增一以加上这一层的高度
		}
	}

	//删除节点
	template <typename anytype>
	void BinaryTree<anytype>::dispose(BinaryTreeNode<anytype> *root)
	{
		delete root;
	}

	//创建树
	template <typename anytype>
	void BinaryTree<anytype>::create(BinaryTreeNode<anytype> **root)
	{
		anytype data;
		std::cin.clear();
		std::cin >> data;
		
		if ('#' != data)
		{
			++m_size;
			*root = new BinaryTreeNode<anytype>(data);

			if (nullptr != *root)
			{
				create(&((*root)->m_left_child));
				create(&((*root)->m_right_child));
			}
			else
			{
				std::cerr << __FILE__ << ' ' << __FUNCTION__ << '#' << __LINE__ << "内存申请失败!\n";
			}
		}
		else
		{
			root = nullptr;
		}
	}
}
