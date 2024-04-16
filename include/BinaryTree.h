#pragma once
#include <iostream>

using namespace std;

namespace nestea {
	struct Node {
		int value;
		Node* left;
		Node* right;

		Node();
		Node(int _value);
	};

	class BinaryTree {
	private:
		Node* root;
		void delete_tree(Node* _root);
		void print_tree(const Node* _root);
		Node* copy_tree(Node* _root);
		Node* find_node(Node* _root, int key);
		Node* erase_node(Node*& _root, int key);
		Node* min_node(Node* _root);

	public:
		BinaryTree();
		BinaryTree(const BinaryTree& _bintree);
		BinaryTree& operator=(const BinaryTree& _root);
		~BinaryTree();
		void print();
		bool insert(int key);
		bool contains(int key);
		bool erase(int key);
		Node* get_root();
	};
}