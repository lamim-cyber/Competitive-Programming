#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

// Number of ways to reach to n using any positive integer

const int mod = 1e9 + 7;
const int N = 2e6 + 10;
int dp[N];

int number_of_ways(int n){
    if(n == 0){
        return 1;
    }
  
    if(dp[n] != 0){
        return dp[n];
    }
  
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += number_of_ways(n - i);
        ans %= mod;
    }
    dp[n] = ans;
    return dp[n];
}

void solve(int test) {
    int n ;
    cin >> n;
    cout << number_of_ways(n) << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
