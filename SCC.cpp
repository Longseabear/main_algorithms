#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
	vector<int> next;
};
stack<int> s;
Node node[10001];
int finished[10001];
int parrent[10001];
int global_idx = 0;
vector<vector<int>> SCC;
int dfs(int cur) {
	parrent[cur] = ++global_idx;
	s.push(cur);
	int cur_parrent = parrent[cur];
	for (int i = 0; i < node[cur].next.size(); i++) {
		int next = node[cur].next[i];
		if (finished[next]) continue;
		if (parrent[next] == 0) cur_parrent = min(cur_parrent, dfs(next));
		else cur_parrent = min(cur_parrent, parrent[next]);
	}

	if (cur_parrent == parrent[cur]) {
		vector<int> scc;
		while (1) {
			int top_node = s.top();
			s.pop();
			scc.push_back(top_node);
			finished[top_node] = true;
			if (top_node == cur) break;
		}
		SCC.push_back(scc);
	}
	return cur_parrent;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].next.push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!finished[i]) dfs(i);
	}
	for (int i = 0; i < SCC.size(); i++) {
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC.begin(), SCC.end());
	printf("%d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}

}
