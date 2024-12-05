// YT - YoruoniVamp (VTube)
// Graph

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld lond double
#define ull unsigned long long
#define cint const int
#define cf const float

cint mxA = 1e5+5;
vector<pair<int,int>> gph[mxA];
bool vis[mxA];
int n, u, v, w;

int dfs(int a){
    int ans = 0;
    vis[a] = true;
    for(auto [v,w]: gph[a]){
        if(vis[v]) continue;
        ans = max(ans, w+dfs(v));
    }return ans;
}

void solve(){
    cin >> n;
    n--;
    while(n--){
        cin >> u >> v >> w;
        gph[v].push_back({u,w});
        gph[u].push_back({v,w});
    }cout << dfs(1);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);cout.tie(0);
    solve();
    return 0;
}
