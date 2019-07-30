#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
 
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


class UF{

	vi p, r;

public:
	UF(int V): p(V), r(V, 0){
		for(int i=0; i<V; i++)	p[i] = i;
	}

	int findSet(int i){
		return (  (p[i] == i) ? i : ( p[i] = findSet(p[i]) )  );
	}

	void unionSet(int i, int j){
		int x, y;
		x = findSet(i), y = findSet(j);
		if(x == y)	return;
		if(r[x] > r[y]){
			p[y] = x;
		}
		else{
			p[x] = y;
			if(r[x] == r[y])	r[y]++;
		}
	}

};

void kruskal(vector<pair<double, ii> > &edj, int V, vii &ed){
	sort(edj.begin(), edj.end());
	UF uf(V);
	vii ans;
	for(auto &el : ed){
		int i = el.F, j = el.S;
		uf.unionSet(i, j);
	}
	for(auto &el : edj){
		double wt = el.F;
		int i = el.S.F, j = el.S.S;
		if(uf.findSet(i) != uf.findSet(j)){
			uf.unionSet(i, j);
			ans.push_back(ii(i, j));
		}
	}
	if(!ans.size()){
		cout << "No new highways need\n";
	}
	else{
		for(auto &el : ans){
			cout << el.F + 1 << ' ' << el.S + 1 << '\n';
		}
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int T;	cin >> T;
	while(T--){
		int V;	cin >> V;
		vii arr(V);
		for(int i=0; i<V; i++){
			int a, b;	cin >> a >> b;
			arr[i] = make_pair(a, b);
		}
		int m;	cin >> m;
		vii ed(m);
		for(int i=0; i<m; i++){
			int a, b;	cin >> a >> b;
			a--; b--;
			ed[i] = make_pair(a, b);
		}
		vector<pair<double, ii> > edj;
		for(int i=0; i<V; i++){
			for(int j=i+1; j<V; j++){
				auto p1 = arr[i], p2 = arr[j];
				int x1 = p1.F, x2 = p2.F;
				int y1 = p1.S, y2 = p2.S;
				double dist = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
				edj.push_back(make_pair(dist, ii(i, j)));
			}
		}
		kruskal(edj, V, ed);
		if(T)	cout << '\n';
	}
	return 0;
} 