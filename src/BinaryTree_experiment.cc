#include <iostream>
#include <random>
#include <BinaryTree.h>

using namespace std;
using namespace nestea;

int lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

int random_value(int from, int to, int seed) {
	mt19937 gen(seed);
	uniform_real_distribution<> segment(from, to);
	return segment(gen);
}

void set_insert(int from, int to, int seed) {
	int set_size[] = { 1000, 10000, 100000 };
	for (int s = 0; s < 3; s++) {
		static double seconds = 0;
		for (int i = 0; i < 100; i++) {
			BinaryTree _bintree;
			clock_t start = clock();
			for (int j = 0; j < set_size[s]; j++) {
				_bintree.insert(random_value(from, to, seed));
			}
			clock_t end = clock();
			seconds += (double)(end - start) / CLOCKS_PER_SEC;
		}
		cout << "BinaryTree:: insertion time of " << set_size[s] << " items: " << seconds / 100 << " seconds" << "\n";
	}
}

void set_contains(int from, int to, int seed) {
	int set_size[] = { 1000, 10000, 100000 };
	for (int s = 0; s < 3; s++) {
		static double seconds = 0;
		for (int i = 0; i < 1000; i++) {
			BinaryTree _bintree;
			for (int j = 0; j < set_size[s]; j++) {
				_bintree.insert(random_value(from, to, seed));
			}
			clock_t start = clock();
			_bintree.contains(random_value(from, to, seed));
			clock_t end = clock();
			seconds += (double)(end - start) / CLOCKS_PER_SEC;
		}
		cout << "BinaryTree:: time to search for an item in " << set_size[s] << " items: " << seconds / 1000 << " seconds" << "\n";
	}
}

void set_erase(int from, int to, int seed) {
	int set_size[] = { 1000, 10000, 100000 };
	for (int s = 0; s < 3; s++) {
		static double seconds = 0;
		for (int i = 0; i < 1000; i++) {
			BinaryTree _bintree;
			for (int j = 0; j < set_size[s]; j++) {
				_bintree.insert(random_value(from, to, seed));
			}
			clock_t start = clock();
			_bintree.insert(random_value(from, to, seed));
			_bintree.erase(random_value(from, to, seed));
			clock_t end = clock();
			seconds += (double)(end - start) / CLOCKS_PER_SEC;
		}
		cout << "BinaryTree:: time to insert and erase for an item in " << set_size[s] << " items: " << seconds / 1000 << " seconds" << "\n";
	}
}

void vector_insert(int from, int to, int seed) {
	int set_size[] = { 1000, 10000, 100000 };
	for (int s = 0; s < 3; s++) {
		static double seconds = 0;
		for (int i = 0; i < 100; i++) {
			vector<int> _vector;
			clock_t start = clock();
			for (int j = 0; j < set_size[s]; j++) {
				_vector.push_back(random_value(from, to, seed));
			}
			clock_t end = clock();
			seconds += (double)(end - start) / CLOCKS_PER_SEC;
		}
		cout << "Vector:: insertion time of " << set_size[s] << " items: " << seconds / 100 << " seconds" << "\n";
	}
}

void vector_contains(int from, int to, int seed) {
	int set_size[] = { 1000, 10000, 100000 };
	for (int s = 0; s < 3; s++) {
		static double seconds = 0;
		for (int i = 0; i < 1000; i++) {
			vector<int> _vector;
			for (int j = 0; j < set_size[s]; j++) {
				_vector.push_back(random_value(from, to, seed));
			}
			clock_t start = clock();
			std::find(_vector.begin(), _vector.end(), random_value(from, to, seed));
			clock_t end = clock();
			seconds += (double)(end - start) / CLOCKS_PER_SEC;
		}
		cout << "Vector:: time to search for an item in " << set_size[s] << " items: " << seconds / 1000 << " seconds" << "\n";
	}
}

void vector_erase(int from, int to, int seed) {
	int set_size[] = { 1000, 10000, 100000 };
	for (int s = 0; s < 3; s++) {
		static double seconds = 0;
		for (int i = 0; i < 1000; i++) {
			vector<int> _vector;
			for (int j = 0; j < set_size[s]; j++) {
				_vector.push_back(random_value(from, to, seed));
			}
			clock_t start = clock();
			_vector.push_back(random_value(from, to, seed));
			std::erase(_vector, random_value(from, to, seed));
			clock_t end = clock();
			seconds += (double)(end - start) / CLOCKS_PER_SEC;
		}
		cout << "Vector:: time to insert and erase for an item in " << set_size[s] << " items: " << seconds / 1000 << " seconds" << "\n";
	}
}

int main() {
	set_insert(0, 100000, 10);
	set_contains(0, 100000, 10);
	set_erase(0, 100000, 10);
	vector_insert(0, 100000, 10);
	vector_contains(0, 100000, 10);
	vector_erase(0, 100000, 10);
	return 0;
}

//BinaryTree:: insertion time of 1000 items: 0.01051 seconds
//BinaryTree:: insertion time of 10000 items: 0.11343 seconds
//BinaryTree:: insertion time of 100000 items : 0.94904 seconds

//BinaryTree:: time to search for an item in 1000 items: 1.7e-05 seconds
//BinaryTree:: time to search for an item in 10000 items: 3.1e-05 seconds
//BinaryTree:: time to search for an item in 100000 items: 3.8e-05 seconds

//BinaryTree:: time to insert and erase for an item in 1000 items: 1.8e-05 seconds
//BinaryTree:: time to insert and erase for an item in 10000 items: 3.3e-05 seconds
//BinaryTree:: time to insert and erase for an item in 100000 items : 4.4e-05 seconds

//Vector::insertion time of 1000 items: 0.00646 seconds
//Vector::insertion time of 10000 items : 0.06379 seconds
//Vector::insertion time of 100000 items : 0.60281 seconds

//Vector::time to search for an item in 1000 items : 6e-06 seconds
//Vector::time to search for an item in 10000 items : 1.7e-05 seconds
//Vector::time to search for an item in 100000 items : 2.1e-05 seconds

//Vector::time to insert and erase for an item in 1000 items : 1e-05 seconds
//Vector::time to insert and erase for an item in 10000 items : 4.9e-05 seconds
//Vector::time to insert and erase for an item in 100000 items : 0.000286 seconds