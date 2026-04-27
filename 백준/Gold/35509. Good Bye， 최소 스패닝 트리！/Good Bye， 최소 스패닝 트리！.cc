#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int p[100000];
int N, M;

struct Edge {
	int id;
	int u, v;
	ll w;
};

struct UnionFind {
	vector<int> parent;

	UnionFind(int n) {
		parent.resize(n + 1);
		for (int i = 1; i <= n; i++) parent[i] = i;
	}

	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]); 
	}

	bool merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false; 
		parent[u] = v;
		return true; 
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	vector<Edge> edges(M + 1);
	
	for (int i = 1; i <= M; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].id = i;
	}

	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
		return a.w < b.w;
	});

	UnionFind uf_mst(N);
	ll sum_w = 0;
	ll max_w = 0;
	int cnt = 0;
	
	for (auto& e : edges) {
		if (uf_mst.merge(e.u, e.v)) {
			sum_w += e.w;
			max_w = max(max_w, e.w);

			if (++cnt == N - 1) break;
		}
	}

	
	vector<Edge> candidate;

	for (const auto& e : edges) {
		if (e.w <= max_w) {
			candidate.push_back(e); // max_w 이하만 넣고 돌리기
		}
	}
	sort(candidate.begin(), candidate.end(), [](const Edge& a, const Edge& b) {
		return a.w > b.w; //내림차순
	});

	UnionFind uf_mbst(N);
	ll mbst_max_sum = 0;
	vector<int> mbst_edges;
	cnt = 0;
	
	for (const auto& e : candidate) {
		if (uf_mbst.merge(e.u, e.v)) {
			mbst_max_sum += e.w;
			mbst_edges.push_back(e.id);

			if (++cnt == N - 1) break;
		}
	}
	
	cout << "NO\n"; //1. MST이면서 MBST가 아닌 것(항상 존재하지 않음)


	if (mbst_max_sum > sum_w) { // 2. MBST이면서 MST가 아닌 것
		cout << "YES\n";
		for (int id : mbst_edges) {
			cout << id << '\n';
		}
	}
	else {
		cout << "NO\n";
	}

	return 0;
}