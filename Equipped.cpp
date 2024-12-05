// YT - YoruoniVamp (VTube)
// Bitmask

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define cint const int
#define cf const float

int n, k, c, ts, s;
int dp[300];
vector<pair<int,int>> v;

void solve(){
    cin >> n >> k;
    while(n--){
        cin >> c;
        s = 0;
        for(int i = 0; i < k; i++){
            cin >> ts;
            s += ts; s <<= 1;
            //cout << s << ' ' << i << endl;
        }s >>= 1;
        v.push_back({c,s});
    }memset(dp,1000000,sizeof(dp)); dp[0] = 0;
    for(auto i: dp) cout << i << " ";
    for(int i = 0; i < (1 << k); i++){
        for(int j = 0; j < v.size(); j++){
            dp[i|v[j].second] = min(dp[i|v[j].second], dp[i] + v[j].first);
        }
    }
    //for(auto [i,j]: v) cout << i << ' ' << j << endl;
    //for(auto i: dp) cout << i << " ";
    //cout << endl;
    cout << dp[(1<<k)-1]; return;
}

int main(){
    //cin.tie(nullptr)->sync_with_stdio(0);cout.tie(0);
    solve();
    return 0;
}