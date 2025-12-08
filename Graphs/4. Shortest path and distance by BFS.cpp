#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define all(v) v.begin(),v.end()
#define nl '\n'
#define gap ' '
using namespace std;
const int N = 2e5 + 10;

vector<int> G[N] ; // storing the graph (adj lists)
int dis[N] , par[N]; // distance count array , parent array
bitset<N> visited; // visited or not

void solve(int test){

    int n , m; // number of nodes and edges 
    cin >> n >> m;
    while(m--){
        int x , y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    queue<int> q;
    q.push(1); // starting bfs from 1 , it can be any node
    visited[1] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto y : G[x]){
            if(!visited[y]){
                dis[y] = dis[x] + 1; // y er parent holo x , r jekhan theke hishab kortesi oikhan theke y er distance hobe parent + 1
                par[y] = x; // y er parent holo x , path print korar jonno lagbe
                q.push(y);
                visited[y] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++)cout << dis[i] << gap; // node 1 theke index wise shobar distance peye jabo
    cout << nl;
    
    vector<int> path;
    int v ;
    cin >> v;
    while(v != 1){ // jehetu bfs 1 theke chalaisi tai 1 thekei path ber korte hobe
        path.push_back(v);
        v = par[v];
    }
    path.push_back(1);
    reverse(all(path));
    
    for(auto x : path)cout << x << gap;
    cout << nl;

}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i); 
}
