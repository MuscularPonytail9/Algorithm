#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;
int num, res;
int N;
int mat[100][100];
int lecture[100];
vector<int> v;

bool isCleared() {
	bool check = true;
	for (int i = 1; i <= N; i++) {
		if (lecture[i] != 0) {
			check = false;
		}
	}
	return check;
}

void function() {
	for (int i = 1; i <= N; i++) {
		if (lecture[i] == 0) {
			for (int j = 1; j <= N; j++) {
				mat[j][i] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int check = 0;
		for (int j = 1; j <= N; j++) {
			if (mat[i][j] != 0) {
				check++;
			}
		}
		lecture[i] = check;
	}
}

int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) {
			cin >> lecture[j];
			for (int k = 1; k <= lecture[j]; k++) {
				int temp;
				cin >> temp;
				mat[j][temp] = 1;
			}
		}
		while (isCleared() == false) {
			function();
			res++;
		}
		v.push_back(res + 1);
		res = 0;
		for (int k = 1; k <= N; k++) {
			for (int l = 1; l <= N; l++) {
				mat[k][l] = 0;
			}
		}
		for (int k = 1; k <= N; k++) {
			lecture[k] = 0;
		}
	}
	for (int i = 0; i <= v.size(); i++) {
		cout << "#" << i + 1 << " " << v[i] << '\n';
	}
	return 0;
}