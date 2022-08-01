#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
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
	int key;
	Node* parent;
	Node* left;
	Node* right;
};

Node nodes[10002];
vector<pair<int, int>> v;
int cnt;

class tree {
public:
	void initTree() {
		for (int i = 0; i <= 10001; i++) {
			nodes[i].key = i;
			nodes[i].parent = nullptr;
			nodes[i].left = nullptr;
			nodes[i].right = nullptr;
		}
	}
	void setEdge() {
		int pIndex, cIndex;
		cin >> pIndex >> cIndex;
		if (nodes[pIndex].left == nullptr) {
			nodes[pIndex].left = &nodes[cIndex];
			nodes[cIndex].parent = &nodes[pIndex];
		}
		else if (nodes[pIndex].right == nullptr) {
			nodes[pIndex].right = &nodes[cIndex];
			nodes[cIndex].parent = &nodes[pIndex];
		}
	}
	int findCommonParent(int v1, int v2) {
		Node* temp1 = &nodes[v1];
		deque<int> d1;
		deque<int> d2;
		while (temp1 != nullptr) {
			d1.push_front(temp1->key);
			temp1 = temp1->parent;			
		}
		Node* temp2 = &nodes[v2];
		while (temp2 != nullptr) {
			d2.push_front(temp2->key);
			temp2 = temp2->parent;
		}
		int res = 0;
		for (int i = 0; i < d1.size(); i++) {
			if (d1[i] == d2[i]) {
				res = d1[i];
			}
			else {
				break;
			}
		}
		return res;
	}

	int countNum(Node* node) {
		cnt++;
		if (node->left != nullptr) {
			countNum(node->left);
		}
		if (node->right != nullptr) {
			countNum(node->right);
		}
		return cnt;
	}
};

int main() {
	tree tr;
	//freopen("input.txt", "r", stdin);
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		tr.initTree();
		int V, E, v1, v2;
		cin >> V >> E >> v1 >> v2;
		for (int j = 1; j <= E; j++) {
			tr.setEdge();
		}
		int commonParentIndex = tr.findCommonParent(v1, v2);
		v.push_back({ commonParentIndex ,tr.countNum(&nodes[commonParentIndex]) });
		cnt = 0;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << "#" << i + 1 << " " << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}
