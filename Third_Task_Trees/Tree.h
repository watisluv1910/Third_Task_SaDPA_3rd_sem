#pragma once

#include "NodeStruct.h"

using std::string;
using std::vector;

// Create expression tree class from postfix expression
class Tree
{
public:
	
	// Default constructor
	Tree() : root(nullptr) {};
	
	// Constructor with postfix string argument
	Tree(const string& exp);

	// Get root
	Node* getRoot() { return root; };

	int calcTree(const Node* node);

	// Print tree data method
	void printTreeData(const string& prefix, const Node* node, bool isLeft);

	// Print tree method
	void printTree(const Node* node, int level = 0);
	
private:

	// Node root field
	Node* root;

	//
	Node* createTree(const string& infix);
	
	//
	vector<int> findOperators(const string& exp);

	//
	int calcCenter(const string& exp, const std::vector<int>& operatorsIndexes);
	
	// Check if character is operator method
	bool isOperator(char c);
};