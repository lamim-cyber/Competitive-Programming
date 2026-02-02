#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

// Number of ways to reach by adding 1 or 3

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int dp[N];

int number_of_ways(int n){
    if(n < 3){
        return 1;
    }

    if(n == 3){
        return 2;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    dp[n] = number_of_ways(n - 1) % mod + number_of_ways(n - 3) % mod;
    return dp[n] % mod ;

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
