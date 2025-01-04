// YT - YoruoniVamp (VTube)

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define cint const int
#define cf const float
#define pii pair<int,int>
#define t4i tuple<int,int,int,int>

int x, y, n, a, b;
vector<pii> dirt, water, wind, fire;
vector<t4i> DirtWater, WindFire;

void solve(){
    cin >> x >> y >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        dirt.push_back({a,b});
    }for(int i = 0; i < n; i++){
        cin >> a >> b;
        water.push_back({a,b});
    }for(int i = 0; i < n; i++){
        cin >> a >> b;
        wind.push_back({a,b});
    }for(int i = 0; i < n; i++){
        cin >> a >> b;
        fire.push_back({a,b});
    }for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            DirtWater.push_back({dirt[i].first + water[j].first,dirt[i].second + water[j].second,i,j});
            WindFire.push_back({wind[i].first + fire[j].first,wind[i].second + fire[j].second,i,j});
        }
    }sort(DirtWater.begin(),DirtWater.end());
    sort(WindFire.begin(),WindFire.end());
    for(auto tpl: DirtWater){
        auto [diwaX, diwaY, diIdx, waIdx] = tpl;
        auto [wifiX, wifiY, wiIdx, fiIdx] = *lower_bound(WindFire.begin(),WindFire.end(),make_tuple(x-diwaX,y-diwaY,0,0));
        if(diwaX + wifiX == x and diwaY + wifiY == y){
            cout << dirt[diIdx].first << " " << dirt[diIdx].second;
            cout << water[waIdx].first << " " << water[waIdx].second;
            cout << wind[wiIdx].first << " " << wind[wiIdx].second;
            cout << fire[fiIdx].first << " " << fire[fiIdx].second;
            return;
        }
    }return;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);cout.tie(0);
    solve();
    return 0;
}