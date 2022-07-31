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
	int c;
	Node* left;
	Node* right;
};

Node nodes[1002];
vector<int> v;


class tree {
public:
	void initTree() {
		for (int i = 0; i <= 1001; i++) {
			nodes[i].c = NULL;
			nodes[i].isDigit = NULL;
			nodes[i].left = nullptr;
			nodes[i].right = nullptr;
		}
	}

	void setEdge(int x) {
		char str[6];
		cin >> str;
		if (str[0] >= '0' && str[0] <='9') {
			nodes[x].isDigit = true;
			int num = 0;
			for (int i = 0; str[i]; i++) {
				num *= 10;
				num += str[i] - '0';
			}
			nodes[x].c = num;
		}
		else {
			nodes[x].isDigit = false;
			nodes[x].c = str[0];
			int l, r;
			cin >> l >> r;
			nodes[x].left = &nodes[l];
			nodes[x].right = &nodes[r];
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

	int calc(Node* node) {
		if (node->isDigit == true) {
			return node->c;
		}
		int l = calc(node->left);
		int r = calc(node->right);
		if (node->c == '+') {
			return l + r;
		}
		else if (node->c == '-') {
			return l - r;
		}
		else if (node->c == '*') {
			return l * r;
		}
		else {
			return l / r;
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
		int res = tr.calc(&nodes[1]);
		v.push_back(res);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << "#" << i + 1 << " " << v[i] << '\n';
	}
	return 0;
}
