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
	char ch;
	Node* left;
	Node* right;
};

Node nodes[29];
int nodeCnt;
int N;
Node* newNode(char c) {
	nodes[nodeCnt].ch = c;
	nodes[nodeCnt].left = nullptr;
	nodes[nodeCnt].right = nullptr;
	return &nodes[nodeCnt++];
}

class tree {
public:
	void setTree() {
		char c = 'A';
		for (int i = 1; i <= 26; i++) {
			nodes[i].ch = c;
			c++;
		}
	}

	void setEdge(int x) {
		char ch;
		cin >> ch;
		if (ch != '.') {
			nodes[x].left = &nodes[ch - 64];
		}
		cin >> ch;
		if (ch != '.') {
			nodes[x].right = &nodes[ch - 64];
		}
	}
	void preOrder(Node* node) {
		cout << node->ch;
		if (node->left != nullptr) {
			preOrder(node->left);
		}
		if (node->right != nullptr) {
			preOrder(node->right);
		}
	}
	void inOrder(Node* node) {
		if (node->left != nullptr) {
			inOrder(node->left);
		}
		cout << node->ch;
		if (node->right != nullptr) {
			inOrder(node->right);
		}
	}
	void postOrder(Node* node) {
		if (node->left != nullptr) {
			postOrder(node->left);
		}
		if (node->right != nullptr) {
			postOrder(node->right);
		}
		cout << node->ch;
	}
};

int main() {
	cin >> N;
	tree tr;
	tr.setTree();
	for (int i = 1; i <= N; i++) {
		char ch;
		cin >> ch;
		tr.setEdge(ch-64);
	}
	tr.preOrder(&nodes[1]);
	cout << '\n';
	tr.inOrder(&nodes[1]);
	cout << '\n';
	tr.postOrder(&nodes[1]);
	return 0;
}
