#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll maxn = 1e5+2;
const ll mod = 1e9+7;
const ll inf = 1e18;

class DisjointUnion{
    vector<ll> parent;
    vector<ll> size;
public:
    ll connected_component;
    DisjointUnion(ll Size){
        parent.resize(Size+1);
        size.resize(Size+1);
        connected_component = Size;
        for(int i = 1; i <= Size; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    ll find(ll num){
        ll temp = num;
        if (parent[num] != num){
            return parent[num] = find(parent[num]);
        }
        return num;
    }
    void union_set(ll a, ll b){
        ll arep = find(a);
        ll brep = find(b);
        if (arep == brep)return;
        connected_component--;
        ll asize = size[arep];
        ll bsize = size[brep];
        if (asize > bsize){
            parent[brep] = arep;
            size[arep]+=size[brep];
        }
        else{
            parent[arep] = brep;
            size[brep]+=size[arep];
        }
    }
};

bool comp(vector<ll> a, vector<ll> b){
    return a[2] < b[2];
}

ll n, m;
vector<vector<ll>> weights;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    DisjointUnion unionFind(n);
    for(int i = 0; i< m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        weights.push_back({a, b, c});
    }
    sort(weights.begin(), weights.end(), comp);
    ll res = 0;
    ll connect = unionFind.connected_component;
    for(vector<ll> weight : weights){
        unionFind.union_set(weight[0], weight[1]);
        if (connect != unionFind.connected_component){
            connect = unionFind.connected_component;
            res+=weight[2];
        }
    }
    if (connect != 1) cout << "IMPOSSIBLE";
    else cout << res;
}

