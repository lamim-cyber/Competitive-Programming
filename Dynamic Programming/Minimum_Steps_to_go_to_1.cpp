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
/* Given a number n , you have to calculate minimum steps to reach 1
you have 3 operations , either n - 1 , n / 2 , n / 3 */

const int N = 1e5 + 10;
int step1[N] , step2[N];

//Recursive
int min_steps(int n){
    if(n == 1)return 0;
    if(step1[n] != -1)return step1[n];

    int ans = min_steps(n - 1) + 1;
    if(n % 2 == 0){
        ans = min(ans , min_steps(n / 2) + 1);
    }
    if(n % 3 == 0){
        ans = min(ans , min_steps(n / 3) + 1);
    }
    step1[n] = ans;
    return step1[n];
}

void solve(int test) {
     int n ;
     cin >> n;
     memset(step1 , -1 , sizeof step1);
     memset(step2 , -1 , sizeof step2);
      
     cout << min_steps(n) << nl; // answer of rewcursive dp or top-down dp
     
     step2[1] = 0;
     //Iterative
     for(int i = 2; i <= n; i++){
        int ans = step2[i - 1] + 1;
        if(i % 2 == 0){
            ans = min(ans , step2[i / 2] + 1);
        }
        if(i % 3 == 0){
            ans = min(ans , step2[i / 3] + 1);
        }
        step2[i] = ans;
     }

     cout << step2[n] << nl; // answer of iterative dp or bottom-up dp
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
