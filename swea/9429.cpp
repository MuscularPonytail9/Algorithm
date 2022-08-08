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
#define MAX 70000

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

using namespace std;

struct Node {
	char name[NAME_MAXLEN + 1];
	Node* child[30];
};
Node nodes[MAX];
Node* root;
int nodeCnt;
int nodeSum = 1;

Node* newNode(char name[NAME_MAXLEN + 1]) {
	for (int i = 0; i < NAME_MAXLEN + 1; i++) {
		if (name[i] != NULL) {
			nodes[nodeCnt].name[i] = name[i];
		}
		else {
			nodes[nodeCnt].name[i] = NULL;
		}
	}
	for (int i = 0; i < 30; i++) {
		nodes[nodeCnt].child[i] = nullptr;
	}
	return &nodes[nodeCnt++];
}

void init(int n) {
	nodeCnt = 0;
	root = newNode("/");
	nodeSum = 1;
}

int count(Node* node) {
	int cnt = 1;
	//cout << node->name << " ";
	for (int i = 0; node->child[i] != nullptr; i++) {
		cnt += count(node->child[i]);
	}
	//cout << '\n';
	return cnt;
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
	cout << "5 find " << path << '\n';
	if (!strcmp(path, "/")) {
		//cout << count(root) - 1;
		return count(root)-1;
	}
	else {
		Node* tmp = root;
		int nameIdx = 0;
		char temp[NAME_MAXLEN + 1] = "";
		for (int i = 1; path[i] != NULL; i++) {
			if (path[i] == '/') {
				nameIdx = i;
				for (int j = 0; j < 30; j++) {
					if (!strcmp(tmp->child[j]->name, temp)) {
						tmp = tmp->child[j];
						break;
					}
				}
				for (int j = 0; j < NAME_MAXLEN + 1; j++) {
					temp[j] = NULL;
				}
			}
			else {
				temp[i - 1 - nameIdx] = path[i];
			}
		}
		//cout << count(tmp) - 1;
		return count(tmp)-1;
	}
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
	cout << '\n' << "1 mkdir" << '\n';
	int called = 0;
	if (!strcmp(path, "/")) {
		Node* temp = newNode(name);

		for (int i = 0; i < 30; i++) {
			if (root->child[i] == nullptr) {
				root->child[i] = temp;
				called++;
				cout << called << '\n';
				nodeSum++;
				//cout << root->name << "   " << temp->name << '\n';
				break;
			}
		}
	}
	else {
		Node* tmp = root;
		int nameIdx = 0;
		char temp[NAME_MAXLEN + 1] = "";
		for (int i = 1; path[i] != NULL; i++) {
			if (path[i] == '/') {
				nameIdx = i;
				for (int j = 0; j < 30; j++) {
					if (!strcmp(tmp->child[j]->name, temp)) {
						tmp = tmp->child[j];
						break;
					}
				}
				for (int j = 0; j < NAME_MAXLEN + 1; j++) {
					temp[j] = NULL;
				}
			}
			else {
				temp[i - 1 - nameIdx] = path[i];
			}
		}
		//cout << name << '\n';
		nodeSum++;
		Node* temp2 = newNode(name);
		//cout << temp2->name << '\n';
		for (int i = 0; i < 30; i++) {
			if (tmp->child[i] == nullptr) {
				called++;
				cout << called << '\n';
				tmp->child[i] = temp2;
				break;
			}
		}
		cout << nodeSum << '\n';
		cout << count(root) << '\n';
	}
}

//Node* getCopiedTree(Node* src) {
//	Node* tmp = newNode(src->name);
//	for (int i = 0; src->child[i] != nullptr; i++) {
//		tmp->child[i] = getCopiedTree(src->child[i]);
//	}
//	return tmp;
//}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
	cout << '\n' << "2 rm" << '\n';
	Node* tmp = root;
	Node* prev = nullptr;
	int nameIdx = 0;
	int j = 0;
	char temp[NAME_MAXLEN + 1] = "";
	for (int i = 1; path[i] != NULL; i++) {
		if (path[i] == '/') {
			nameIdx = i;
			for (j = 0; j < 30; j++) {
				if (!strcmp(tmp->child[j]->name, temp)) {
					prev = tmp;
					tmp = tmp->child[j];
					break;
				}
			}
			for (int j = 0; j < NAME_MAXLEN + 1; j++) {
				temp[j] = NULL;
			}
		}
		else {
			temp[i - 1 - nameIdx] = path[i];
		}
	}
	int mN = count(prev->child[j]);
	if (prev != nullptr) {
		prev->child[j] = nullptr;
		for (int k = j + 1; prev->child[k] != nullptr; k++) {
			if (prev->child[k + 1] == nullptr || k == 28) {
				prev->child[k - 1] = prev->child[k];
				prev->child[k] = nullptr;
			}
			else {
				prev->child[k - 1] = prev->child[k];
			}
		}
	}
	nodeSum = nodeSum - mN;
	cout << nodeSum << '\n';
	cout << count(root) << '\n';
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	cout << '\n' << "3 cp" << '\n';
	Node* tmp = root;
	char temp[NAME_MAXLEN + 1] = "";
	char temp2[NAME_MAXLEN + 1] = "";
	int nameIdx = 0;
	for (int i = 1; srcPath[i] != NULL; i++) {
		if (srcPath[i] == '/') {
			nameIdx = i;
			for (int j = 0; j < 30; j++) {
				if (!strcmp(tmp->child[j]->name, temp)) {
					tmp = tmp->child[j];
					break;
				}
			}
			for (int j = 0; j < NAME_MAXLEN + 1; j++) {
				temp[j] = NULL;
			}
		}
		else {
			temp[i - 1 - nameIdx] = srcPath[i];
		}
	}
	int dN = count(tmp);
	nameIdx = 0;
	Node* tmp2 = root;
	if (!strcmp(dstPath, "/")) {
		for (int i = 0; i < 30; i++) {
			if (tmp2->child[i] == nullptr) {
				tmp2->child[i] = tmp;
				break;
			}
		}
	}
	else {
		for (int i = 1; dstPath[i] != NULL; i++) {
			if (dstPath[i] == '/') {
				nameIdx = i;
				for (int j = 0; j < 30; j++) {
					if (!strcmp(tmp2->child[j]->name, temp2)) {
						tmp2 = tmp2->child[j];
						break;
					}
				}
				for (int j = 0; j < NAME_MAXLEN + 1; j++) {
					temp2[j] = NULL;
				}
			}
			else {
				temp2[i - 1 - nameIdx] = dstPath[i];
			}
		}
		for (int i = 0; i < 30; i++) {
			if (tmp2->child[i] == nullptr) {
				tmp2->child[i] = tmp;
				break;
			}
		}
	}
	nodeSum = nodeSum + dN;
	cout << nodeSum << '\n';
	cout << count(root) << '\n';
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
	cout << '\n' << "4 mv" << '\n';
	Node* tmp = root;
	Node* prev = nullptr;
	char temp[NAME_MAXLEN + 1] = "";
	char temp2[NAME_MAXLEN + 1] = "";
	int nameIdx = 0;
	int j = 0;
	for (int i = 1; srcPath[i] != NULL; i++) {
		if (srcPath[i] == '/') {
			nameIdx = i;
			for (j = 0; j < 30; j++) {
				if (!strcmp(tmp->child[j]->name, temp)) {
					prev = tmp;
					tmp = tmp->child[j];
					break;
				}
			}
			for (int j = 0; j < NAME_MAXLEN + 1; j++) {
				temp[j] = NULL;
			}
		}
		else {
			temp[i - 1 - nameIdx] = srcPath[i];
		}
	}
	prev->child[j] = nullptr;
	for (int k = j + 1; prev->child[k] != nullptr; k++) {
		if (prev->child[k + 1] == nullptr || k == 28) {
			prev->child[k - 1] = prev->child[k];
			prev->child[k] = nullptr;
		}
		else {
			prev->child[k - 1] = prev->child[k];
		}
	}
	Node* tmp2 = root;
	nameIdx = 0;
	if (!strcmp(dstPath, "/")) {
		for (int i = 0; i < 30; i++) {
			if (tmp2->child[i] == nullptr) {
				tmp2->child[i] = tmp;
				//cout << tmp2->name << "/++" << tmp->name << '\n';
				break;
			}
		}
	}
	else {
		for (int i = 1; dstPath[i] != NULL; i++) {
			if (dstPath[i] == '/') {
				nameIdx = i;
				for (int j = 0; j < 30; j++) {
					if (!strcmp(tmp2->child[j]->name, temp2)) {
						tmp2 = tmp2->child[j];
						break;
					}
				}
				for (int j = 0; j < NAME_MAXLEN + 1; j++) {
					temp2[j] = NULL;
				}
			}
			else {
				temp2[i - 1 - nameIdx] = dstPath[i];
			}
		}
		for (int i = 0; i < 30; i++) {
			if (tmp2->child[i] == nullptr) {
				tmp2->child[i] = tmp;
				//cout << tmp2->name << "/++" << tmp->name << '\n';
				break;
			}
		}
	}
	cout << nodeSum << '\n';
	cout << count(root) << '\n';
}

static bool run(int m) {

	bool isAccepted = true;
	int cmd;
	char name[NAME_MAXLEN + 1];
	char path1[PATH_MAXLEN + 1], path2[PATH_MAXLEN + 1];

	while (m--) {

		scanf("%d", &cmd);

		if (cmd == CMD_MKDIR) {
			scanf("%s%s", path1, name);
			cmd_mkdir(path1, name);
		}
		else if (cmd == CMD_RM) {
			scanf("%s", path1);
			cmd_rm(path1);
		}
		else if (cmd == CMD_CP) {
			scanf("%s%s", path1, path2);
			cmd_cp(path1, path2);
		}
		else if (cmd == CMD_MV) {
			scanf("%s%s", path1, path2);
			cmd_mv(path1, path2);
		}
		else {
			int ret;
			int answer;

			scanf("%s", path1);
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