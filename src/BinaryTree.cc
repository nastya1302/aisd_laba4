#include <iostream>
#include <stdexcept>
#include <BinaryTree.h>

using namespace std;
using namespace nestea;

Node::Node() {
	value = 0;
	left = nullptr;
	right = nullptr;
}

Node::Node(int _value) {
	value = _value;
	left = nullptr;
	right = nullptr;
}

BinaryTree::BinaryTree() {
	root = nullptr;
}

//BinaryTree::BinaryTree(const BinaryTree& _root){}

//BinaryTree& BinaryTree::operator=(const BinaryTree& _root){}

BinaryTree::~BinaryTree(){
	if(!root)
		throw std::invalid_argument("BinaryTree::The tree is empty");
	delete_tree(root);
	root = nullptr;
}

void BinaryTree::print(){
	if (!root)
		throw std::invalid_argument("BinaryTree::The tree is empty");
	print_tree(root);
}

bool BinaryTree::insert(int key){
	if (!root) {
		root = new Node(key);
		return true;
	}
	else {
		Node* current = root;
		while (current) {
			if (current->value == key) {
				cout << "BinaryTree::An element with this value already exists.";
				return true;
			}
			else if (current->value < key) {
				if (current->right != nullptr)
					current = current->right;
				else {
					current->right = new Node(key);
					return true;
				}
			}
			else {
				if (current->left != nullptr)
					current = current->left;
				else {
					current->left = new Node(key);
					return true;
				}
			}
		}
	}
	return false;
}

//bool BinaryTree::contains(int key){}

//bool BinaryTree::erase(int key){}

//Node* BinaryTree::get_root(){}

void BinaryTree::delete_tree(Node* _root) {
	if (_root->left) delete_tree(_root->left);
	if (_root->right) delete_tree(_root->right);
	delete _root;
	_root = nullptr;
}

void BinaryTree::print_tree(const Node* _root) {
	cout << _root->value << " ";
	if(_root->left) print_tree(_root->left);
	if(_root->right) print_tree(_root->right);
}