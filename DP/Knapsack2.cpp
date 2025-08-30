#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll maxn = 1e5+2;
const ll mod = 1e9+7;
const ll inf = 1e18;

ll n, w, h[102], v[102];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    for(int i= 0; i <n;i++)cin >> h[i] >> v[i];

    ll V = 0;
    for(int i = 0; i < n;i++)V+=v[i];

    vector<ll> dp(V+1, inf);
    dp[0] = 0;

    for(int i = 0; i < n;i++){
        for(int val = V; val >= v[i]; val--){
            dp[val] = min(dp[val], dp[val-v[i]]+h[i]);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= V; i++){
        if (dp[i] <= w)ans = i;
    }
    cout << ans;
}

