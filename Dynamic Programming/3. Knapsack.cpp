#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int N = 200;
const int M = 1e5 + 10;
ll n , p;
ll w[N] , v[N];
ll dp[N][M];

ll knapsack(ll i , ll tot){
    if(i == n + 1) return 0;
    if(dp[i][tot] != -1) return dp[i][tot];
  
    ll ans = knapsack(i + 1 , tot);
    if(tot + w[i] <= p) ans = max(ans , knapsack(i + 1 , tot + w[i]) + v[i]);

    dp[i][tot] = ans;
    return dp[i][tot];
}

void solve(int test) {
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    memset(dp , -1 , sizeof dp);
    cout << knapsack(1 , 0) << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
//https://atcoder.jp/contests/dp/tasks/dp_d
