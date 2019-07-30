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

int r, c;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(vvc &m, vii &f, ii j){
	vvii dist(r, vii(c, make_pair(-1, -1)));
	queue<ii> q;
	for(auto &el : f){
		dist[el.F][el.S] = make_pair(0, 1);
		q.push(el);
	}
	dist[j.F][j.S] = make_pair(0, 0);
	q.push(j);
	while(!q.empty()){
		ii p = q.front();	q.pop();
		int x = p.F, y = p.S;
		if(x == 0  || y == 0 || x == r-1 || y == c-1){
			if((dist[x][y]).S == 0){
				cout << dist[x][y].S + 1 << '\n';
				return;
			}
		}
		for(int i=0; i<4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			ii n = make_pair(nx, ny);
			if(0 <= nx && nx < r && 0 <= ny && ny < c && m[nx][ny] == '.'){
				if(dist[nx][ny].F == -1){
					(dist[nx][ny]).F = (dist[x][y]).F + 1;
					(dist[nx][ny]).S = (dist[x][y]).S;
					q.push(n);
					if(nx == 0 || ny == 0 || nx == r-1 || ny == c-1){
						if(dist[nx][ny].S == 0){
							cout << dist[nx][ny].F + 1<< '\n';
							return;
						}
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);	cin.tie(0);
	int T; cin >> T;
    while(T--){
        cin >> r >> c;
        vvc m(r, vc(c));
        ii j1;
        vii f;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> m[i][j];
                if(m[i][j] == 'J')	j1 = make_pair(i, j);
                else if(m[i][j] == 'F')	f.push_back(make_pair(i, j));
            }
        }

        bfs(m, f, j1);
    }
	return 0;
} 