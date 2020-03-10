/*
 * BSTree.h
 *
 * Nicole Vavrukh 301357534
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>

using namespace std;

class BSTree {
public:

	BSTree();
	BSTree(const BSTree &rbt); // Copy constructor
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string x, char y, int z);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string x, char y);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string x, char y);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string x, char y, string z, char a);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();

private:

	//Stores pointer to root value of entire Binary Search Tree
	Node * root;

	//Recursive function used for insert
	Node * insertTree(Node *node, Customer inserter);

	//Recursive function used for search
	Node * treeSearch(Node *node, Customer customer);

	//Recursive function used to find node's parent for remove
	Node * treeParentSearch(Node *node, Node *parent, Customer customer);

	//Recursive function for inOrderPrint
	void PrintTree(Node *node);

	//Recursive function used to remove internal nodes (not including root) in remove
	void InOrderSuccesorMovement(Node *node);

	//Recursive function used to remove root and external nodes in remove
	void eraseNode(Node *deleter, Node *parentdeleter);

	//Recursive function used to deep copy tree in copy contructor
	Node * recursiveCreate(Node *copy);

	//Recursive function used for delete
	void recursiveDelete(Node *node);

	//Recursve function used to add customers into vector for rangeSearch
	void vectorCustomersinRange(Node *node, Customer start, Customer end, vector<Customer> &customers);

};

#endif /* BSTREE_H_ */
