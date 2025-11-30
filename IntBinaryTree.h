// Specification file for the IntBinaryTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H


// The IntBinaryTree class manages a binary tree of integers.
class StringBinaryTree {
private:
   // TreeNode is a private structure for IntBinaryTree nodes.
   struct TreeNode {
      string value;         // changed from int to string
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   // root points to the topmost node of the tree.
   TreeNode *root;      

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(string, TreeNode *&); // changed to string
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:
   // Constructor initializes the root to nullptr, indicating an empty tree.
   StringBinaryTree()     { root = nullptr; } // same now for strings

   // Destructor deallocates all nodes in the tree.
   ~StringBinaryTree()    { destroySubTree(root); }

   // Public interface for inserting, searching, and removing nodes (changed from int to string)
   void insertNode(string);
   bool searchNode(string);
   void remove(string);

   // Public wrappers for tree traversal functions.
   void displayInOrder() const     {  displayInOrder(root); }
   void displayPreOrder() const    {  displayPreOrder(root); }
   void displayPostOrder() const   {  displayPostOrder(root); }
};



#endif // INTBINARYTREE_H
