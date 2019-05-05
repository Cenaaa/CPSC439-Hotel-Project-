//
//  DatabaseTree.h
//  462_Hotel
//
//  Created by Alex Liao on 2019/4/28.
//  Copyright © 2019年 Alex Liao. All rights reserved.
//

#ifndef DatabaseTree_h
#define DatabaseTree_h

#include "Node.h"
#include <fstream>
#include <iostream>
#include "GuestAccount.h"
using std::cout;
using std::endl;
using std::fstream;

template <typename NodeType>
class DatabaseTree {
private:
   Node<NodeType>* root;
   bool insert_Helper (Node<NodeType>* &, const NodeType &);
   bool search_Helper (Node<NodeType>* &, const NodeType &);
   NodeType retrieve_Helper(Node<NodeType>* &, const NodeType &);
   bool delete_Node_Helper (Node<NodeType>* &,   const NodeType &);
   void remove (Node<NodeType>* &);
   void make_empty_Helper (Node<NodeType>* &);
   void print_Tree_Helper (Node<NodeType>*);
   void read_tree_Helper (fstream &, Node<NodeType>*);
   void write_tree_Helper (fstream &, Node<NodeType>*);
   
public:
   DatabaseTree ();   // constructor with no arg
   bool insert (const NodeType &);
   bool search (const NodeType &);
   bool delete_Node (const NodeType &);
   NodeType retrieve(const NodeType &);
   bool isEmpty () const;
   void make_empty ();
   void print_Tree ();
   void print_Node (NodeType);
   void read_tree (fstream &);
   void write_tree (fstream &);
   ~DatabaseTree();   // destructor
};

template<typename NodeType> // Default constructor with no arg
DatabaseTree<NodeType>::DatabaseTree() { root = NULL; } // Set pointer to first node to NULL

template<typename NodeType>
bool DatabaseTree<NodeType>::insert(const NodeType &with_data) {
   return insert_Helper(root, with_data); // Insert a node into the Tree
}

template<typename NodeType>
bool DatabaseTree<NodeType>::insert_Helper(Node<NodeType>* &ptr, const NodeType &with_data) {
   if (!ptr) { ptr = new Node<NodeType>(with_data); } // Tree is empty, insert new node
   else if (with_data == ptr->node_val) {
      cout << "Duplicated value. Insert failed.\n\n"; // value already in tree
      return false;
   } else if (with_data < ptr->node_val) {
      return insert_Helper(ptr->left, with_data);      // insert in left subtree
   } else if (with_data > ptr->node_val) {
      return insert_Helper(ptr->right, with_data);      // insert in right subtree
   }
   return true;
}

// Retrieve node info from tree
template<typename NodeType>
bool DatabaseTree<NodeType>::search(const NodeType &with_ID) {
   return search_Helper(root, with_ID);
}

//   retrieve helper function
template<typename NodeType>
bool DatabaseTree<NodeType>::search_Helper(Node<NodeType>* &ptr, const NodeType &with_ID) {
   if (NULL != ptr) {
      if(with_ID == ptr->node_val) { return true; }
      else if (with_ID < ptr->node_val) { return search_Helper(ptr->left, with_ID); }
      else if (with_ID > ptr->node_val) { return search_Helper(ptr->right, with_ID); }
   } // Tree is empty, Retrieve failed
   return false;
}

template<typename NodeType>
NodeType DatabaseTree<NodeType>::retrieve(const NodeType &with_ID) {
   return retrieve_Helper(root, with_ID);
}

template<typename NodeType>
NodeType DatabaseTree<NodeType>::retrieve_Helper(Node<NodeType>* &ptr, const NodeType &with_ID) {
   if (NULL != ptr) {
      if(with_ID == ptr->node_val) { return ptr->node_val; }
      else if (with_ID < ptr->node_val) { return retrieve_Helper(ptr->left, with_ID); }
      else if (with_ID > ptr->node_val) { return retrieve_Helper(ptr->right, with_ID); }
   }
   return NULL;
}

// Delete a node value from the Tree, calls delete_Node_Helper to search node
template<typename NodeType>
bool DatabaseTree<NodeType>::delete_Node(const NodeType &with_Value) {
   return delete_Node_Helper(root, with_Value);
}

//Recursive delete helper
template<typename NodeType>
bool DatabaseTree<NodeType>::delete_Node_Helper(Node<NodeType>* &ptr, const NodeType &with_Value) {
   if (NULL == ptr) {
      cout << "Value not found.\n\n"; // Tree is empty
      return false;
   }
   if (with_Value == ptr->node_val) { remove(ptr); }
   else if (with_Value < ptr->node_val) { return delete_Node_Helper(ptr->left, with_Value); }
   else if (with_Value > ptr->node_val) { return delete_Node_Helper(ptr->right, with_Value); }
   return true;
}

// Utility function to delete node pointed to by ptr
template<typename NodeType>
void DatabaseTree<NodeType>::remove(Node<NodeType>* &ptr) {
   Node<NodeType>* candidate_node = ptr;
   Node<NodeType>* connector;
   if (NULL != ptr) {
      if (NULL == ptr->right) { ptr = ptr->left; } // When reach end of ptr's right kid.
      else if (NULL == ptr->left) { ptr = ptr->right; } // When reach end of ptr's left kid.
      else { // Node to delete has two children.
         // Move to node's right kid
         connector = ptr->right;
         // Find the smallest node in the right subtree - Go to left as far as possible
         while(NULL != connector->left) { connector = connector->left; }
         // Connect left subtree of original tree as left subtree of smallest node in right subtree
         connector->left = ptr->left;
         // Replace original tree with its right subtree
         ptr = ptr->right;
      }
      delete candidate_node;
   }
   cout <<"finishing delete Node..\n";
}

// Check if the Tree is empty?
template<typename NodeType>
bool DatabaseTree<NodeType>::isEmpty() const { return (NULL == root); }

// Delete entire tree
template<typename NodeType>
void DatabaseTree<NodeType>::make_empty() { make_empty_Helper(root); }

// Recursive delete tree helper
template<typename NodeType>
void DatabaseTree<NodeType>::make_empty_Helper(Node<NodeType>* &ptr) {
   if (NULL == ptr) { return; }
   make_empty_Helper(ptr->left);
   make_empty_Helper(ptr->right);
   delete ptr;
   ptr = NULL;
}

// Print tree contents
template<typename NodeType>
void DatabaseTree<NodeType>::print_Tree() {
   if (nullptr == root) { cout << "Database is empty." << endl; }
   else { printHelper(root); }
}

// Recursive print helper to print tree contents.
template<typename NodeType>
void DatabaseTree<NodeType>::print_Tree_Helper(Node<NodeType>* ptr) {
   if (nullptr == ptr) { return; }
   print_Tree_Helper (ptr->left);
   cout << ptr->node_val << endl;
   print_Tree_Helper (ptr->right);
}

template<typename NodeType>
void DatabaseTree<NodeType>::print_Node(const NodeType with_value) {
   if (retrieve_Helper(root, with_value)) {
      cout << with_value << endl;
   }
}

template<typename NodeType>
void DatabaseTree<NodeType>::read_tree(fstream &file_IO) {
   read_tree_Helper(file_IO, root);
}

template<typename NodeType>
void DatabaseTree<NodeType>::read_tree_Helper (fstream &file_IO, Node<NodeType>* ptr) {
   if (nullptr == ptr) { return; }
   file_IO.read(reinterpret_cast<char*>(&ptr->node_val), sizeof(ptr->node_val));
   cout << ptr->node_val;
   cout << endl;
   read_tree_Helper(file_IO, ptr->left);
   read_tree_Helper(file_IO, ptr->right);
}

template<typename NodeType>
void DatabaseTree<NodeType>::write_tree(fstream &file_IO) { write_tree_Helper(file_IO, root); }

template<typename NodeType>
void DatabaseTree<NodeType>:: write_tree_Helper (fstream &file_IO, Node<NodeType>* ptr) {
   if(nullptr == ptr) { return; }
   NodeType accountNode = ptr->node_val;
   file_IO.write(reinterpret_cast<char *>(&accountNode), sizeof(accountNode));
   cout << "Write patient node to tree\n";
   write_tree_Helper(file_IO, ptr->left);
   write_tree_Helper(file_IO, ptr->right);
}

// Destructor
template<typename NodeType>
DatabaseTree<NodeType>::~DatabaseTree() { make_empty(); }

#endif /* DatabaseTree_h */
