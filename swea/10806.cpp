#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

int A[10];

struct Node {
	int cnt;
	int lef;
};

class MinHeap {
#define parent  (i >> 1)
#define left	(i << 1)
#define right   (i << 1 | 1)

	static constexpr size_t MAX_N = 100000;

	Node data[MAX_N + 1];
	size_t size;

public:
	MinHeap() = default;

	void print() {
		for (int i = 1; i <= size; i++) {
			cout << data[i].cnt << " ";
		}
		cout << '\n';
	}

	bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void init() {
		size = 0;
	}
	void push(int cnt, int x) {
		size++;
		data[size].cnt = cnt;
		data[size].lef = x;
		for (int i = size; parent != 0 && data[parent].cnt >= data[i].cnt; i >>= 1) {
			std::swap(data[parent], data[i]);
		}
		print();
	}
	Node top() const {
		assert(size != 0);
		return data[1];
	}
	void pop() {
		assert(size != 0);
		data[1] = data[size--];
		for (size_t i = 1; left <= size;) {
			const size_t max_child = left == size || data[left].cnt < data[right].cnt ? left : right;
			if (data[max_child].cnt > data[i].cnt) {
				std::swap(data[max_child], data[i]);
				i = max_child;
			}
			else {
				break;
			}
		}
		print();
	}

#undef parent
#undef left
#undef right
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N;
        for (int n = 0; n < N; n++) cin >> A[n];
        cin >> K;

        int ans;
		MinHeap mh;
		mh.init();
        mh.push(0, K);
		mh.print();
        while (mh.top().lef) {
            Node node = mh.top();
			mh.pop();
            int cnt = node.cnt;
			cout << "current : " << cnt << '\n';
            int left = node.lef;
			mh.push(cnt + left, 0);
			cout << "pushed (" << cnt + left << ", " << 0 << ")" << '\n';
            for (int n = 0; n < N; n++) {
                if (left >= A[n]) {
                    mh.push(cnt + (left % A[n]), left / A[n]);
					cout << "pushed (" << cnt + (left % A[n]) << ", " << left / A[n] << ")" << '\n';
                }
            }
        }
		ans = mh.top().cnt;
        cout << '#' << tc << ' ' << ans << '\n';
    }
}

//int N, K, Ans;
//int Nums[11];
//
//void Input() {
//	int i;
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		scanf("%d", &Nums[i]);
//	}
//	scanf("%d", &K);
//}
//
//void GetAns() {
//	int i;
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//	pq.push(make_pair(0, K));
//	while (pq.top().second) {
//		pair<int, int> cur = pq.top();
//		pq.pop();
//		cout << "now (" << cur.first << ", " << cur.second << ")" <<'\n';
//		pq.push(make_pair(cur.first + cur.second, 0));
//		cout << "pushed (" << cur.first + cur.second << ", " << 0 << ")" << '\n';
//		for (i = 0; i < N; i++) {
//			pq.push(make_pair(cur.first + cur.second % Nums[i], cur.second / Nums[i]));
//			cout << "pushed (" << cur.first + cur.second % Nums[i] << ", " << cur.second / Nums[i] << ")" << '\n';
//		}
//	}
//	Ans = pq.top().first;
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	int t, t_i;
//	scanf("%d", &t);
//	for (t_i = 1; t_i <= t; t_i++) {
//		Input();
//		GetAns();
//		printf("#%d %d\n", t_i, Ans);
//	}
//	return 0;
//}