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

	public:
		BinaryTree();
		//BinaryTree(const BinaryTree& _root);
		//BinaryTree& operator=(const BinaryTree& _root);
		~BinaryTree();
		void print();
		bool insert(int key);
		//bool contains(int key);
		//bool erase(int key);

		//Node* get_root();
	};
}