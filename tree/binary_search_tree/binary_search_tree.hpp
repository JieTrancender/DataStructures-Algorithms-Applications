#pragma once

#include "./binary_search_tree_node.hpp"
#include "./binary_search_tree_interface.h"

#include <iostream>
#include <queue>

namespace mtl
{
	template <typename anytype>
	class BinarySearchTree : public BinarySearchTreeInterface<BinarySearchTreeNode<anytype>>
	{
	public:
		//构造函数
		BinarySearchTree() : m_root(nullptr) {}

		//析构函数
		~BinarySearchTree()
		{
			erase();
		}

		//创建搜索二叉树
		void create()
		{
			create(&m_root);
		}

		//判空
		bool empty() const override
		{
			return 0 == m_size;
		}

		//获得结点树
		int size() const override
		{
			return m_size;
		}

		//前序遍历
		void preOrder(void(*func)(BinarySearchTreeNode<anytype> *))
		{
			visit = func;
			preOrder(m_root);
			std::cout << std::endl;
		}

		//中序遍历
		void inOrder(void(*func)(BinarySearchTreeNode<anytype> *))
		{
			visit = func;
			inOrder(m_root);
			std::cout << std::endl;
		}

		//后序遍历
		void postOrder(void(*func)(BinarySearchTreeNode<anytype> *))
		{
			visit = func;
			postOrder(m_root);
			std::cout << std::endl;
		}

		//按层遍历
		void levelOrder(void(*func)(BinarySearchTreeNode<anytype> *))
		{
			visit = func;
			levelOrder(m_root);
			std::cout << std::endl;
		}

		//获得高度
		int height() const
		{
			return height(m_root);
		}

		//获得根结点
		BinarySearchTreeNode<anytype>* getRoot()
		{
			return m_root;
		}

		//删除搜索树
		void erase()
		{
			postOrder(dispose);
			m_root = nullptr;
			m_size = 0;
		}
		
	private:
		BinarySearchTreeNode<anytype> *m_root;
		static int m_size;

		static void (*visit)(BinarySearchTreeNode<anytype> *);
		static void preOrder(BinarySearchTreeNode<anytype> *);
		static void inOrder(BinarySearchTreeNode<anytype> *);
		static void postOrder(BinarySearchTreeNode<anytype> *);
		static void levelOrder(BinarySearchTreeNode<anytype> *);
		static int height(BinarySearchTreeNode<anytype> *);
		static void dispose(BinarySearchTreeNode<anytype> *);
		static void output(BinarySearchTreeNode<anytype> *);
		static void create(BinarySearchTreeNode<anytype> **);
	};

	//静态函数指针初始化
	template <typename anytype>
	void (*BinarySearchTree<anytype>::visit)(BinarySearchTreeNode<anytype> *) = nullptr;

	//静态变量size初始化
	template <typename anytype>
	int BinarySearchTree<anytype>::m_size = 0;

	//私有前序遍历
	template <typename anytype>
	void BinarySearchTree<anytype>::preOrder(BinarySearchTreeNode<anytype> *root)
	{
		if (nullptr != root)
		{
			BinarySearchTree<anytype>::visit(root);
			preOrder(root->m_left_child);
			preOrder(root->m_right_child);
		}
	}

	//私有中序遍历
	template <typename anytype>
	void BinarySearchTree<anytype>::inOrder(BinarySearchTreeNode<anytype> *root)
	{
		if (nullptr != root)
		{
			inOrder(root->m_left_child);
			BinarySearchTree<anytype>::visit(root);
			inOrder(root->m_right_child);
		}
	}

	//私有后序遍历
	template <typename anytype>
	void BinarySearchTree<anytype>::postOrder(BinarySearchTreeNode<anytype> *root)
	{
		if (nullptr != root)
		{
			postOrder(root->m_left_child);
			postOrder(root->m_right_child);
			BinarySearchTree<anytype>::visit(root);
		}
	}

	//私有按层遍历
	template <typename anytype>
	void BinarySearchTree<anytype>::levelOrder(BinarySearchTreeNode<anytype> *root)
	{
		std::queue<BinarySearchTreeNode<anytype> *> q;
		while (nullptr != root)
		{
			BinarySearchTree<anytype>::visit(root);

			if (nullptr != root->m_left_child);
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
	int BinarySearchTree<anytype>::height(BinarySearchTreeNode<anytype> *root)
	{
		if (nullptr == root)
		{
			return 0;
		}
		else
		{
			int height_left = height(root->m_left_child);
			int height_right = height(root->m_right_child);
			return height_left > height_right ? ++height_left : ++height_right;
		}
	}

	//删除结点
	template <typename anytype>
	void BinarySearchTree<anytype>::dispose(BinarySearchTreeNode<anytype> *root)
	{
		delete root;
	}

	//创建树
	template <typename anytype>
	void BinarySearchTree<anytype>::create(BinarySearchTreeNode<anytype> **root)
	{
		anytype data;
		std::cin.clear();
		std::cin >> data;

		if ('#' != data)
		{
			++m_size;
			*root = new BinarySearchTreeNode<anytype>(data);

			if (nullptr != *root)
			{
				create(&(*root)->m_left_child);
				create(&(*root)->m_right_child);
			}
			else
			{
				std::cerr << __FILE__ << ' ' << __LINE__ << "#" << __FUNCTION__ << " 内存申请失败\n";
			}
		}
		else
		{
			*root = nullptr;
		}
	}
	
}
