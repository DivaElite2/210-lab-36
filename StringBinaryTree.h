// Specification file for the IntBinaryTree class
#ifndef STRINGBINARYTREE_H
#define STRINGBINARYTREE_H


#include <iostream>
#include <string>
using namespace std;
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
   void insert(TreeNode *&nodePtr, TreeNode *&newNode) {
      if (!nodePtr)
            nodePtr = newNode;
        else if (newNode->value < nodePtr->value)
            insert(nodePtr->left, newNode);
        else 
            insert(nodePtr->right, newNode);
   }

   void destroySubTree(TreeNode *nodePtr) {
      if (nodePtr) {
            destroySubTree(nodePtr->left);
            destroySubTree(nodePtr->right);
            delete nodePtr;
        }

   }
   void deleteNode(string str, TreeNode *&nodePtr) {
      if (!nodePtr) return;
        if (str < nodePtr->value)
            deleteNode(str, nodePtr->left);
        else if (str > nodePtr->value)
            deleteNode(str, nodePtr->right);
        else
            makeDeletion(nodePtr);

   }
   void makeDeletion(TreeNode *&nodePtr) {
      if (!nodePtr) return;
        TreeNode *tempNodePtr;
        if (!nodePtr->right) {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left;
            delete tempNodePtr;
        } else if (!nodePtr->left) {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        } else {
            tempNodePtr = nodePtr->right;
            while (tempNodePtr->left)
                tempNodePtr = tempNodePtr->left;
            tempNodePtr->left = nodePtr->left;
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }

   }
   void displayInOrder(TreeNode *nodePtr) const {
      if (nodePtr) {
            displayInOrder(nodePtr->left);
            cout << nodePtr->value << endl;
            displayInOrder(nodePtr->right);
        }
   }
   void displayPreOrder(TreeNode *nodePtr) const {
      if (nodePtr) {
            cout << nodePtr->value << endl;
            displayPreOrder(nodePtr->left);     
            displayPreOrder(nodePtr->right);
        }
   }
   void displayPostOrder(TreeNode *nodePtr) const {
      if (nodePtr) {
            displayPostOrder(nodePtr->left);    
            displayPostOrder(nodePtr->right);
            cout << nodePtr->value << endl;
        }
   }

public:
   // Constructor initializes the root to nullptr, indicating an empty tree.
   StringBinaryTree()     { root = nullptr; } // same now for strings

   // Destructor deallocates all nodes in the tree.
   ~StringBinaryTree()    { destroySubTree(root); }

   // Public interface for inserting, searching, and removing nodes (changed from int to string)
   void insertNode(string str) {
        TreeNode *newNode = new TreeNode;
        newNode->value = str;
        newNode->left = newNode->right = nullptr;
        insert(root, newNode);
    }

    bool searchNode(string str) {
        TreeNode *nodePtr = root;
        while (nodePtr) {
            if (nodePtr->value == str) return true;
            else if (str < nodePtr->value) nodePtr = nodePtr->left;
            else nodePtr = nodePtr->right;
        }
        return false;
    }

    void remove(string str) {
        deleteNode(str, root);
    }

    bool modify(string oldValue, string newValue) {
        if (!searchNode(oldValue)) {
            cout << "Error: '" << oldValue << "' not found.\n";
            return false;
        }
        if (searchNode(newValue)) {
            cout << "Error: '" << newValue << "' already exists.\n";
            return false;
        }
        remove(oldValue);
        insertNode(newValue);
        cout << "Modified '" << oldValue << "' to '" << newValue << "'\n";
        return true;
    }

    void displayInOrder() const { displayInOrder(root); }
    void displayPreOrder() const { displayPreOrder(root); }
    void displayPostOrder() const { displayPostOrder(root); }
};





#endif // STRINGBINARYTREE_H
