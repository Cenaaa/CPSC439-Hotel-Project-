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

template <typename AnyType>
class DatabaseTree {
private:
   Node<AnyType>* root;
   // Follwing are helper functions to access each node in the tree.
   bool insert_Helper (Node<AnyType>* &, const AnyType &);
   bool search_Helper (Node<AnyType>* &, const AnyType &);
   AnyType retrieve_Helper(Node<AnyType>* &, const AnyType &);
   bool delete_Node_Helper (Node<AnyType>* &,   const AnyType &);
   void remove (Node<AnyType>* &);
   void make_empty_Helper (Node<AnyType>* &);
   void print_Tree_Helper (Node<AnyType>*);
   
public:
   DatabaseTree ();   // constructor with no arg
   
   // Following are utility functions to access & modify the tree.
   bool insert (const AnyType &);
   bool search (const AnyType &);
   bool delete_Node (const AnyType &);
   AnyType retrieve(const AnyType &);
   bool isEmpty () const;
   void make_empty ();
   void print_Tree ();
   void print_Node (AnyType);
   ~DatabaseTree();   // destructor
};

template<typename AnyType> // Default constructor with no arg
DatabaseTree<AnyType>::DatabaseTree() { root = NULL; } // Set pointer to first node to NULL

/* insert(const AnyType &)
   - Utility to insert a node of any type, which in our case of a GuestAccount, into the tree.
 Parameter:
   - with_data: Of type GuestAccount.
 Return: A call to the helper function of this method.
*/
template<typename AnyType>
bool DatabaseTree<AnyType>::insert(const AnyType &with_data) {
   return insert_Helper(root, with_data);
}

/* insert_Helper(Node<AnyType>*, const AnyType &)
   - Helper for the insert utility to access the nodes of, and insert a new node into, the tree.
 Parameter:
   - &ptr: A pointer to the node of the tree, of type any, which in our case is GuestAccount.
   - &with_data: Of any type, which in our case is GuestAccount - to be inserted into the tree.
*/
template<typename AnyType>
bool DatabaseTree<AnyType>::insert_Helper(Node<AnyType>* &ptr, const AnyType &with_data) {
   if (!ptr) { ptr = new Node<AnyType>(with_data); } // Tree is empty, insert new node
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

/* search(const AnyType &)
   - Utility to allow search for a matching node in the tree.
 Parameter:
   - with_ID: A node of any type, which in our case is GuestAccount.
 Return: Call to the helper of this method.
*/
template<typename AnyType>
bool DatabaseTree<AnyType>::search(const AnyType &with_ID) {
   return search_Helper(root, with_ID);
}

/* search_Helper(Node<AnyType>* &, const AnyType &)
   - Helper for the serch utility to recursively traverse each node in the tree searching for node with matching value, which is the ID of the GuestAccount.
 Parameter:
   - &ptr: A pointer to the node of the tree, of any type, which in our case is GuestAccount.
   - &with_ID: The node to be matched, of any type, which in our case is GuestAccount.
 Return: a boolean value of the search result.
*/
template<typename AnyType>
bool DatabaseTree<AnyType>::search_Helper(Node<AnyType>* &ptr, const AnyType &with_ID) {
   if (NULL != ptr) {
      if(with_ID == ptr->node_val) { return true; }
      else if (with_ID < ptr->node_val) { return search_Helper(ptr->left, with_ID); }
      else if (with_ID > ptr->node_val) { return search_Helper(ptr->right, with_ID); }
   } // Tree is empty, Retrieve failed
   return false;
}

/* retrieve(const AnyType &)
   - Utility to retrieves the value stored in the node from tree, which in our case is GuestAccount.
 Parameter:
   - with_ID: The comparison node whose ID is to be matched against nodes in the tree.
 Return: A call to the helper of this method.
*/
template<typename AnyType>
AnyType DatabaseTree<AnyType>::retrieve(const AnyType &with_ID) {
   return retrieve_Helper(root, with_ID);
}

/* retrieve_Helper(Node<AnyType>* &, const AnyType &):
   - Helper for the retrieve utility.
 Parameter:
   - &ptr: A pointer to the node of the tree, of any type, which in our case is GuestAccount.
   - &with_ID: The comparison node whose ID is to be matched against other nodes in the tree.
 Return: If a match is found, return the value of the node, which in our case is GuestAccount.
         Else, return NULL.
*/
template<typename AnyType>
AnyType DatabaseTree<AnyType>::retrieve_Helper(Node<AnyType>* &ptr, const AnyType &with_ID) {
   if (NULL != ptr) {
      if(with_ID == ptr->node_val) { return ptr->node_val; }
      else if (with_ID < ptr->node_val) { return retrieve_Helper(ptr->left, with_ID); }
      else if (with_ID > ptr->node_val) { return retrieve_Helper(ptr->right, with_ID); }
   }
   return NULL;
}


/* delete_Node(const AnyType &):
   - Utility to delete a node with certain value from the Tree, calls delete_Node_Helper to search for the node.
 Parameter:
   - &with_Value: A node of any type, which in our case is GuestAccount, to be compared against other nodes in the tree.
 Return: A call to the helper of this method.
*/
template<typename AnyType>
bool DatabaseTree<AnyType>::delete_Node(const AnyType &with_Value) {
   return delete_Node_Helper(root, with_Value);
}

/* delete_Node_Helper(Node<AnyType>* &, const AnyType &):
   - Helper for the delete_Node utility to Recursively search for the matching node in the tree.
 Parameter:
   - &ptr: A pointer to the node in the tree.
   -&with_Value: A node of any type, which in our case is GuestAccount, to be compared against other nodes in the tree.
 Return: A boolean value of the seach result.
*/
template<typename AnyType>
bool DatabaseTree<AnyType>::delete_Node_Helper(Node<AnyType>* &ptr, const AnyType &with_Value) {
   if (NULL == ptr) {
      cout << "Value not found.\n\n"; // Tree is empty
      return false;
   }
   if (with_Value == ptr->node_val) { remove(ptr); }
   else if (with_Value < ptr->node_val) { return delete_Node_Helper(ptr->left, with_Value); }
   else if (with_Value > ptr->node_val) { return delete_Node_Helper(ptr->right, with_Value); }
   return true;
}

/* remove(Node<AnyType>* &):
   - A sub-helper for the delete_Node_Helper to remove a node pointed to by ptr from the tree.
 Parameter:
   - &ptr: A pointer to the node to be deleted from the tree.
 Return: None.
*/
template<typename AnyType>
void DatabaseTree<AnyType>::remove(Node<AnyType>* &ptr) {
   Node<AnyType>* candidate_node = ptr;
   Node<AnyType>* connector;
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
template<typename AnyType>
bool DatabaseTree<AnyType>::isEmpty() const { return (NULL == root); }

// Empty the entire tree.
template<typename AnyType>
void DatabaseTree<AnyType>::make_empty() { make_empty_Helper(root); }

// Recursive emptying tree helper
template<typename AnyType>
void DatabaseTree<AnyType>::make_empty_Helper(Node<AnyType>* &ptr) {
   if (NULL == ptr) { return; }
   make_empty_Helper(ptr->left);
   make_empty_Helper(ptr->right);
   delete ptr;
   ptr = NULL;
}

// Print contents of the entire tree.
template<typename AnyType>
void DatabaseTree<AnyType>::print_Tree() {
   if (nullptr == root) { cout << "Database is empty." << endl; }
   else { printHelper(root); }
}

// Recursive print helper to print tree contents.
template<typename AnyType>
void DatabaseTree<AnyType>::print_Tree_Helper(Node<AnyType>* ptr) {
   if (nullptr == ptr) { return; }
   print_Tree_Helper (ptr->left);
   cout << ptr->node_val << endl;
   print_Tree_Helper (ptr->right);
}

// Prints the value stored in a certain node, which in our case is content of GuestAccount.
template<typename AnyType>
void DatabaseTree<AnyType>::print_Node(const AnyType with_value) {
   if (retrieve_Helper(root, with_value)) {
      cout << with_value << endl;
   }
}

// Destructor
template<typename AnyType>
DatabaseTree<AnyType>::~DatabaseTree() { make_empty(); }

#endif /* DatabaseTree_h */
