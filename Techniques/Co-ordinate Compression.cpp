#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define all(v) v.begin(),v.end()
#define gap ' '
using namespace std;

// duita approach ache , map r set er ta might be slow

void solve(int test) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> v = a;

    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    // set er moto ekhane unique vector ta pawa jabe tao abar 
    // sorted , so index janlei holo compress korar jonno

    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(all(v) , a[i]) - v.begin();
    }

    for(int i = 1; i <= n; i++)cout << a[i] << gap;

    set<int> s;
    for(int i = 1; i <= n; i++)s.insert(a[i]);
    map<int , int > m;
    int id = 0;
    for(auto x : s){
        m[x] = ++id;
    }

    for(int i = 1; i <= n; i++)a[i] = m[a[i]];

    for(int i = 1; i <= n; i++)cout << a[i] << gap;

}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
