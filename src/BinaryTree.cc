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

BinaryTree::BinaryTree(const BinaryTree& _bintree){
	root = copy_tree(_bintree.root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& _bintree){
	delete_tree(root);
	root = copy_tree(_bintree.root);
	return *this;
}

BinaryTree::~BinaryTree(){
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
				//cout << "BinaryTree::An element with this value already exists.";
				return false;
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

bool BinaryTree::contains(int key){
	if (find_node(root, key))
		return true;
	return false;
}

bool BinaryTree::erase(int key){
	if (erase_node(root, key))
		return true;
	return false;
}

Node* BinaryTree::erase_node(Node*& _root, int key){
	if (!_root || !contains(key))
		return nullptr;
	else if (_root->value > key)
		return erase_node(_root->left, key);
	else if (_root->value < key)
		return erase_node(_root->right, key);
	else if (_root->value == key) {
		if (!root->left) {
			Node* current = _root->right;
			delete _root;
			_root = current;
			return _root;
		}
		else if (!_root->right) {
			Node* current = _root->left;
			delete _root;
			_root = current;
			return _root;
		}
		else {
			Node* current = min_node(_root->right);
			_root->value = current->value;
			erase_node(_root->right, current->value);
		}
	}
	return _root;
}

Node* BinaryTree::min_node(Node* _root) {
	while (_root->left)
		_root = _root->left;
	return _root;
}

Node* BinaryTree::get_root(){
	return root;
}

void BinaryTree::delete_tree(Node* _root) {
	if (!_root) 
		return;
	if(_root->left)
		delete_tree(_root->left);
	if(_root->right)
		delete_tree(_root->right);
	delete _root;
	_root = nullptr;
}

void BinaryTree::print_tree(const Node* _root) {
	cout << _root->value << " ";
	if (_root->left) 
		print_tree(_root->left);
	if (_root->right) 
		print_tree(_root->right);
}

Node* BinaryTree::copy_tree(Node* _root){
	Node* current = new Node(_root->value);
	if(_root->left) 
		current->left = copy_tree(_root->left);
	if(_root->right) 
		current->right = copy_tree(_root->right);
	return current;
}

Node* BinaryTree::find_node(Node* _root, int key) {
	if (_root == nullptr)
		return nullptr;
	if (_root->value == key)
		return _root;
	if (_root->value < key)
		return find_node(_root->right, key);
	else
		return find_node(_root->left, key);
}