// bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

		 using std::cout;
using std::endl;
using std::queue;

struct Node{
	int value;
	Node* left;
	Node* right;
	Node(const int& value) : value(value), left(nullptr), right(nullptr){}

};
class BST{
public:
	BST() :root(nullptr){}

	~BST(){
		deleteBST(root);
	}

	void add(const int &value){
		insert(root, value);
	}


	void remove(const int& value){
		remNode(root, value);
	}


	void search(const int &value){
		if (searchNode(root, value) == true){
			cout << value << " is found" << endl;
		}
		else{
			cout << value << " not found" << endl;
		}
	}


	void findmax(){
		cout << "Max: " << findMax(root)->value << endl;
	}

	void printPreorderDFS(){
		cout << "Preorder: ";
		preorderDFS(root);
		cout << endl;
	}
	void printInorderDFS(){
		cout << "Inorder: ";
		inorderDFS(root);
		cout << endl;
	}

	void printPostorderDFS(){
		cout << "Postorder: ";
		postorderDFS(root);
		cout << endl;
	}

	void printBFS(){
		cout << "BFS: ";
		BFS(root);
		cout << endl;
	}

	//----------------------------------private----------------------------------------//
private:

	Node* root;
	

	//delete tree (destructor)
	void deleteBST(Node* &root){
		if (root == nullptr){
			return;
		}
		deleteBST(root->left);
		deleteBST(root->right);
		delete root;
		root = nullptr;
	}

	

	//insert Node
	void insert(Node* &root, const int &value){
		if (root == nullptr){
			root = new Node(value);
			return ;
		}
		else if (value <= root->value){
			insert(root->left, value);
		}
		else{
			insert(root->right, value);
		}
		
	}

	//remove Node
	void remNode(Node* &root, const int &value){
		if (root == nullptr){
			return;
		}
		else if (value < root->value){
			remNode(root->left, value);
		}
		else if (value > root->value){
			remNode(root->right, value);
		}
		else{
			//1. no child
			if (root->left == nullptr && root->right == nullptr){
				delete root;
				root = nullptr;
			}
			//case 2: has right child
			else if (root->left == nullptr){
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			//case 3 : has left child
			else if (root->right == nullptr){
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			//case 4: has 2 children
			else{
				Node* temp = findMax(root->left); //maximum in right subtree
				root->value = temp->value; //swap values
				remNode(root->right, temp->value);//remove like in case 2
			}
		}
	}

	// find maximum in tree- function used in remNode
	Node*  findMax(Node* &root)const{
		if (root == nullptr){
			return root;
		}
		else if (root->right == nullptr){
			return root;
		}
		return findMax(root->right);
	}

	//search value
	bool searchNode(Node* root, const int &value)const{
		if (root == nullptr){
			return false;
		}
		else if (value == root->value){
			return true;
		}
		else if (value <= root->value){
			return searchNode(root->left, value);
		}
		else{
			return searchNode(root->right, value);
		}
	}

	//pretorder DFS
	void preorderDFS(Node* &root)const{
		if (root == nullptr){
			return;
		}
		cout << root->value << ' ';
		preorderDFS(root->left);
		preorderDFS(root->right);
	}

	//inorder DFS
	void inorderDFS(Node* &root)const{
		if (root == nullptr){
			return;
		}
		inorderDFS(root->left);
		cout << root->value << ' ';
		inorderDFS(root->right);
	}

	//postorder DFS
	void postorderDFS(Node* &root)const{
		if (root == nullptr){
			return;
		}
		postorderDFS(root->left);
		postorderDFS(root->right);
		cout << root->value << ' ';
	}

	//BFS without recursion
	void BFS(Node* &root){
		if (root == nullptr){
			return;
		}
		queue<Node*> Q;
		Q.push(root);
		while (!Q.empty())
		{
			Node* curr = Q.front();
			cout << curr->value << ' ';
			Q.pop();
			if (curr->left != nullptr && curr->right != nullptr){
				Q.push(curr->left);
				Q.push(curr->right);
			}
			else if (curr->left != nullptr){
				Q.push(curr->left);
			}
			else if (curr->right != nullptr){
				Q.push(curr->right);
			}
		}
	}



};

int main()
{
	BST t;
	t.add(25);          //				25	
	t.add(17);			//			17		  40
	t.add(40);			//		 13   19    38   45
	t.add(13);			//     10   18 21          46
	t.add(19);			//
	t.add(10);
	t.add(18);
	t.add(21);
	t.add(38);
	t.add(45);
	t.add(46);
	t.printBFS();
	t.printInorderDFS();
	t.remove(17);
	t.search(18);
	t.remove(46);//remove list
	t.printInorderDFS();
	t.add(46);//add again
	t.printInorderDFS();
	t.remove(45);//remove node with right child
	t.printInorderDFS();
	t.remove(13);//remove node with left child
	t.printInorderDFS();
	t.findmax();
	t.remove(19);//remove node with 2 children
	t.printInorderDFS();
	t.printInorderDFS();
	t.search(10);
	t.search(2);
	t.printPreorderDFS();
	t.printInorderDFS();
	t.printPostorderDFS();
	t.printBFS();
	return 0;
}



