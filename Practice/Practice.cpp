// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Recursive
int Fibonacci(int n)
{
	if (0 == n) return 0;
	if (1 == n) return 1;
	return Fibonacci(n - 2) + Fibonacci(n - 1);
}

// Fibonacci iterative
int fibs[100];
int Fibonacc2(int n)
{
	if (0 == n) return 0;
	if (1 == n) return 1;
	if (0 != fibs[n]) return fibs[n];
	fibs[n] = Fibonacc2(n - 2) + Fibonacc2(n-1);
	return fibs[n];
}

// Binary tree is BST
// Left < Node < right
// All nodes in left subtree < Node < all nodes in right subtree

bool IsBST(Node* n, int min, int max)
{
	if (!n) return true;
	if (min < n->val && n->val < max)
	{
		return IsBST(n->left, min, n->val) && IsBST(n->right, n->val, max);
	}
	return false;
}

// Nodes in a BST are visited in ascending order when visiting in in-order
bool IsBST2(Node* n, int prev)
{
	if (!n) return true;
	bool left = IsBST2(n->left, prev);
	if (!left) return false;
	if (n->val < prev) return false;
	return IsBST2(n->right, n->val)
}

void InorderBSTIterative(Node* n)
{
	if (!n) return;


}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

