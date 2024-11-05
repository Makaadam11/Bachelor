#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#pragma once

class AVLTree
{
private:
	struct Node
	{
		int element;
		Node* left;
		Node* right;
		int height;
	};

	Node* root;
	int currentsize, Maxsize;
	static void clear(Node*& node);

public:

	int getMaxsize(int size);
	int max(int a, int b);
	int height(Node*);
	
	AVLTree();
	AVLTree(const AVLTree & element);
	//AVLTree(AVLTree && element);
	~AVLTree();
	void DestroyHelper(Node*);
	const int& findMin() const;
	const int& findMax() const;
	Node* findMin1(Node* t) const;
	Node* findMax1(Node* t) const;

	bool contains(const int &element) const;
	bool contains1(const int &element, Node *t)const;
	Node* find(const int& k, Node* nptr)const;
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
	void remove(const int& element);
	void remove1(const int& element, Node*& t);
	Node* deleteNode(Node* root, int element);
	void printTreeInOrder(Node* t) const;
	void printTreePreOrder(Node* t) const;
	void printTreePostOrder(Node* t) const;
	Node* clone(Node* t) const;
	Node* insert1(Node* Node, int element);
	void insert(int element, Node* Node);
	Node* rightRotate(Node* t);
	Node* leftRotate(Node* t);
	int getBalance(Node* N);
	Node* newNode(int key);
	Node* getRoot()const;
	void clear() { clear(root); }

	AVLTree & operator=(const AVLTree& t);
	//AVLTree & operator=(AVLTree&& t);

	void print_dominant_operations();

};

#endif
