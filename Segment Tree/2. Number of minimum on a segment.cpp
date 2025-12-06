#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define F first
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 2e5 + 10;
const ll mx = 1e10 + 10;
ll a[N] ; // original array
pair<ll , int> t[4 * N];//store the minimum and how many times in a range

void build(int node , int b , int e){
    
    if(b == e){
        t[node] = {a[b] , 1} ; // on the leaf , it is the minimum and count is 1
        return;
    }

    int l = 2 * node; 
    int r = 2 * node + 1;
    int mid = (b + e) / 2;

    build(l , b , mid);
    build(r , mid + 1 , e);

    if(t[l].F == t[r].F){
        t[node] = {min(t[l].F , t[r].F) , t[l].S + t[r].S}; //if minimum is same , then add the count
    }else if(t[l].F < t[r].F){
        t[node] = t[l]; // if not , then keep the minimum
    }else {
        t[node] = t[r]; // same as before
    }
}

pair<ll , int> query(int node , int b , int e , int i , int j){
    if(e < i or b > j){
        return {mx , 0};
    } // purai bahire

    if(b >= i and e <= j){
        return t[node];
    } // purai bhitore

    int l = 2 * node; 
    int r = 2 * node + 1;
    int mid = (b + e) / 2;

    pair<ll,int> L = query(l , b , mid , i , j);
    pair<ll,int> R = query(r , mid + 1 , e , i , j);

    if (L.first == R.first) {
        return {L.first, L.second + R.second};
    } else if (L.first < R.first) {
        return L;
    } else {
        return R;
    }

}

void update(int node , int b , int e , int i , int x){
    if(i < b or i > e)return;
    if(b == e and b == i){
        t[node] = {x , 1};
        return;
    }

    int l = 2 * node;
    int r = 2 * node + 1;
    int mid = (b + e) / 2;
    update(l , b , mid , i , x);
    update(r , mid + 1, e , i , x);

    if(t[l].F == t[r].F){
        t[node] = {min(t[l].F , t[r].F) , t[l].S + t[r].S};
    }else if(t[l].F < t[r].F){
        t[node] = t[l];
    }else {
        t[node] = t[r];
    }
}

void solve(int test){

    int n , q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1 , 1 , n);
    while(q--){
        int x , y , z;
        cin >> x >> y >> z;
        y++;
        if(x == 1){
            update(1 , 1 , n , y , z);
        }else {
            pair<ll , int> p = query(1 , 1 , n , y, z);
            cout << p.F << gap << p.S << nl;
        }
    }

}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
    
}
