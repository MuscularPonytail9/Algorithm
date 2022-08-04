#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS
#endif
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

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

using namespace std;

struct Node {
	string cur;
	vector<Node*> v;
};

class tree {
public:
	Node* root;
};
tree tr;

void clean(Node* node) {
	if (node->v.empty() == false) {
		for (int i = 0; i < node->v.size(); i++) {
			clean(node->v[i]);
		}
	}
	for (int i = 0; i < node->v.size(); i++) {
		delete node->v[i];
	}
	node->v.clear();
}

void init(int n) {
	clean(tr.root);
}

void cmd_mkdir(string s1, string s2) {
	if (s1 == "/") {
		Node* temp = new Node();
		temp->cur = s2;
		tr.root->v.push_back(temp);
	}
	else {
		string temp = "";
		s1.erase(0, 0);
		Node* tmp = tr.root;
		while (!s1.empty()) {
			while (s1[0] != '/') {
				temp + s1[0];
				s1.erase(0, 0);
			}
			s1.erase(0, 0);
			for (int i = 0; i < tmp->v.size(); i++) {
				if (tmp->v[i]->cur == temp) {
					tmp = tmp->v[i];
					break;
				}
			}
			temp = "";
		}
		Node* temp2 = new Node();
		temp2->cur = s2;
		tmp->v.push_back(temp2);
	}
}

int count(Node* node) {
	int cnt = 0;
	if (node->v.empty() == false) {
		for (int i = 0; i < node->v.size(); i++) {
			cnt += count(node->v[i]);
		}
	}
	for (int i = 0; i < node->v.size(); i++) {
		cnt++;
	}
	return cnt;
}

Node* newNode(string s) {
	Node* tmp = new Node();
	tmp->cur = s;
	return tmp;
}

Node* getCopiedTree(Node* src) {
	Node* tmp = newNode(src->cur);
	for (int i = 0; i < src->v.size(); i++) {
		tmp->v.push_back(getCopiedTree(src->v[i]));
	}
	return tmp;
}

void cmd_rm(string s) {
	string temp = "";
	s.erase(0, 0);
	Node* tmp = tr.root;
	Node* prev = nullptr;
	int i = 0;
	while (!s.empty()) {
		while (s[0] != '/') {
			temp + s[0];
			s.erase(0, 0);
		}
		s.erase(0, 0);
		for (i = 0; i < tmp->v.size(); i++) {
			if (tmp->v[i]->cur == temp) {
				prev = tmp;
				tmp = tmp->v[i];
				break;
			}
		}
		temp = "";
	}
	clean(tmp);
	if (prev != nullptr) {
		prev->v.erase(prev->v.begin() + i);
	}
	delete tmp;
}

void cmd_cp(string src, string dest) {
	string temp = "";
	src.erase(0, 0);
	Node* tmp = tr.root;
	while (!src.empty()) {
		while (src[0] != '/') {
			temp + src[0];
			src.erase(0, 0);
		}
		src.erase(0, 0);
		for (int i = 0; i < tmp->v.size(); i++) {
			if (tmp->v[i]->cur == temp) {
				tmp = tmp->v[i];
				break;
			}
		}
		temp = "";
	}
	string temp2 = "";
	dest.erase(0, 0);
	Node* tmp2 = tr.root;
	while (!dest.empty()) {
		while (dest[0] != '/') {
			temp2 + dest[0];
			dest.erase(0, 0);
		}
		dest.erase(0, 0);
		for (int i = 0; i < tmp2->v.size(); i++) {
			if (tmp2->v[i]->cur == temp2) {
				tmp2 = tmp2->v[i];
				break;
			}
		}
		temp2 = "";
	}
	tmp2->v.push_back(getCopiedTree(tmp));
}

void cmd_mv(string src, string dest) {
	string temp = "";
	src.erase(0, 0);
	Node* tmp = tr.root;
	Node* prev = nullptr;
	int i = 0;
	while (!src.empty()) {
		while (src[0] != '/') {
			temp + src[0];
			src.erase(0, 0);
		}
		src.erase(0, 0);
		for (i = 0; i < tmp->v.size(); i++) {
			if (tmp->v[i]->cur == temp) {
				prev = tmp;
				tmp = tmp->v[i];
				break;
			}
		}
		temp = "";
	}
	string temp2 = "";
	dest.erase(0, 0);
	Node* tmp2 = tr.root;
	while (!dest.empty()) {
		while (dest[0] != '/') {
			temp2 + dest[0];
			dest.erase(0, 0);
		}
		dest.erase(0, 0);
		for (int j = 0; j < tmp2->v.size(); j++) {
			if (tmp2->v[j]->cur == temp2) {
				tmp2 = tmp2->v[j];
				break;
			}
		}
		temp2 = "";
	}
	tmp2->v.push_back(getCopiedTree(tmp));
	clean(tmp);
	if (prev != nullptr) {
		prev->v.erase(prev->v.begin() + i);
	}
	delete tmp;
}

int cmd_find(string s) {
	if (s == "/") {
		return count(tr.root);
	}
	else {
		string temp = "";
		s.erase(0, 0);
		Node* tmp = tr.root;
		while (!s.empty()) {
			while (s[0] != '/') {
				temp + s[0];
				s.erase(0, 0);
			}
			s.erase(0, 0);
			for (int i = 0; i < tmp->v.size(); i++) {
				if (tmp->v[i]->cur == temp) {
					tmp = tmp->v[i];
					break;
				}
			}
			temp = "";
		}
		return count(tmp);
	}
}

static bool run(int m) {

	bool isAccepted = true;
	int cmd;
	string name;
	string path1, path2;

	while (m--) {

		scanf("%d", &cmd);

		if (cmd == CMD_MKDIR) {
			cin >> path1 >> name;
			cmd_mkdir(path1, name);
		}
		else if (cmd == CMD_RM) {
			cin >> path1;
			cmd_rm(path1);
		}
		else if (cmd == CMD_CP) {
			cin >> path1 >> path2;
			cmd_cp(path1, path2);
		}
		else if (cmd == CMD_MV) {
			cin >> path1 >> path2;
			cmd_mv(path1, path2);
		}
		else {
			int ret;
			int answer;

			cin >> path1;
			ret = cmd_find(path1);
			scanf("%d", &answer);

			isAccepted &= (ret == answer);
		}
	}

	return isAccepted;
}

int main(void) {

	int test, T;
	int n, m;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test = 1; test <= T; ++test) {

		scanf("%d%d", &n, &m);

		init(n);

		if (run(m)) {
			printf("#%d 100\n", test);
		}
		else {
			printf("#%d 0\n", test);
		}
	}

	return 0;
}