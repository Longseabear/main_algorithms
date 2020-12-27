#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
struct Item {
	int start;
	int end;
};
struct cmp {
	bool operator()(Item a, Item b) {
		if (a.start == b.start) return a.end < b.end;
		return a.start < b.start;
	}
};
vector<Item> vector_sort(vector<Item>& a) {
	sort(a.begin(), a.end(), cmp());
	vector<Item> sorted_vector;
	if (a.size() == 0) return sorted_vector;
	int s = a[0].start;
	int e = a[0].end;
	for (int i = 0; i < a.size(); i++) {
		if (s <= a[i].start && a[i].start <=e) e = max(a[i].end, e);
		else {
			sorted_vector.push_back({ s,e });
			s = a[i].start;
			e = a[i].end;
		}
	}
	sorted_vector.push_back({ s,e });
	return sorted_vector;
}

vector<Item> vector_merge(vector<Item>& a, vector<Item>& b) {
	vector<Item> res;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			res.push_back({ a[i].start + b[j].start, a[i].end + b[j].end - 1 });
		}
	}
	return vector_sort(res);
}
int main() {
	int n,m;
	scanf("%d", &n);
	vector<Item> item;
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		item.push_back({ val, val + 1 });
	}
	item[0].start = 0;
	vector<Item> res;

	res.push_back({ 0,1});
	item = vector_sort(item);
	scanf("%d", &m);
	for (int i = 20; i >=0; i--) {
		res = vector_merge(res, res);
		if (m & (1 << i)) res = vector_merge(res, item);
	}
	int answer = res[0].end;
	printf("%s win at %d", answer%2==0?"holsoon":"jjaksoon",answer);
}
