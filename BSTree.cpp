/*
 * BSTree.cpp
 *
 * Nicole Vavrukh 301357534
 *      
 */

#include "BSTree.h"


BSTree::BSTree() {

	//Default Constructor makes root empty/NULL
	root = NULL;
}

BSTree::BSTree(const BSTree & rbt){

	//Copy Contructor delegates to recursive private function if copy root is not NULL
	root=NULL;
	if(rbt.root==NULL){
		return;
	}
	recursiveCreate(rbt.root);
}


BSTree::~BSTree() {

	//Destructor delegates to recursive private function
	recursiveDelete(root);
}


bool BSTree::insert(string x, char y, int z) {

	//Place values in arguments into customer object
	Customer customer(x, y, z);

	//If root is NULL, tree is empty so make customer node the root and return
	if (root==NULL){
		Node *insertionNode = new Node(NULL, NULL, customer);
		root = insertionNode;
		return true;
	}

	//Otherwise delegate insertion to private recursive function
	insertTree(root, customer);
	return true;
	
}


bool BSTree::remove(string x, char y) {
	
	//Create a customer with same name but no balance, to search tree for
	Customer customer(x, y, 0);

	//Search for customer; if not found remove returns false
	Node *result = treeSearch(root,customer);
	if (result==NULL || result->customer != customer) {
		return false;
	}

	//If found, search for parent and call private function to delete node, return true
	Node *parentResult = treeParentSearch(root,NULL, customer);
	eraseNode(result,parentResult);
	return true;
}


bool BSTree::search(string x, char y) {

	//Create a customer with same name but no balance, to search tree for
	Customer customer(x, y, 0);

	//Search for customer using private recusive function
	Node *result = treeSearch(root,customer);

	//If found return true, otherwise return false
	if (result!=NULL && result->customer == customer) {
		return true;
	}
	return false;
}


vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {

	//Create customer objects for start and end of range of search
	Customer start(x, y, 0);
	Customer end (z, a, 0);

	//Create vector to store custoemrs in this range
	vector<Customer> customers;

	//If start value is greater than end value, nothing can be added to vector
	//Therefore return empty vector
	if (start >= end) {
		return customers;
	}

	//Delegate inserts into vector to recursive private function and return vector
	vectorCustomersinRange(root, start, end, customers);
	return customers;
}


void BSTree::inOrderPrint() {

	//Delegates to private recursive function
	PrintTree(root);
}

Node* BSTree::insertTree(Node *node, Customer inserter){

	//Base case; Makes new node and returns it
	if (node == NULL) {
		Node *insertionNode = new Node(NULL, NULL, inserter);
		return insertionNode;
	}

	//If customer is less than node's customer, continue on left path
	if (inserter < node->customer) {
		node->left=insertTree(node->left, inserter);
	}

	//If customer is greater than or equal to node's customer, continue on right path
	else {
		node->right = insertTree(node->right, inserter);
	}

	//Returns node if node unchanged
	return node;
}

Node * BSTree::treeSearch(Node *node, Customer customer){
	
	//Base case; if node is NULL, external or customer's found, return node
	if (node==NULL || node->isExternal() || node->customer ==customer) {
		return node;
	}

	//if node's customer is bigger than the customer searching for, descend left
	if (node->customer >= customer) {
		return treeSearch(node->left, customer);
	}

	//Otherwise, node's customer is less that what seraching for so descend right
	return treeSearch(node->right, customer);
}

Node * BSTree::treeParentSearch(Node *node, Node *parent, Customer customer){

	//if node is NULL, return NULL since customer is not in Tree
	if (node==NULL){
		return NULL;
	}

	//If customer found in tree, return parent, which is its parent
	if(node->customer==customer){
		return parent;
	}

	//If node's customer is greater than searching customer, go left
	if (node->customer > customer) {
		return treeParentSearch(node->left,node, customer);
	}

	//Otherwise go right
	return treeParentSearch(node->right,node, customer);
}

void BSTree::PrintTree(Node *node){

	//Base case; If node is NULL do nothing
	if (node == NULL) {
		return;
	}

	//Recusively print left side
	PrintTree(node->left); 
	
	//Print node's customer
	cout << node->customer << "\n";

	//Recusively print right side
	PrintTree(node->right);
}

void BSTree::InOrderSuccesorMovement(Node *node){
	
	//Make parent node, and current node the right child
	Node *parent = node;
	Node *curr = node->right;

	//If left is NULL, curr is the succesor, move and delete accordingly
	if (curr->left == NULL) {
		node->customer = curr->customer;
		parent->right = curr->right;
		delete curr;
		return;
	}

	//Move curr and parent to continue search for in order succesor
	curr = curr->left;
	parent = node->right;

	//While current is not the in oder succesor, move parent and curr left
	while (curr->left!= NULL) {
		curr = curr->left;
		parent = parent->left;
	}
	
	//move data to proper spots and delete
	node->customer = curr->customer;
	parent->left = curr->right;
	delete curr;
	return;
}

void BSTree::eraseNode(Node *deleter, Node *parentDeleter){

	//if deleter is the root special case
	if (deleter==root){

		//if root is external, its only elemnt, delete it and make root NULL
		if(deleter->isExternal()){
			delete deleter;
			root=NULL;
			return;
		}

		//if right side doesnt exist, delete and make root the left child
		if(deleter->right==NULL){
			root=deleter->left;
			delete deleter;
			return;
		}

		//if left side doesnt exist, delete and make root the right child
		if(deleter->left==NULL){
			root=deleter->right;
			delete deleter;
			return;
		}
	}

	//If deleter is external, make its parent's pointer to it NULL and delete it
	if (deleter->isExternal()) {
		if (deleter==parentDeleter->right){
			parentDeleter->right=NULL;
		}
		else{
			parentDeleter->left=NULL;
		}
		delete deleter;
		return;
	}

	//If deleter has no right child, parent's pointer changes to deleter's left
	if (deleter->right == NULL) {
		if (deleter==parentDeleter->right){
			parentDeleter->right=deleter->left;
		}
		else{
			parentDeleter->left=deleter->left;
		}
		delete deleter;
		return;
	}

	//If deleter has no left child, parent's pointer changes to deleter's right
	if (deleter->left == NULL) {
		if (deleter==parentDeleter->right){
			parentDeleter->right=deleter->right;
		}
		else{
			parentDeleter->left=deleter->right;
		}
		delete deleter;
		return;
	}

	//Otherwise this is internal node where succesor must be found, delegate to private function
	InOrderSuccesorMovement(deleter);
	return;
}

Node * BSTree::recursiveCreate(Node *copy){

	//Base Case; if copy is NULL return NULL
	if (copy == NULL) {
		return NULL;
	}

	//Create a new node with same info as copyRoot
	Node *node = new Node(NULL, NULL, copy->customer);

	//If tree has NULL root, node become new root
	if (root==NULL){
		root=node;
	}

	//Recursively make node's left and right descendants and return node
	node->left = recursiveCreate(copy->left);
	node->right = recursiveCreate(copy->right);
	return node;
}

void BSTree::recursiveDelete(Node *node){

	//Base Case; if node is NULL return
	if (node==NULL){
		return;
	}

	//Recursively delete node's descendants then node itself
	recursiveDelete(node->left);
	recursiveDelete(node->right);
	delete node;
}

void BSTree::vectorCustomersinRange(Node *node, Customer start, Customer end, vector<Customer> &customers){
	
	//Base Case; if node is NULL simply return
	if (node == NULL) {
		return;
	}

	//Recursively add relevent customers from left side
	vectorCustomersinRange(node->left, start, end, customers);

	//If node' customer is in range of [start, end], add it to vector
	if (node->customer >= start && node->customer <= end) {
		//cout << "insert " << root->customer <<"\n";
		customers.push_back(node->customer);
	}

	//Recursively add relevent customers from left side
	vectorCustomersinRange(node->right, start, end, customers);
}


