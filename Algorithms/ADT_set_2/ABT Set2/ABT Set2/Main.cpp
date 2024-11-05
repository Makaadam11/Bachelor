// C++ implementation of the approach
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
using namespace std;

// Structure to implement a node of a BST
template <typename T>
struct Node {

	// The data content of the node
	T data;

	// Link to the left child
	Node* left;

	// Link to the right child
	Node* right;

public:
	// Function to print the inorder
	// traversal of the BST
	void inorder(Node* r)
	{
		if (r == NULL) {
			return;
		}
		inorder(r->left);
		cout << r->data << " ";
		inorder(r->right);
	}

	/*
		Function to check if BST contains a node
		with the given data

		@param r pointer to the root node
		@param d the data to search
		@return 1 if the node is present else 0
	*/
	int containsNode(Node* r, T d)
	{
		if (r == NULL) {
			return 0;
		}
		int x = r->data == d ? 1 : 0;
		return x | containsNode(r->left, d) | containsNode(r->right, d);
	}

	/*
		Function to insert a node with
		given data into the BST

		@param r pointer to the root node
		@param d the data to insert
		@return pointer to the root of the resultant BST
	*/
	Node* insert(Node* r, T d)
	{

		// Add the node when NULL node is encountered
		if (r == NULL) {
			Node<T>* tmp = new Node<T>;
			tmp->data = d;
			tmp->left = tmp->right = NULL;
			return tmp;
		}

		// Traverse the left subtree if data
		// is less than the current node
		if (d < r->data) {
			r->left = insert(r->left, d);
			return r;
		}

		// Traverse the right subtree if data
		// is greater than the current node
		else if (d > r->data) {
			r->right = insert(r->right, d);
			return r;
		}
		else
			return r;
	}
};

// Class to implement a Set using BST
template <typename T>
class Set {

	// Pointer to the root of the
	// BST storing the set data
	Node<T>* root;

	// The number of elements in the set
	int size;

public:
	// Default constructor
	Set()
	{
		root = NULL;
		size = 0;
	}

	// Copy constructor
	Set(const Set& s)
	{
		root = s.root;
		size = s.size;
	}

	/*
		Function to Add an element to the set

	*/
	void add(const T data)
	{
		if (!root->containsNode(root, data)) {
			root = root->insert(root, data);
			size++;
		}
	}

	Set popAll( Set& B)
	{
		return (*this - B);
	}

	Set pop(Set& B)
	{
		return (*this - B);
	}

	/*
		Function to compute the union of two sets
	*/
	Set unionSet(Set& s)
	{
		Set<T> res;

		// Second set is returned
		// if first set is empty
		if (root == NULL)
			return res;

		// First set is returned
		// if second set is empty
		if (s.root == NULL)
			return *this;

		// The elements of the first set
		// are added to the resultant set
		stack<Node<T>*> nodeStack;
		nodeStack.push(root);

		// Preorder traversal of the BST
		while (!nodeStack.empty()) {
			Node<T>* node;
			node = nodeStack.top();
			nodeStack.pop();

			// The data is added to the resultant set
			res.add(node->data);

			if (node->right)
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}

		// The elements of the second set
		// are added to the resultant set
		stack<Node<T>*> nodeStack1;
		nodeStack1.push(s.root);

		while (!nodeStack1.empty()) {
			Node<T>* node;
			node = nodeStack1.top();
			nodeStack1.pop();

			res.add(node->data);

			if (node->right)
				nodeStack1.push(node->right);
			if (node->left)
				nodeStack1.push(node->left);
		}

		return res;
	}

	/**
		Computes the intersection of two sets

		@param s the set to find intersection with
		@return the intersection set
	*/
	Set intersectionSet(Set& s)
	{
		Set<T> res;
		stack<Node<T>*> nodeStack;
		nodeStack.push(root);

		while (!nodeStack.empty()) {
			Node<T>* node;
			node = nodeStack.top();
			nodeStack.pop();
			if (s.contains(node->data)) {
				res.add(node->data);
			}
			if (node->right)
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}
		return res;
	}


	Set operator-(Set& s)
	{
		Set<T> res;
		stack<Node<T>*> nodeStack;
		nodeStack.push(this->root);

		while (!nodeStack.empty()) {
			Node<T>* node;
			node = nodeStack.top();
			nodeStack.pop();
			if (!s.contains(node->data)) {
				res.add(node->data);
			}
			if (node->right)
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}
		return res;
	}

	bool operator==(Set& s)
	{
		if (s.getSize() != size) {
			return false;
		}
		stack<Node<T>*> nodeStack;
		nodeStack.push(this->root);

		while (!nodeStack.empty()) {
			Node<T>* node;
			node = nodeStack.top();
			nodeStack.pop();
			if (!s.contains(node->data)) {
				return false;
			}
			if (node->right)
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}
		return true;
	}

	T* toArray()
	{
		T* A = new T[size];
		int i = 0;
		stack<Node<T>*> nodeStack;
		nodeStack.push(this->root);

		while (!nodeStack.empty()) {
			Node<T>* node;
			node = nodeStack.top();
			nodeStack.pop();

			A[i++] = node->data;

			if (node->right)
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}
		return A;
	}

	/*
		Function to check whether the set contains an element

		@param data the element to search
		@return relut of check
	*/
	bool contains(T data)
	{
		return root->containsNode(root, data) ? true : false;
	}

	// Function to print the contents of the set
	void displaySet()
	{
		cout << "{ ";
		root->inorder(root);
		cout << "}" << endl;
	}

	/*
		Function to return the current size of the Set

		@return size of set
	*/
	int getSize()
	{
		return size;
	}
};

// Driver code
int main()
{


	//====================================================================== STRING

	Set<string> A1;
	string S[3];

	cout << "Wpisz 3 wyrazy do zbioru A (wpisz wyraz i nacisnij enter): ";
	for (size_t i = 0; i < 3; i++)
	{
		cin >> S[i];
		A1.add(S[i]);
	}

	// Add elements to Set A

	// Display the contents of Set A
	cout << "A = ";
	A1.displaySet();


	// Check if Set A contains some elements
	cout << "\n A " << (A1.contains("Ala") ? "isMember"
		: "isnt a member")
		<< " Ala" << endl;
	cout << "\n A " << (A1.contains("ma") ? "isMember"
		: "isnt a member")
		<< " ma" << endl;
	cout << endl;

	Set<string> B1;
	string S1[3];

	cout << "Wpisz 3 wyrazy do zbioru B (wpisz wyraz i nacisnij enter): ";
	for (size_t i = 0; i < 3; i++)
	{
		cin >> S1[i];
		B1.add(S1[i]);
	}

	
	cout << "B = ";
	B1.displaySet();


	// Set F contains the difference
	// of the Sets A and B
	Set<string> F1 =( A1 - B1 );
	Set<string> F2 = (B1 - A1);
	Set<string> F3 = F1.unionSet(F2);
	cout << "A - B = ";
	F3.displaySet();
	cout << endl;

	// Set D contains the union
	// of the Sets A and B
	Set<string> D1 = A1.unionSet(B1);
	cout << "A union B = ";
	D1.displaySet();
	cout << endl;

	// Set E contains the intersection
	// of the Sets A and B
	Set<string> E1 = A1.intersectionSet(B1);
	cout << "A intersection B = ";
	E1.displaySet();
	cout << endl;

	cout << "Wpisz liczbe jaka chcesz usunac ze zbioru B (wpisz liczbe i nacisnij enter): ";

	string minus;
	cin >> minus;
	Set<string> M1;
	M1.add(minus);

	B1 = B1.pop(M1);
	cout << "pop B = ";
	B1.displaySet();

	A1 = A1.popAll(B1);
	cout << "popALL A - B = ";
	A1.displaySet();

	//====================================================================== INT

	// Create Set A
	Set<int> A;
	int T[5];

	cout << "Wpisz 4 liczby do zbioru A (wpisz liczbe i nacisnij enter): ";
	for (size_t i = 0; i < 4; i++)
	{
		cin >> T[i];
		A.add(T[i]);
	}

	
	cout << "A = ";
	A.displaySet();
	

	// Check if Set A contains some elements
	cout <<"\n A " << (A.contains(3) ? "isMember"
		: "isnt a member")
		<< " 3" << endl;
	cout <<"\n A " << (A.contains(4) ? "isMember"
		: "isnt a member")
		<< " 4" << endl;
	cout << endl;

	// Create Set B
	Set<int> B;

	// Insert elements to Set B
	int T1[5];

	cout << "Wpisz 4 liczby do zbioru B (wpisz liczbe i nacisnij enter): ";
	for (size_t i = 0; i < 4; i++)
	{
		cin >> T1[i];
		B.add(T1[i]);
	}

	// Display the contents of Set B
	cout << "B = ";
	B.displaySet();
	


	// Set F contains the difference
	// of the Sets A and B
	Set<int> F = A - B;
	Set<int> F4 = (B - A);
	Set<int> F5 = F.unionSet(F4);
	cout << "A - B = ";
	F5.displaySet();
	cout << endl;

	// Set D contains the union
	// of the Sets A and B
	Set<int> D = A.unionSet(B);

	cout << "A union B = ";
	D.displaySet();
	cout << endl;

	// Set E contains the intersection
	// of the Sets A and B
	Set<int> E = A.intersectionSet(B);
	cout << "A intersection B = ";
	E.displaySet();
	cout << endl;

	cout << "Wpisz liczbe jaka chcesz usunac ze zbioru B (wpisz liczbe i nacisnij enter): ";
	
	int minus1;
	cin >> minus1;
	Set<int> M;
	M.add(minus1);

	B = B.pop(M);
	cout << "pop B = ";
	B.displaySet();

	A = A.popAll(B);
	cout << "popALL A - B = ";
	A.displaySet();

	//===============================================================



	cout << endl;
	
	return 0;
}
