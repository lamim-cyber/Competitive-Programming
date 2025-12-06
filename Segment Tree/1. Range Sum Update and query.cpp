#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
using namespace std;

const int N = 2e5 + 10;
ll a[N] , t[4 * N]; // segment tree er j tree ta build hobe shegular node er number maximum 4 * node hote pare
                    // so ekhane j tree array ta nisi shetao 4 * N size er hobe
// building the tree
void build(int node , int b , int e){
    // noode represents the index of the array t and b represents the begin of the range
    // and e represents the end of that range
    if(b == e){
        t[node] = a[b];
        return;
    }

    int l = 2 * node; // left child node number of that node 
    int r = 2 * node + 1; // right child node number of that node
    int mid = (b + e) / 2; // divide the range into two parts

    build(l , b , mid); 
    build(r , mid + 1 , e);
   // build the left and right 

    t[node] = t[l] + t[r] ; // then add
}

ll query(int node , int b , int e , int i , int j){

  // i , j represents the range we want to know the sum
    if(e < i or b > j){
        return 0;
    } // ekdom e jodi bahire hoy , tahole kichu newar proyojon nai

    if(b >= i and e <= j){
        return t[node];
    } // purapuri bhitore hoole purata niye return 

  // purapuri bhitoreo nai , bahireo nai , tar mane intersect korse , 
  // so dui dikei jete hobe
    int l = 2 * node; 
    int r = 2 * node + 1;
    int mid = (b + e) / 2;
    return query(l , b , mid , i , j) + query(r , mid + 1 , e , i , j);
}
// update ta kind of query er motoi just , update a i == j
void update(int node , int b , int e , int i , int x){
    if(i < b or i > e)return; // purai bahire
    if(b == e and b == i){
        t[node] = x;
        return;
    } // puurai bahire

    int l = 2 * node;
    int r = 2 * node + 1;
    int mid = (b + e) / 2;
    update(l , b , mid , i , x); // dui pashei update 
    update(r , mid + 1, e , i , x);
    t[node] = t[l] + t[r]; // new node update
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
        if(x == 1){
            update(1 , 1 , n , y , z);
        }else {
            cout << query(1 , 1 , n , y , z) << nl;
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
//here , build , query , update shob kichui logn
