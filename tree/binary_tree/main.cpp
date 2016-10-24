/*************************************************************************
    > File Name: main.cpp
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Mon Oct 24 20:35:40 2016
 ************************************************************************/

#include "./binary_tree.hpp"

#include <iostream>

void visit(mtl::BinaryTreeNode<char> *element)
{
	std::cout << element->m_element;
}

int main(int argc, char* argv[])
{
	mtl::BinaryTree<char> my_binary_tree;
	std::cout << "Creating..." << std::endl;
	my_binary_tree.create();

	std::cout << "Ths tree's size is " << my_binary_tree.size() << std::endl;
	std::cout << "This tree's height is " << my_binary_tree.height() << std::endl;
	std::cout << "The root is " << my_binary_tree.getRoot() << std::endl;

	std::cout << "PreOrder: ";
	my_binary_tree.preOrder(visit);

	std::cout << "InOurder: ";
	my_binary_tree.inOrder(visit);

	std::cout << "PostOrder: ";
	my_binary_tree.postOrder(visit);

	std::cout << std::endl;

	return 0;
}
