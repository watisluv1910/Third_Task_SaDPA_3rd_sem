#pragma once

struct Node
{
    char value;
    Node* left, *right;

	// Default constructor
    Node() : value(0), left(nullptr), right(nullptr) {};

    Node(char value) : left(nullptr), right(nullptr)
    {
        this->value = value;
    };
};