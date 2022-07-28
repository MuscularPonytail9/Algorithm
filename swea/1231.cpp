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

string s;
vector<string> res;
struct Node {
	char c;
	Node* left, * right;
};

constexpr size_t MAX_NODE = 102;

Node nodes[MAX_NODE];

void init() {
	for (int i = 0; i <= 101; i++) {
		nodes[i].c = NULL;
		nodes[i].left = nullptr;
		nodes[i].right = nullptr;
	}
}

void Inorder(Node* node) {
	if (node->left != nullptr) Inorder(node->left);
	s = s + node->c;
	if (node->right != nullptr) Inorder(node->right);
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	for (int t = 0; t < 10; t++) {
		init();
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int index;
			cin >> index;
			cin >> nodes[index].c;
			if (cin.get() != '\n') {
				int leftIndex;
				cin >> leftIndex;
				nodes[index].left = &nodes[leftIndex];
				if (cin.get() != '\n') {
					int rightIndex;
					cin >> rightIndex;
					nodes[index].right = &nodes[rightIndex];
				}
			}
		}
		s = "";
		Inorder(&nodes[1]);
		res.push_back(s);
	}
	for (int i = 0; i < res.size(); i++) {
		cout << "#" << i + 1 << " " << res[i] << '\n';
	}
}
