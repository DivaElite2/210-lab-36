#include <iostream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

StringBinaryTree::StringBinaryTree() {
    root = nullptr;
}

StringBinaryTree::~StringBinaryTree() {
    destroySubTree(root);
}

void StringBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);
   else 
      insert(nodePtr->right, newNode);
}

void StringBinaryTree::insertNode(string str) {
   TreeNode *newNode = new TreeNode;
   newNode->value = str;
   newNode->left = newNode->right = nullptr;
   insert(root, newNode);
}

void StringBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}

bool StringBinaryTree::searchNode(string str) {
   TreeNode *nodePtr = root;
   while (nodePtr) {
      if (nodePtr->value == str)
         return true;
      else if (str < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

void StringBinaryTree::remove(string str) {
   deleteNode(str, root);
}

void StringBinaryTree::deleteNode(string str, TreeNode *&nodePtr) {
   if (!nodePtr) return;
   if (str < nodePtr->value)
      deleteNode(str, nodePtr->left);
   else if (str > nodePtr->value)
      deleteNode(str, nodePtr->right);
   else
      makeDeletion(nodePtr);
}

void StringBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   TreeNode *tempNodePtr;
   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
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


bool StringBinaryTree::modify(string oldValue, string newValue) {
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

void StringBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

void StringBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

void StringBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}


void StringBinaryTree::displayInOrder() const {
    displayInOrder(root);
}

void StringBinaryTree::displayPreOrder() const {
    displayPreOrder(root);
}

void StringBinaryTree::displayPostOrder() const {
    displayPostOrder(root);
}