//
//  Node.h
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

template<typename NodeType> class DatabaseTree;   // Tree class forward declarations: see DatabaseTree.h

template <typename NodeType>
class Node {
   friend class DatabaseTree<NodeType>;         //   make Tree a friend
   friend ostream &operator<< (ostream &toConsole, const NodeType node);
private:
   NodeType node_val;               //   node_val = i.e. GuestAccount profile
   Node<NodeType>* left;
   Node<NodeType>* right;
public:
   // Constructor with arg
   Node(const NodeType &, Node<NodeType>* left = NULL, Node<NodeType>* right = NULL);
   
   // Constructor with no arg
   Node();
   
   NodeType get_Node() const;         //   return data in the node
   NodeType operator<   (const NodeType &rValue) const;
   NodeType operator>   (const NodeType &rValue) const;
   NodeType operator==  (const NodeType &rValue) const;
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

// Return a copy of the data in the node
template<typename NodeType>
NodeType Node<NodeType>::get_Node() const {
   return node_val;
}

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
