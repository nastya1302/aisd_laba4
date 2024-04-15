#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <BinaryTree.h>

using namespace std;
using namespace nestea;

TEST(BinaryTree_tests, insert1) {
	BinaryTree _bintree;
	bool check = _bintree.insert(5);
	EXPECT_TRUE(check);
}

TEST(BinaryTree_tests, insert2) {
	BinaryTree _bintree;
	_bintree.insert(5);
	_bintree.insert(7);
	_bintree.insert(4);
	_bintree.insert(2);
	_bintree.insert(1);
	_bintree.insert(3);
	_bintree.insert(6);
	_bintree.print();
	cout << "\n";
}
