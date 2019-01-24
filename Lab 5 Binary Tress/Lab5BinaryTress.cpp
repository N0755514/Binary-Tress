// Lab5BinaryTress.cpp : Defines the entry point for the console application.
//
#pragma once 
#include "stdafx.h"
#include <iostream>

using namespace std;



class BinaryTree
{
public:
	struct TreeNode
	{
		int value;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;


	BinaryTree() //constructor 
	{
		root = NULL;
	}

	void insertNode(int);
	//void searchNode(int);
	//void displayInOrder(TreeNode *);
	//void showNodesInOrder(void)
	//{
	//	displayinOrder(root);
	//}
};

void BinaryTree::insertNode(int num)
{
	TreeNode *newNode; // pointer to new node
	TreeNode *nodePtr; //pointer to traverse the tree

	//Create new node 

	newNode = new TreeNode;
	newNode->value = num; //new node is allocated and its value is initialised
	newNode->left = newNode->right = NULL; //set to NULL because all nodes must be inserted as leaf nodes 
	nodePtr = NULL; //just initialising pointer

	if (!root)  // is the tree empty?
		root = newNode; //make a root to start the tree
	else
	{
		nodePtr = root;
	}

	while (nodePtr != NULL) //finding the correct place for a node within the tree
	{
		if (num < nodePtr->value) //if the new value is less than the roots value, we know it will be inserted somewhere on the left subtree.
		{
			if (nodePtr->left)
				nodePtr = nodePtr->left;
			else

				nodePtr->left = newNode; 
			break;
		}			
		else if (num > nodePtr->value) //otherwise, on the right
		{
			if (nodePtr->right)
				nodePtr = nodePtr->right;
			else
			{
				nodePtr->right = newNode;
				break;
			}
		}

		// We simply traverse the subtree, comparing each node along the way with the new node's value, and deciding if we should continue to the left or the right. 
		
		else
		{
			cout << "Duplicate value found in tree. \n";
			break;
		}

			
		}
	}



int main()
{
	BinaryTree tree;
	cout << "Inserting nodes" << endl;
	tree.insertNode(23);
	tree.insertNode(3);
	tree.insertNode(1);
	tree.insertNode(15);
	tree.insertNode(50);
	tree.insertNode(28);
	tree.insertNode(221);
    return 0;
}

