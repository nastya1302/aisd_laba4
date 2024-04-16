#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <BinaryTree.h>

using namespace std;
using namespace nestea;

TEST(BinaryTree_tests, insert1) {
	BinaryTree _bintree;
	EXPECT_TRUE(_bintree.insert(5));
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

TEST(BinaryTree_tests, copy1) {
	BinaryTree _bintree;
	_bintree.insert(5);
	_bintree.insert(7);
	_bintree.insert(4);
	_bintree.insert(2);
	_bintree.insert(1);
	_bintree.insert(3);
	_bintree.insert(6);
	BinaryTree _bintree2(_bintree);
	_bintree.print();
	cout << "\n";
	_bintree2.print();
	cout << "\n";
}

TEST(BinaryTree_tests, copy2) {
	BinaryTree _bintree1;
	_bintree1.insert(5);
	_bintree1.insert(7);
	_bintree1.insert(4);
	_bintree1.insert(2);
	_bintree1.insert(1);
	_bintree1.insert(3);
	_bintree1.insert(6);
	cout << "Binary Tree 1: ";
	_bintree1.print();
	cout << "\n";

	BinaryTree _bintree2;
	_bintree2.insert(4);
	_bintree2.insert(2);
	_bintree2.insert(3);
	_bintree2.insert(5);
	cout << "Binary Tree 2: ";
	_bintree2.print();
	cout << "\n";

	cout << " 1 = 2\n";
	_bintree1 = _bintree2;

	cout << "Binary Tree 1: ";
	_bintree1.print();
	cout << "\n";

	cout << "Binary Tree 2: ";
	_bintree2.print();
	cout << "\n";
}

TEST(BinaryTree_tests, contains1) {
	BinaryTree _bintree;
	_bintree.insert(5);
	_bintree.insert(7);
	_bintree.insert(4);
	_bintree.insert(2);
	_bintree.insert(1);
	_bintree.insert(3);
	_bintree.insert(6);
	EXPECT_TRUE(_bintree.contains(6));
}

TEST(BinaryTree_tests, contains2) {
	BinaryTree _bintree;
	_bintree.insert(5);
	_bintree.insert(7);
	_bintree.insert(4);
	_bintree.insert(2);
	_bintree.insert(1);
	_bintree.insert(3);
	_bintree.insert(6);
	EXPECT_FALSE(_bintree.contains(10));
}

TEST(BinaryTree_tests, erase1) {
	BinaryTree _bintree;
	_bintree.insert(5);
	_bintree.insert(7);
	_bintree.insert(4);
	_bintree.insert(2);
	_bintree.insert(1);
	_bintree.insert(3);
	_bintree.insert(6);
	EXPECT_FALSE(_bintree.erase(10));
}

TEST(BinaryTree_tests, erase2) {
	BinaryTree _bintree;
	_bintree.insert(5);
	_bintree.insert(7);
	_bintree.insert(4);
	_bintree.insert(2);
	_bintree.insert(1);
	_bintree.insert(3);
	_bintree.insert(6);
	bool check = _bintree.erase(5);
	_bintree.print();
	cout << "\n";
	EXPECT_TRUE(check);
}