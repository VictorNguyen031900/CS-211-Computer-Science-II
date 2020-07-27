#include "trees.h"
#include <iostream>

using namespace std;

int main()
{
  IntBinaryTree tree;
  IntBinaryTree tree1;
  IntBinaryTree tree2;

  cout << "Height: " << tree.treeHeight() << endl;
  cout << endl;

  cout << "Inserting nodes." << endl;
  tree.insertNode(5);
  tree.insertNode(8);
  tree.insertNode(3);
  tree.insertNode(12);
  tree.insertNode(9);
  cout << endl;

  cout << "Here are the values in the tree: " << endl;
  tree.displayInOrder();
  cout << endl;

  cout << "Height: " << tree.treeHeight()<< endl;
  cout << endl;

  cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;

  cout << "Deleting 8..." << endl;
  tree.remove(8);
  cout << "Deleting 12..." << endl;
  tree.remove(12);
  cout << endl;

  cout << "Now, here are the nodes: " << endl;
  tree.displayInOrder();
  cout << endl;

  cout << "Height: " << tree.treeHeight() << endl;

  cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;

  tree1.insertNode(55);
  tree1.insertNode(5);
  tree1.insertNode(8);

  cout << endl << "Here are the nodes of tree1: " << endl;
  tree1.displayInOrder();
  cout << endl;

  tree2 = tree1;

  cout << "Now, her are the nodes of tree2: " << endl;
  tree2.displayInOrder();
  cout << endl;

  tree1.insertNode(10);
  tree1.insertNode(3);
  tree1.insertNode(12);

  cout << endl << "Here are the ndoes of tree1 afer adding 3 nodes: " << endl;
  tree1.displayInOrder();
  cout << endl;

  cout << endl << "Here are the nodes of tree2: " << endl;
  tree2.displayInOrder();

  IntBinaryTree tree3 = tree1;

  cout << "Now, here are the nodes of tree3: " << endl;
  tree3.displayInOrder();
  cout << endl;

  tree1.remove(5);

  cout << endl << "Here are the nodes of tree1 after removing node 5: " << endl;
  tree1.displayInOrder();

  cout << endl << "Now, Here are the nodes of tree3" << endl;
  tree3.displayInOrder();
  cout << endl;

  return 0;
}
