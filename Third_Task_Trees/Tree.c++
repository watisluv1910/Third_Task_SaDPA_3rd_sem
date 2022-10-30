// Create expression tree from postfix expression

#include <iostream>
#include <string>
#include <vector>

#include "Tree.h"

using std::string;
using std::vector;

// Construct tree
Tree::Tree(const string& exp)
{
	root = createTree(exp);
}

// Create expression subtree from infix expression
Node* Tree::createTree(const string& exp)
{
	Node* node = new Node(exp.front());

	// Vector of current expression's operators indexes:
	vector<int> operatorsIndexes = findOperators(exp);

	if (operatorsIndexes.size())
	{
		// The value of the central element in 
		// operatorsIndexes array for current expression:
		const int center = calcCenter(exp, operatorsIndexes);

		node = new Node(exp.at(center));

		node->left = createTree(
			exp.substr(
				0, 
				center
			)
		);

		node->right = createTree(
			exp.substr(center + 1)
		);
	}

	return node;
}

vector<int> Tree::findOperators(const string& exp)
{
	vector<int> operatorsIndexes;

	for (int i = 0; i < exp.size(); i++)
	{
		if (isOperator(exp.at(i)))
		{
			operatorsIndexes.push_back(i);
		}
	}

	return operatorsIndexes;
}

int Tree::calcCenter(const string& exp, 
	const vector<int>& operatorsIndexes)
{
	// The value of the central element in operatorsIndexes:
	return operatorsIndexes.at(operatorsIndexes.size() / 2);
}

// Check is the character is operator
bool Tree::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
	{
		return true;
	}
	return false;
}

// Print tree as a file system
void Tree::printTreeData(const string& prefix, const Node* node, bool isLeft)
{
	// Check if node is not null
	if (node != nullptr)
	{
		std::cout << prefix;
		
		// Check if node is left child
		std::cout << (isLeft ? "|->" : "L->");
		
		// Print node value
		
		std::cout << node->value << std::endl;

		// Print left subtree
		printTreeData(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printTreeData(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

// Print tree as a tree
void Tree::printTree(const Node* node, int level)
{
	// Check if node is not null
	if (node != nullptr)
	{
		// Print right child
		printTree(node->right, level + 1);

		// Print node value
		for (int i = 0; i < level; i++)
		{
			std::cout << "    ";
		}
		std::cout << node->value << std::endl;

		// Print left child
		printTree(node->left, level + 1);
	}
}

// Calculate tree value
int Tree::calcTree(const Node* node)
{
	// Check if node is not null
	if (node != nullptr)
	{
		// Check if node is operator
		if (isOperator(node->value))
		{
			// Calculate left child
			int left = calcTree(node->left);

			// Calculate right child
			int right = calcTree(node->right);

			// Calculate node value
			switch (node->value)
			{
			case '+':
				return left + right;
			case '-':
				return left - right;
			case '*':
				return left * right;
			case '/':
				return left / right;
			case '^':
				return pow(left, right);
			}
		}
		else
		{
			// Return node value
			return node->value - '0';
		}
	}
}
