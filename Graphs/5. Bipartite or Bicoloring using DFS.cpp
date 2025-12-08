#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
using namespace std;

const int N = 2e5 + 10;

vector<int> G[N] ;
int col[N];
bitset<N> visited;
bool pos;

void DFS(int n){
    for(auto x : G[n]){
        if(!visited[x]){
            col[x] = col[n] ^ 1; // parent r child er color alada hobe
            visited[n] = true;
            DFS(x);
        }else {
            if(col[x] == col[n]){
                pos = false; // jodi same thake tahole bad
            }
        }
    }
}

void solve(int test){

    int n , m;
    cin >> n >> m;
    while(m--){
        int x , y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    visited[1] = true;
    pos = true;
    DFS(1);
    if(pos)yes
    else no
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
