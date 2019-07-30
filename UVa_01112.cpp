#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
 
const int INF = 1e9;

using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using ll = long long int;
using vb = vector<bool>;
using vvb = vector<vb>;


void dijkstra(vvii &adj, int T, int s){
	int V = adj.size();
	vi dist(V, INF);
	dist[s] = 0;
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(0, s));
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		int u = p.S, d = p.F;
		if(dist[u] < d)	continue;
		dist[u] = d;
		for(auto &el : adj[u]){
			if(dist[el.F] > dist[u] + el.S){
				dist[el.F] = dist[u] + el.S;
				pq.push(ii(dist[u] + el.S, el.F));
			}
		}
	}
	int ans = 0;
	for(auto &el : dist){
		if(el > T)	ans++;
	}
	cout << V - ans << '\n';
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int T;	cin >> T;
	while(T--){
		int N, E, tim;
		cin >> N >> E  >> tim;
		int M;	cin >> M;
		vvii adj(N+1);
		for(int i=0; i<M; i++){
			int u, v, w;
			cin >> u >> v >> w;
			adj[v].push_back(ii(u, w));
		}
		dijkstra(adj, tim, E);
		if(T)	cout << '\n';
	}
	return 0;
} 