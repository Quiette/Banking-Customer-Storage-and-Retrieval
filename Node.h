/*
 * Node.h
 *
 * Nicole Vavrukh 301357534
 *      
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
	Node(Node *l, Node *r, Customer c);
	~Node();

	//Friends
	friend class BSTree;

private:
	Node *left;
	Node *right;
	Customer customer;
	bool isExternal();
};


#endif /* NODE_H_ */
