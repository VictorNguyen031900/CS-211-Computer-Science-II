//tree.h

#include <iostream>

using namespace std;

class IntBinaryTree
{
 private:
  struct TreeNode
  {
    int value;
    TreeNode *left;
    TreeNode *right;
  };

  TreeNode *root;

  void insert(TreeNode *&, TreeNode *&);
  void deleteNode(int, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void destroySubTree(TreeNode *);
  //implement 4 functions
  void displayInOrder(TreeNode *) const;
  int countLeafNodes(TreeNode *&);
  int getTreeHeight(TreeNode *);
  TreeNode *copyTree(TreeNode *);

 public:
  IntBinaryTree();
  IntBinaryTree(const IntBinaryTree &); //implement function
  ~IntBinaryTree();

  void insertNode(int);
  bool searchNode(int);
  void remove(int);
  void displayInOrder() const;
  //implemnet 3 functions
  int numLeafNodes();
  int treeHeight();
  IntBinaryTree operator= (const IntBinaryTree &);
};
