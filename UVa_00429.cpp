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


int bfs(int src, int dst, vvi &adj){
	int V = adj.size();
	vi dist(V, INF);
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		bool f = 0;
		for(auto &el : adj[u]){
			if(dist[el] == INF){
				dist[el] = dist[u] + 1;
				q.push(el);
				if(el == dst){
					f = 1;
					break;
				}
			}
		}
		if(f)	break;
	}
	return dist[dst];
}

bool check(string &a, string &b){
	if(a.size() != b.size())	return false;
	bool f = false;
	for(int i=0; i<a.size(); i++){
		if(a[i] != b[i]){
			if(f)	return false;
			f = true;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int T;	cin >> T;
	while(T--){
		vs arr;
		string t;
		while(1){
			cin >> t;
			if(t == "*")	break;
			arr.push_back(t);
		}
		int n = arr.size();
		vvi adj(n);
		unordered_map<string, int> hm;
		for(int i=0; i<n; i++){
			hm[arr[i]] = i;
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(check(arr[i], arr[j])){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		string a, b;
		int c = 0;
		cin.ignore();
		while(getline(cin, t) && t.size() > 1){
			int pos = t.find(' ');
			a = t.substr(0, pos);
			b = t.substr(pos+1);
			cout << a << ' ' << b << ' ' << bfs(hm[a], hm[b], adj) << '\n';
		}
		if(T)	cout << '\n';
	}
	return 0;
} 