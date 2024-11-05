#include <cstdio>
#include <cstdlib>
#include<bits/stdc++.h>
#include<iostream>
#include <unistd.h>
#include "AVLTree.hpp"
using namespace std;

int dominant_operations = 0;

AVLTree:: Node* AVLTree::getRoot()const {
	return this->root;
}
int AVLTree:: getMaxsize(int size){
	this->Maxsize = size;
	return this->Maxsize;
}
int AVLTree:: max(int a, int b)
{
	dominant_operations++;
	return (a > b) ? a : b;
}
int AVLTree:: height(Node* N)
{
	if (N == NULL) {
		dominant_operations++;
		return 0;
	}
	dominant_operations++;
	return N->height;
}
AVLTree:: AVLTree() {
	
	this->root = NULL;
	this->currentsize = 0;
	this->Maxsize = 0;
}

AVLTree :: AVLTree(const AVLTree& element)
{
	root = clone(element.root);
}
/***
AVLTree::AVLTree(AVLTree&& element) {

}
***/
AVLTree::~AVLTree()
{
	DestroyHelper(root);
}
void AVLTree::DestroyHelper(Node* root) {
	if (root != NULL)
	{
		dominant_operations++;
		DestroyHelper(root->left);
		DestroyHelper(root->right);
		this->root = nullptr;
	}
}

const int& AVLTree:: findMin() const {
	return findMin1(root)->element;
}
const int& AVLTree::findMax() const {
	return findMax1(root)->element;
}
AVLTree:: Node* AVLTree :: findMin1(Node* t) const
{
	if (t == NULL) {
		dominant_operations++;
		return NULL;
	}
	else if (t->left == NULL) {
		dominant_operations++;
		return t;
	}
	else
		return findMin1(t->left);
}

AVLTree:: Node* AVLTree:: findMax1(Node* t) const
{
	if (t == NULL) {
		dominant_operations++;
		return NULL;
	}	
	else if (t->right == NULL) {
		dominant_operations++;
		return t;
	}
	else
		return findMax1(t->right);
}

bool AVLTree:: contains1(const int& element, Node* t)const {
	if (t == nullptr) {
		dominant_operations++;
		return false;
	}
	if (t->element == element) {
		dominant_operations++;
		return true;
	}
	else if (element <= t->element) {
		dominant_operations++;
		return find(element, t->left);
	}
	else return find(element,t->right);
}

bool AVLTree:: contains(const int& element)const {
	return contains1(element, root);
}

AVLTree:: Node* AVLTree::find(const int& k, Node* nptr)const {
	if (nptr == nullptr) {
		dominant_operations++;
		cerr << "key not found: " << k << endl;
		return nptr;
	}
	if (nptr->element == k) {
		dominant_operations++;
		return nptr;
	}
	if (k > nptr->element) {
		dominant_operations++;
		return find(k, nptr->right);
	}
	else return find(k, nptr->left);
}

bool AVLTree :: isEmpty() const {
	if (currentsize == 0)
	{
		dominant_operations++;
		return true;
	}
	return false;
}
bool AVLTree:: isFull() const {
	if (currentsize == Maxsize)
	{
		dominant_operations++;
		return true;
	}
	return false;
}
int AVLTree:: size() const {
	return currentsize;
}
void AVLTree:: remove(const int& element) {
	deleteNode(root, element);
}
void AVLTree::remove1(const int& element, Node*& t) {

	deleteNode(t, element);
}
AVLTree:: Node* AVLTree::deleteNode(Node* root, int element)
{
	if (root == NULL)
	{
		dominant_operations++;
		return root;
	}
	
	if (element < root->element) {
		dominant_operations++;
		root->left = deleteNode(root->left, element);
	}
	else if (element > root->element) {
		dominant_operations++;
		root->right = deleteNode(root->right, element);
	}
	else {

		if (root->left == NULL and root->right == NULL) {
			dominant_operations++;
			return NULL;
		}
			

		else if (root->left == NULL) {
			dominant_operations++;
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			dominant_operations++;
			Node* temp = root->left;
			free(root);
			return temp;
		}

		Node* temp = findMin1(root->right);

		root->element = temp->element;

		root->right = deleteNode(root->right, temp->element);
	}
	return root;
}
void AVLTree::printTreeInOrder(Node* root) const {
	if (root != NULL)
	{
		dominant_operations++;
		printTreeInOrder(root->left);
		std::cout << root->element << "-->";
		printTreeInOrder(root->right);
	}
}
void AVLTree :: printTreePreOrder(Node* root) const{
	if (root != NULL)
	{
		dominant_operations++;
		std::cout << root->element << "-->";
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}
void AVLTree::printTreePostOrder( Node* root) const
{
	if (root != NULL)
	{
		dominant_operations++;
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		cout << root->element << "-->";
	}
}
AVLTree::Node* AVLTree::clone(Node* T) const {
	if (T == NULL) {
		return NULL;
	}
	Node* p;
	p = new Node;
	p->element = T->element;
	p->left = clone(T->left);
	p->right = clone(T->right);
	return p;
}

AVLTree:: Node* AVLTree::rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;
 
	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;
 
	return x;
}
AVLTree:: Node* AVLTree::leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;
 
	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	return y;
}

int AVLTree::getBalance(Node* N)
{
	if (N == NULL) {
		dominant_operations++;
		return 0;
	}
	return height(N->left) - height(N->right);
}

AVLTree:: Node* AVLTree:: newNode(int key)
{
	Node* node = new Node();
	node->element = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
					  
	return(node);
}
void AVLTree::insert(int key, Node *root) {

	if (root == nullptr) {
		dominant_operations++;
		root = this->root;
	}
	currentsize++;
	this->root = insert1(this->root, key);
}

AVLTree:: Node* AVLTree::insert1(Node* node, int key)
{
	if (node == NULL) {
		dominant_operations++;
		return(newNode(key));
	}

	if (key < node->element) {
		dominant_operations++;
		node->left = insert1(node->left, key);
	}
	else if (key > node->element) {
		dominant_operations++;
		node->right = insert1(node->right, key);
	}
	else 
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right));

	int balance = getBalance(node);
 
	if (balance > 1 && key < node->left->element) {
		dominant_operations++;
		return rightRotate(node);
	}	
	if (balance < -1 && key > node->right->element){
		dominant_operations++;
		return leftRotate(node);
	}

	if (balance > 1 && key > node->left->element)
	{
		dominant_operations++;
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->element)
	{
		dominant_operations++;
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

void AVLTree:: clear(Node*& node) {
	if (!node) return;
	clear(node->left);
	clear(node->right);
	delete node;
	node = nullptr;
}

AVLTree& AVLTree::operator=(const AVLTree& other) {
	if (this != &other) {
		clear();
		root = clone(other.root);
	}
	return *this;
}

void AVLTree :: print_dominant_operations() {
	 cout << dominant_operations;
}


