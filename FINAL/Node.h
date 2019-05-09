//
//  Node.h : This header file contains both declarations and implementations of a node's methods.
//  462_Hotel
//
//  Created by Alex Liao on 2019/4/28.
//  Copyright © 2019年 Alex Liao. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <fstream>
#include <iostream>
using std::ostream;

// Tree class forward declarations: see DatabaseTree.h
template<typename AnyType> class DatabaseTree;

template <typename AnyType>
class Node {
   friend class DatabaseTree<AnyType>;         //   make Tree a friend
   friend ostream &operator<< (ostream &toConsole, const AnyType node);
private:
   AnyType node_val; // node_val = i.e. GuestAccount profile
   Node<AnyType>* left;
   Node<AnyType>* right;
public:
   // Constructor with arg
   Node(const AnyType &, Node<AnyType>* left = NULL, Node<AnyType>* right = NULL);
   
   // Constructor with no arg
   Node();
   
   AnyType get_Node() const; // return data in the node
   
   // Overloaded operators to compare node value.
   AnyType operator<   (const AnyType &rValue) const;
   AnyType operator>   (const AnyType &rValue) const;
   AnyType operator==  (const AnyType &rValue) const;
};

// Constructor with args
template<typename NodeType>
Node<NodeType>::Node(const NodeType &val, Node<NodeType>* left, Node<NodeType>* right) {
   node_val   = val;
   this->left = left;
   this->right = right;
}

// Constructor with no argt
template<typename NodeType>
Node<NodeType>::Node( ) {
   left  = NULL;
   right = NULL;
}

// Return a copy of the data in the node, which in our case, a GuestAccount object.
template<typename NodeType>
NodeType Node<NodeType>::get_Node() const {
   return node_val;
}

/* Following are overloaded comparison operators to compare any type of node value, which in our case is of type GuestAccount. Causes the overloaded comparison operators of the GuestAccount class to be invoked, which compares the userID attribute value of the GuestAccount.
 Parameter:
   - &rOperand: Of any type store in the node, which in our case is GuestAccount.
 Return: Invocation of the respected comparison operator, which invokes overloaded comparison operator of the GuestAccount class that which returns boolean value of the comparison result.
*/
template<typename NodeType>
NodeType Node<NodeType>::operator<(const NodeType &rOperand) const {
   return (node_val < rOperand.node_val);
}

template<typename NodeType>
NodeType Node<NodeType>::operator>(const NodeType &rOperand) const {
   return (node_val < rOperand.node_val);
}

template<typename NodeType>
NodeType Node<NodeType>::operator==(const NodeType &rOperand) const {
   return (node_val < rOperand.node_val);
}

#endif /* Node_h */
