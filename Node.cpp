/*
 * Node.cpp
 *
 * Nicole Vavrukh 301357534
 *      
 */

#include "Node.h"

//Sets left pointer to l, right pointer to r and customer to c
Node::Node(Node * l, Node * r, Customer c)
	: left(l), right(r), customer(c) {
 }

//Sets left and right pointers to NULL
Node::~Node(){
		left=NULL;
		right=NULL;
}


//Returns true if children are both NULL and is therefore a leaf
bool Node::isExternal(){
	if (left == NULL && right == NULL) {
		return true;
	}
	return false;
}
