#include <iostream>
#include <vector>
#include <BinaryTree.h>

using namespace std;
using namespace nestea;

vector<int> duplicate_elements(vector<int> _vector) {
	BinaryTree _bintree;
	vector<int> _duplicate;
	for (int i = 0; i < _vector.size(); i++)
		if (!_bintree.insert(_vector[i]))
			_duplicate.push_back(_vector[i]);
	return _duplicate;
}

int main() {
	vector<int> _vector = { 3, 2, 2, 4 };
	vector<int> _duplicate = duplicate_elements(_vector);
	for (int i = 0; i < _duplicate.size(); i++)
		cout << _duplicate[i] << " ";
	return 0;
}