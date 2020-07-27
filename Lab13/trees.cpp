#include "trees.h"
#include <iostream>
using namespace std;



IntBinaryTree::IntBinaryTree()
{
  root = nullptr;
}

IntBinaryTree::IntBinaryTree(const IntBinaryTree &tree)
{
  root = copyTree(tree.root);
}

IntBinaryTree::~IntBinaryTree()
{
  destroySubTree(root);
}

//private
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
  if(nodePtr == nullptr)
    {
      nodePtr = newNode;
    }
  else if(newNode->value < nodePtr->value)
    {
      insert(nodePtr->left, newNode);
    }
  else
    {
      insert(nodePtr->right, newNode);
    }
}

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
  if(nodePtr)
    {
      if(nodePtr->left)
	{
	  destroySubTree(nodePtr->left);
	}

      if(nodePtr->right)
	{
	  destroySubTree(nodePtr->right);
	}

      delete nodePtr;
    }
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
  if(num < nodePtr->value)
    {
      deleteNode(num, nodePtr->left);
    }
  else if(num > nodePtr->value)
    {
      deleteNode(num, nodePtr->right);
    }
  else
    {
      makeDeletion(nodePtr);
    }
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
  TreeNode *tempNodePtr = nullptr;
  if(nodePtr == nullptr)
    {
      cout << "Cannot delete empty node." << endl;
    }
  else if(nodePtr->right == nullptr)
    {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;
      delete tempNodePtr;
    }
  else if(nodePtr->left == nullptr)
    {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;
      delete tempNodePtr;
    }
  else
    {
      tempNodePtr = nodePtr->right;
      while(tempNodePtr->left)
	{
	  tempNodePtr = tempNodePtr->left;
	}
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;
      delete tempNodePtr;
    }
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const //WORKS
{
  if(nodePtr == nullptr)
    {
      return;
    }

  displayInOrder(nodePtr->left);

  cout << nodePtr->value << " ";

  displayInOrder(nodePtr->right);
}

int IntBinaryTree::countLeafNodes(TreeNode *&nodePtr) //WORKS
{
  int count = 0;

  if(!nodePtr)
    {
      count = 0;
    }
  else if(nodePtr->left == nullptr && nodePtr->right == nullptr)
    {
      count = 1;
    }
  else
    {
      if(nodePtr->left)
	{
	  count += countLeafNodes(nodePtr->left);
	}
      if(nodePtr->right)
	{
	  count += countLeafNodes(nodePtr->right);
	}
    }

  return count;
}

int IntBinaryTree::getTreeHeight(TreeNode *nodePtr) //WORKS
{
  if(nodePtr == nullptr)
    {
      return 0;
    }
  else
    {
      int lDepth = getTreeHeight(nodePtr->left);
      int rDepth = getTreeHeight(nodePtr->right);

      if(lDepth > rDepth)
	{
	  return(lDepth + 1);
	}
      else
	{
	  return(rDepth + 1);
	}
    }
}

IntBinaryTree::TreeNode *IntBinaryTree::copyTree(TreeNode *nPtr) //SHOULD WORK
{
  if(nPtr == nullptr)
    {
      return nullptr;
    }
  TreeNode *temp;
  temp = new TreeNode;
  temp->value= nPtr->value;
  temp->left = copyTree(nPtr->left);
  temp->right = copyTree(nPtr->right);
  return temp;

}

IntBinaryTree IntBinaryTree::operator=(const IntBinaryTree &tree) //SHOULD WORK
{
  destroySubTree(root);
  root = copyTree(tree.root);
  return *this;
}

void IntBinaryTree::insertNode(int num)
{
  TreeNode *newNode = nullptr;

  newNode = new TreeNode;
  newNode->value = num;
  newNode->left = newNode->right = nullptr;

  insert(root, newNode);
}

bool IntBinaryTree::searchNode(int num)
{
  bool status = false;

  TreeNode *nodePtr = root;

  while(nodePtr)
    {
      if(nodePtr->value == num)
	{
	  status = true;
	}
      else if(num < nodePtr->value)
	{
	  nodePtr = nodePtr->left;
	}
      else
	{
	  nodePtr = nodePtr->right;
	}
    }

  return status;
}

void IntBinaryTree::remove(int num)
{
  deleteNode(num, root);
}

void IntBinaryTree::displayInOrder() const
{
  displayInOrder(root);
}

int IntBinaryTree::numLeafNodes()
{
  countLeafNodes(root);
}

int IntBinaryTree::treeHeight()
{
  getTreeHeight(root);
}
