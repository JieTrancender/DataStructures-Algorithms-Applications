#include "link_binary_tree.hpp"
#include <iostream>

using namespace std;

void visit(MBT::BinaryTreeNode<char> *element)
{
	std::cout << element->m_element;
}

int main(int argc, char **argv)
{
	MBT::LinkBinaryTree<char> my_tree;
	cout << "Creating..." << endl;
	my_tree.create();
	cout << "The size is " << my_tree.size() << endl;
	cout << "The hight is " << my_tree.height() << endl;
	cout << "The root is " << my_tree.getRoot() << endl;
	cout << "PreOrder: ";
	my_tree.preOrder(visit);
	cout << "InOrder: ";
	my_tree.inOrder(visit);
	cout << "PostOrder: ";
	my_tree.postOrder(visit);
	cout << endl;
	return 0;
}
