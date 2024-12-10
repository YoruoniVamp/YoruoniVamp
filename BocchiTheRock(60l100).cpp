// YT - YoruoniVamp (VTube)
// Dijkstra Algorithm

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define cint const int
#define cf const float

cint INF = 1e9;
vector<pair<int,int>> adj[200005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int n, m, k, u, v ,w, dis[100005];
bool vis[100005];

void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++) dis[i] = INF;
    while(m--){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }cin >> k;
    while(k--){
        cin >> u >> w;
        adj[n].push_back({u,w});
    }pq.push({0,n});
    dis[n] = 0;
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v,di]: adj[u]){
            if(dis[u] + di < dis[v]){
                dis[v] = dis[u] + di;
                pq.push({dis[v],v});
            }
        }
    }
    //for(int i = 0; i <= n; i++) cout << i << " " << dis[i] << endl;
    cout << dis[0];
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);cout.tie(0);
    solve();
    return 0;
}