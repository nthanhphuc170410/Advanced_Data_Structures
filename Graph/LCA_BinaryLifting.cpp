#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll maxn = 1e5+2;
const ll mod = 1e9+7;
const ll inf = 1e18;

ll LOG = 20;
ll n, m;
vector<vector<ll>> tree;
vector<vector<ll>> up;
vector<ll> depth;

void dfs(ll cur, ll parent){
    up[cur].resize(LOG, -1);
    up[cur][0] = parent;

    for(int i = 1; i < LOG; i++){
        ll prev = up[cur][i-1];
        if (prev != -1)up[cur][i] = up[prev][i-1];
    }

    for(ll child : tree[cur]){
        depth[child] = depth[cur]+1;
        dfs(child, cur);
    }
}

ll getKthAncestor(ll cur, ll k){
    for(int i = 0 ; i < LOG; i++){
        if (k & (1LL << i)){
            cur = up[cur][i];
            if (cur == -1)return -1;
        }
    }
    return cur;
}
ll lca(ll a, ll b){
    if (depth[a] < depth[b])swap(a, b);

    a = getKthAncestor(a, depth[a]-depth[b]);
    if (a == b)return a;

    for(int i = LOG-1; i >= 0; i--){
        if (up[a][i] != -1 && up[b][i] != up[a][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >>m;
    tree.resize(n+1, {});
    up.resize(n+1, {});
    depth.resize(n+1, 0);
    for(int i = 2; i <= n; i++){
        ll num;
        cin >> num;
        tree[num].push_back(i);
    }
    dfs(1, -1);
    for(int i= 0; i< m;i++){
        ll a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

}

