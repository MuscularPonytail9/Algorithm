#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string>
#include <array>

using namespace std;

struct Node {
	bool isDigit;
	Node* left;
	Node* right;
};

Node nodes[202];
int nodeCnt;
vector<int> v;


class tree {
public:
	bool isAvailabe;

	void initTree() {
		isAvailabe = true;
		for (int i = 1; i <= 201; i++) {
			nodes[i].isDigit = NULL;
			nodes[i].left = nullptr;
			nodes[i].right = nullptr;
		}
	}

	void setEdge(int x) {
		char ch;
		cin >> ch;
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			nodes[x].isDigit = false;
		}
		else {
			nodes[x].isDigit = true;
		}
		if (cin.get() == ' ') {
			int temp;
			cin >> temp;
			nodes[x].left = &nodes[temp];
			if (cin.get() == ' ') {
				cin >> temp;
				nodes[x].right = &nodes[temp];
			}
		}
	}

	bool isLeaf(Node* node) {
		if (node->left == nullptr && node->right == nullptr) {
			return true;
		}
		else {
			false;
		}
	}

	void check(Node* node) {
		if (isLeaf(node) == true) {
			if (node->isDigit == false) {
				isAvailabe = false;
				return;
			}
		}
		else {
			if (node->isDigit == true) {
				isAvailabe = false;
				return;
			}
		}
		if (node->left != nullptr) {
			check(node->left);
		}
		if (node->right != nullptr) {
			check(node->right);
		}
	}
};

int main() {
	tree tr;
	//freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		tr.initTree();
		int nodeNum;
		cin >> nodeNum;
		for (int j = 1; j <= nodeNum; j++) {
			int index;
			cin >> index;
			tr.setEdge(index);
		}
		tr.check(&nodes[1]);
		v.push_back(tr.isAvailabe);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << "#" << i + 1 << " " << v[i] << '\n';
	}
	return 0;
}
