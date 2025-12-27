#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
#define gap ' '
using namespace std;

void solve(int test){

    int n;
    cin >> n;

    cout << (1 << n)  - 1 << gap; // all bit on

    for(int i = 1; i <= n; i++){
        int val = 1 << (n - i); 
        for(int j = 0; j < (1 << i) ; j += 2){ // +2 karon just 1 ta bit e shoray
            cout << j * val + val - 1 << gap; // 1 ta kore bit shorai shorai value print kortese 
            //eta vanglei bujha jabe j shesher bit gula on rekhe baki kaj hoche
            // ekhane jodi shesher duita bit on thake tahole shesher duitake rekhe baki ekta ekta kore bit kore on kore kore print kortese jate maximum hoy
        }
    }
    cout << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i); 
}
//problem : https://codeforces.com/contest/2179/problem/D
