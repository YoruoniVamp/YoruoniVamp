// YT - YoruoniVamp (VTube)

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define cint const int
#define cf const float

int n, m, a, pos;
string s;
vector<int> v, tmp;

void show();
void add(int,int);
void del1(int);
void deln(vector<int>);
void rev();

void show(){
    for(auto i: v) cout << i << " ";
    cout << endl;
    return;
}

void add(int i, int p){
    v.insert(v.begin()+p,a);
    return;
}

void del1(int p){
    v.erase(v.begin()+p);
    return;
}

void deln(vector<int> t){
    vector<pair<int,int>> vt(v.size());
    for(int i = 0; i < v.size(); i++){
        vt[i].first = v[i];
        vt[i].second = i;
    }for(auto i: t){
        for(int j = 0; j < v.size(); j++){
            if(vt[j].second==i){
                vt.erase(vt.begin()+j);
                break;
            }
        }
    }v.clear();
    for(auto [u,w]: vt){
        v.push_back(u);
    }return;
}

void rev(){
    for(int i = 0; i < v.size()/2; i++) swap(v[i],v[v.size()-1-i]);
    return;
}

void solve(){
    cin >> s;
    if(s=="add"){
        cin >> a >> pos;
        add(a,pos);
    }else if(s=="delete1"){
        cin >> pos;
        del1(pos);
    }else if(s=="deleteN"){
        cin >> n;
        tmp.clear();
        while(n--){
            cin >> a;
            tmp.push_back(a);
        }deln(tmp);
    }else if(s=="rev") rev();
    show();
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        v.push_back(a);
    }cin >> m;
    while(m--) solve();
    return 0;
}