// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode *Left;
	BstNode *Right;
};

BstNode* getNewNode(int data)
{
	BstNode * newNode = new BstNode();
	newNode->data = data;
	newNode->Left = NULL;
	newNode->Right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL)
	{//empty tree
		root = getNewNode(data);
	}
	else if (data <= root->data)
	{
		root->Left = Insert(root->Left, data);
	}
	else
	{
		root->Right = Insert(root->Right, data);
	}
	return root;
}

bool Search(BstNode* root, int data)
{
	bool result;
	if (root == NULL)
		result = false;
	else if (root->data == data)
		result = true;
	else if (data <= root->data)
		result = Search(root->Left, data);
	else
		result = Search(root->Right, data);
	return result;
}


int main()
{
	BstNode *root = NULL; //Krijimi i nje peme te zbrazte
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	int Numri;
	cout << "Caktoni numrin qe do te kerkohet: ";
	cin >> Numri;
	if (Search(root, Numri))
		cout << "Numri eshte gjetur!\n";
	else
		cout << "Numri nuk eshte gjetur!\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
