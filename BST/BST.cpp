// SerializeBST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <climits>
#include <assert.h>
#include <math.h>
#include <algorithm>
using namespace std;

// http://leetcode.com/2010/09/determine-if-binary-tree-is-binary.html
struct BSTNode
{
	int mValue;
	BSTNode* mLeft;
	BSTNode* mRight;

	BSTNode(unsigned int value) : mValue(value), mLeft(nullptr), mRight(nullptr) { };

	// Returns pointer to newly inserted value
	static BSTNode* Insert(BSTNode*& root, int value);

	// Returns false if the value is not in the BST
	static bool Delete(BSTNode* root, int value);

	// Returns the node that has the value or nullptr if value is not in BST
	static BSTNode* Find(BSTNode* root, int value);

	// Returns true if the BT is a BST, false otherwise
	static bool IsBST(BSTNode* root, int minVal, int maxVal);
	// If an in-order traversal yields node values in ascending order, tree is BST
	static bool IsBST2(BSTNode* n, int& prevVal);

	// Returns the depth of the BST
	static int Depth(BSTNode* root);

	// Returns the depth and whether is balanced
	// BT is balanced if for any node, the depth of the left and right sub-trees differ by 1 or less.
	static int IsBalanced(BSTNode* n, bool& isBal);

	// Pre-order traversal
	static void SerializeOut(BSTNode* n, ofstream& fon);
	// Sol 1 - for each number call Insert, O(n^2)
	// Sol 2 - numbers are in place, just link them to the right child node
	static void SerializeIn(BSTNode*& n, int& value, int minVal, int maxVal, ifstream& fin);

	static void PrintDepth(BSTNode* n, int& depth);

	// Deletes all nodes of the BST
	static bool Destroy(BSTNode*& root);

	typedef void(*Visit)(BSTNode* n);
	static void PreOrderTraversalRecursive(BSTNode* n, Visit visitorFunc);
	static void InOrderTraversalRecursive(BSTNode* n, Visit visitorFunc);
	static void PreOrderTraversalIterative(BSTNode* n, Visit visitorFunc);
	static void BreadthFirstTraversal
};

BSTNode* BSTNode::Insert(BSTNode*& root, int value)
{
	BSTNode* n = nullptr;
	if (nullptr == root)
	{
		n = root = new BSTNode(value);
	}
	else if (value < root->mValue)
	{
		n = Insert(root->mLeft, value);
	}
	else if (value > root->mValue)
	{
		n = Insert(root->mRight, value);
	}
	return n;
}

BSTNode* BSTNode::Find(BSTNode* n, int value)
{
	if (!n) return nullptr;
	if (value == n->mValue) return n;
	if (value < n->mValue) return Find(n->mLeft, value);
	if (value > n->mValue) return Find(n->mRight, value);
	return nullptr;
}

int BSTNode::Depth(BSTNode* root)
{
	if (nullptr == root) return 0;
	return 1 + max(Depth(root->mLeft), Depth(root->mRight));
}

int BSTNode::IsBalanced(BSTNode* n, bool& isBal)
{
	if (!isBal) return 0;
	if (nullptr == n) return 0;
	int depthLeft = IsBalanced(n->mLeft, isBal);
	int depthRight = IsBalanced(n->mRight, isBal);

	int diff = abs(depthLeft - depthRight);
	// check for n right here, if not balanced, can bail out; else, let it go through
	if (diff > 1) isBal = false;

	return 1 + max(depthLeft, depthRight);
}

bool BSTNode::Destroy(BSTNode*& root)
{
	// Delete nodes in post-order
	if (nullptr != root)
	{
		Destroy(root->mLeft);
		Destroy(root->mRight);
		delete root;
		root = nullptr;
	}
	return true;
}

void BSTNode::PreOrderTraversalRecursive(BSTNode* n, Visit visitorFunc)
{
	if (!visitorFunc) return;

	if (nullptr != n)
	{
		(*visitorFunc)(n);
		PreOrderTraversalRecursive(n->mLeft, visitorFunc);
		PreOrderTraversalRecursive(n->mRight, visitorFunc);
	}
}

void BSTNode::PreOrderTraversalIterative(BSTNode* n, Visit visitorFunc)
{

}

void BSTNode::InOrderTraversalRecursive(BSTNode* n, Visit visitorFunc)
{
	if (!visitorFunc) return;

	if (nullptr != n)
	{
		InOrderTraversalRecursive(n->mLeft, visitorFunc);
		(*visitorFunc)(n);
		InOrderTraversalRecursive(n->mRight, visitorFunc);
	}

}

void BSTNode::InOrderTraversalIterative(BSTNode* n)
{
	// Push the current node into a stack
	// Go to its left child
	// If current node is null, pop the top of the stack, visit it
	// Go to the right child
	// until stack is empty

	if (!n) return;
	Stack<BSTNode*> stack;
	bool done = false;
	BSTNode* current = n;

	while (!done)
	{
		if (current)
		{
			stack.push(current);
			current = current->mLeft;
		}
		else
		{
			if (stack.Empty())
			{
				done = true
			}
			else
			{
				current = stack.pop();
				Visit(current);
				current = current->mRight;
			}
		}
	}
}

void BSTNode::PostOrderTraversalIterative(BSTNode* n)
{
	if (!n) return;

	Stack<BSTNode*> stack;
	Stack<BSTNode*> outputStack;

	stack.push(n);
	while (!stack.empty())
	{
		BSTNode* cur = stack.pop();
		outputStack.push(cur);
		if (cur->mLeft) stack.push(cur->mLeft);
		if (cur->mRight) stack.push(cur->mRight);
	}
	while (!outputStack.empty())
	{
		BSTNode* cur = outputStack.pop();
		print(cur->mValue);
	}
}

BSTNode* BSTNode::LowestCommonAncestorBST(Node* root, Node *p, Node *q) 
{
	if (!root || !p || !q) return NULL;
	if (max(p->data, q->data) < root->data)
		return LCA(root->left, p, q);
	else if (min(p->data, q->data) > root->data)
		return LCA(root->right, p, q);
	else
		return root;
}

bool CompareBinaryTree(BSTNode* a, BSTNode* b)
{
	if (!a && !b) return true;
	if (a && b)
	{
		return (a->mValue == b->mValue && CompareBinaryTree(a->mLeft, b->mLeft) && CompareBinaryTree(a->mRight, b->mRight));
	}
	return false; // either a or b is nullptr
}
static void Print(BSTNode* n)
{
	if (n) cout << n->mValue << " ";
}

bool BSTNode::IsBST(BSTNode* n, int minValue, int maxValue)
{
	// All nodes on the left of the root are smaller than the root
	// All nodes on the right of the root are greater than the root

	// Sol1 - Brute force
	// For a node, go through all its left children and make sure they are smaller, go through all right children and make sure they are greater
	// Repeat for node->left
	// Repeat for node->right
	// O(n^2)

	// Sol 2 - Max of root-left < root && min of root->right > root
	// O(n)

	// Sol 3 - in-order traversal yiels node values in acending order
	// O(n)

	// Sol 4 - 
	// if node value within (min, max) limits
	//		Check n->left for (min, n->Value) && Check n->right for (n->data, max)
	if (!n) return true;
	if (minValue < n->mValue && n->mValue < maxValue)
	{
		return IsBST(n->mLeft, minValue, n->mValue) && IsBST(n->mRight, n->mValue, maxValue);
	}
	return false;
}


// In a BST, an in-order travesal of the nodes lists them in ascending order
// prevVal should always be smaller than current nodes value
bool BSTNode::IsBST2(BSTNode* n, int& prevVal)
{
	if (n == nullptr) return true;

	bool left = IsBST2(n->mLeft, prevVal);
	if (!left) return false;
	if (n->mValue < prevVal) return false;
	prevVal = n->mValue;
	bool right = IsBST2(n->mRight, prevVal);
	return right;
}

// No need for null-sentinel because we know the tree is BST so values need to obey condition
void BSTNode::SerializeIn(BSTNode*& n, int& value, int minVal, int maxVal, ifstream& fin)
{
	if (minVal < value && value < maxVal)
	{
		int nodeVal = value;
		n = new BSTNode(nodeVal);
		if (fin >> value)
		{
			SerializeIn(n->mLeft, value, minVal, nodeVal, fin);
			SerializeIn(n->mRight, value, nodeVal, maxVal, fin);
		}
	}
}

// Serialize out using a pre-order traversal, mark null children with special char (#)
// Serialize in (pre-order traversal)
void DeSerializeBinaryTree(Node*& n)
{
	bool isNumber = true;
	int token = 0;
	if (readNextToken(fin, token, isNumber))
	{
		if (isNumber)
		{
			n = Node(token);
			SerializeBinaryTree(n->left);
			SerializeBinaryTree(n->Right);
		}
	}
}
// Deserialize binary tree without using special chars as placeholders for null children
// We need the pre-order and in-order representation of the tree.
// The first item in the pre-order array is the root node,
// Find it in the in-order array, and thus we know the bounds of the left and the right sub-trees
Node* DeserializeBinaryTree(int pre[], int preStart, int preEnd, int in[], int inStart, int inEnd)
{
	if (preStart > preEnd) return nullptr;
	if (preStart == preEnd) return new Node(pre[preStart]);

	// Find root node index in in-order array
	int rootIndex = binarySearch(in, inStart, inEnd, pre[preStart]);
	// Calculate count of nodes in left and right sub-trees
	int leftCount = rootIndex - inStart;
	//int rightCount = inEnd - rootIndex;

	Node* n = new Node(pre[preStart]);
	n->left = DeserializeBinaryTree(pre, preStart + 1, preStart + leftCount, in, inStart, inStart + leftCount - 1);
	n->right = DeserializeBinaryTree(pre, preStart + leftCount + 1, preEnd, in, inStart + leftCount + 1, inEnd);

}

void BSTNode::PrintDepth(BSTNode* n, int& depth)
{
	// Pre-order traversal, increment depth when going down to child node, decrement when coming up to parent node
	if (n)
	{
		cout << "Node: " << n->mValue << "Depth: " << depth << endl;
		PrintDepth(n->mLeft, ++depth);
		PrintDepth(n->mRight, ++depth);
	}
	--depth;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BSTNode* root = new BSTNode(30);
	BSTNode::Insert(root, 20);
	BSTNode::Insert(root, 10);
	BSTNode::Insert(root, 35);
	BSTNode::Insert(root, 50);
	BSTNode::Insert(root, 40);
	BSTNode::Insert(root, 42);
	cout << "Pre-order: ";
	BSTNode::PreOrderTraversalRecursive(root, &(Print));
	cout << endl;
	cout << "In-order: ";
	BSTNode::InOrderTraversalRecursive(root, &(Print));
	cout << endl;
	// Break the BST
	//root->mRight->mRight->mLeft->mValue = 34;
	cout << "Is BST?: " << BSTNode::IsBST(root, INT_MIN, INT_MAX) << endl;
	BSTNode* n = BSTNode::Find(root, 1);
	assert(n == nullptr);
	n = BSTNode::Find(root, 40);
	assert(n != nullptr && n->mValue == 40);

	cout << "BST depth = " << BSTNode::Depth(root) << endl;
	int depth = 0;
	BSTNode::PrintDepth(root, depth);
	BSTNode::Destroy(root);
	assert(root == nullptr);
	return 0;
}

/*
// Binary Tree pre-order traversal
PreOrder(BinaryTree* root)
visit(root)
PreOrder(root->left)
Preorder(root-right)

// Binary tree in-order traversal
InOrder(BinryTree* root)
InOrder(root->left)
visit(root)
InOrder(root->right)
*/


