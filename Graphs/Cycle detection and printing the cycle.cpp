#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 2e5 + 10;

vector<int> G[N] ;
bitset<N> visited;
int col[N] , par[N];
bool cycle;

void DFS(int v){
    col[v] = 1; // shuru hoise tar mane active 
    for(auto x : G[v]){
        if(!visited[x]){
            par[x] = v;
            visited[x] = true;
            DFS(x);
        }else if(col[x] == col[v]){
            cycle = true;
            vector<int> cyc;
            cyc.push_back(v);
            int n = par[v];
            while(n != v and n!=0){ // jare diye shuru hoise tar kono parent nai 
                cyc.push_back(n);
                n = par[n];
            }

            for(auto y : cyc)cout << y << gap;
            cout << nl;
        }
    }

    col[v] = 2; // dfs shesh hole vinno color
}

void solve(int test){

    int n , m;
    cin >> n >> m;
    while(m--){
        int x , y;
        cin >> x >> y;
        G[x].push_back(y);
    }

    visited[1] = true;
    DFS(1);
    if(cycle)cout << "Cycle Exist" << nl;
    else
        cout<<"Cycle doesnt exist";

}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i); 
}
