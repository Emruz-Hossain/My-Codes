#include <bits/stdc++.h>
using namespace std;

vector <int> edge[100010], tree(400010, INT_MAX);
int color[100010], subtree[100010], baseArray[100010], posInBase[100010], chainIdx[100010], parent[100010], chainHead[100010];
int ptr = 0, chainNo = 0;

void update(int node, int l, int h, int i, int x)
{
	if(l == i && h == i) {
		if(x) tree[node] = i;
		else tree[node] = INT_MAX;
		return;
	}

	int lc = node<<1;
	int rc = lc|1;
	int m = (l+h)>>1;

	if(i <= m) update(lc, l, m, i, x);
	else update(rc, m+1, h, i, x);

	tree[node] = min(tree[lc], tree[rc]);
}


int queryy(int node, int l, int h, int i, int j)
{
	if(i == l && j == h) return tree[node];

	int lc = node<<1;
	int rc = lc|1;
	int m = (l+h)>>1;

	if(j <= m) return queryy(lc, l, m, i, j);
	if(i > m) return queryy(rc, m+1, h, i, j);
	return min(queryy(lc, l, m, i, m), queryy(rc, m+1, h, m+1, j));
}

int query(int u)
{
	int uchain, mn = INT_MAX;
	while(1) {
		uchain = chainIdx[u];

		if(uchain == 0) return min(mn, queryy(1, 0, ptr-1, 0, posInBase[u]));
		mn = min(mn, queryy(1, 0, ptr-1, posInBase[chainHead[uchain]], posInBase[u]));
		u = parent[chainHead[uchain]];
	}
}


void HLD(int curr, int prev)
{
	if(chainHead[chainNo] == 0) chainHead[chainNo] = curr;
	chainIdx[curr] = chainNo;
	posInBase[curr] = ptr;
	baseArray[ptr] = curr;
	ptr++;

	int sc = -1, mx = 0;
	for(int i = 0; i < edge[curr].size(); i++) if(subtree[edge[curr][i]] > mx && edge[curr][i] != prev) mx = subtree[edge[curr][i]], sc = edge[curr][i];

	if(mx) HLD(sc, curr);

	for(int i = 0; i < edge[curr].size(); i++) if(edge[curr][i] != sc && edge[curr][i] != prev) {chainNo++; HLD(edge[curr][i], curr);}
}

void DFS(int curr, int prev)
{
	parent[curr] = prev;
	subtree[curr] = 1;

	for(int i = 0; i < edge[curr].size(); i++) {
		if(edge[curr][i] != prev) {
			DFS(edge[curr][i], curr);
			subtree[curr] += subtree[edge[curr][i]];
		}
	}
}


int main()
{
	int n, q, u, v;

	scanf("%d%d", &n, &q);

	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	DFS(1, -1);
	HLD(1, -1);

	while(q--) {
		scanf("%d%d", &u, &v);

		if(u) {
			int ans = query(v);
			if(ans == INT_MAX) ans = -1;
			else ans = baseArray[ans];
			printf("%d\n", ans);
		}
		else {
			color[v] = 1-color[v];
			update(1, 0, ptr-1, posInBase[v], color[v]);
		}
	}
	return 0;
}
