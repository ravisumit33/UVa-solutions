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

bool check(char ch, string &ans, int ind, vvb &c){
	for(int i=0; i<ind; i++){
		if(c[ch - 'a'][ans[i] - 'a'])	return false;
	}
	return true;
}

void solve(vc &v, vvb &c, int V, string &ans, int ind, vb &hash){
	if(ind >= V){
		cout << ans << '\n';
		return;
	}
	for(int i=0; i<V; i++){
		if(!hash[v[i] - 'a'] && check(v[i], ans, ind, c)){
			ans[ind] = v[i];
			hash[v[i] - 'a'] = true;
			solve(v, c, V, ans, ind+1, hash);
			hash[v[i] - 'a'] = false;
		}
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);	cin.tie(0);
	string var, cons;
	bool f = true;
	while(getline(cin, var) && getline(cin, cons)){
		if(f)	f = false;
		else	cout << '\n';
		vc v;
		for(int i=0; i<var.size(); i++){
			if(var[i] != ' ')	v.push_back(var[i]);
		}
		sort(v.begin(), v.end());
		int V = v.size();
		vvb c(26, vb(26, false));
		for(int i=0; i<cons.size(); i++){
			int a = cons[i] - 'a';
			i += 2;
			int b = cons[i] - 'a';
			i++;
			c[a][b] = true;
		}
		string ans(V, '#');
		int ind = 0;
		vb hash(26, false);
		solve(v, c, V, ans, ind, hash);
		
	}
	return 0;
} 