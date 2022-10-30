#include <iostream>
#include <string>
#include <vector>

#include "Tree.h"

int main() 
{	
	// Enter string expression
	string exp;
	std::cout << "Enter the expression:\n";
	std::cin >> exp;
	
	// Create tree
	Tree tree(exp);
	
	// Print tree
	std::cout << "\nTree in data view:\n";
	tree.printTreeData("", tree.getRoot(), false);

	std::cout << "\nTree in tree view:\n";
	tree.printTree(tree.getRoot());
	
	// Calculate left subtree
	if (tree.getRoot()->left)
		std::cout << "\nLeft subtree value: " << tree.calcTree(tree.getRoot()->left);
	
	// Calculate right subtree
	if (tree.getRoot()->right)
		std::cout << "\nRight subtree value: " << tree.calcTree(tree.getRoot()->right);

	// Print root node
	std::cout << "\nRoot node value: " << tree.getRoot()->value << '\n';

	// Calculate tree
	std::cout << "\nResult: " << tree.calcTree(tree.getRoot()) << '\n';
	
	return 0;
}