#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define nl '\n'
#define sp ' '
#define rep(i, a, b) for(int i=a; i<b; ++i)
#define repd(i, a, b) for(int i=a; i>=b; --i)
#define repz(i, b) for(int i=0; i<b; ++i)
#define trav(i, a) for(int i: a)
#define read(a) repz(i, a.size()) cin>>a[i];
#define sz(a) a.size()
#define PI 3.141592653589793238
#define mod 1000000007
#define INF (int)1e18

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<bool> vb;


struct edge{
	int a, b, weight;
};

void dfs(int root, vvi &adj, vb &vis){
	vis[root] = true;
	trav(i, adj[root]) if(!vis[i]) dfs(i, adj, vis);
}

void solve(){

	//Bellman-Ford
	int n, m;
	cin>>n>>m;

	vector<edge> e(m);

	vvi adj(n);

	repz(i, m){
		int u, v, w;
		cin>>u>>v>>w;
		u--; v--; w = -w;
		e[i].a = u; e[i].b = v; e[i].weight = w;;
		adj[u].pb(v);
	}

	vi d(n, INF);
	d[0] = 0;

	repz(i, n-1){
		repz(j, m){
			if(d[e[j].a] < INF){
				if(d[e[j].b] > d[e[j].a] + e[j].weight){
					d[e[j].b] = max(-INF, d[e[j].a] + e[j].weight);
				}
			}
		}
	}

	set<int> st;
	repz(i, m){
		if(d[e[i].a] < INF){
			if(d[e[i].b] > d[e[i].a] + e[i].weight){
				d[e[i].b] = max(-INF, d[e[i].a] + e[i].weight);
				st.insert(e[i].b);
			}
		}
	}


	vb vis(n);

	trav(i, st)	dfs(i, adj, vis);

	if(vis[n-1]) cout<<-1<<nl;
	else cout<<-d[n-1]<<nl;

}

signed main(){


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);

	// freopen("output.txt", "w", stdout);
	// freopen("input.txt", "r", stdin);

	int ts=1;
	//cin>>ts;
	while(ts--) {
		solve();
	} 
	return 0;

}
