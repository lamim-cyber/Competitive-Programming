#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 2e5 + 10;
vector<int> G[N]; // adj_list of the graph
vector<int> path; // BFS traversal path
bitset<N> visited;//stores if the node is visited or not

void solve(int test){

    int n , e; // number of nodes and edges
    cin >> n >> e;

    for(int i = 1; i <= e; i++){
        int x , y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    queue<int> q; // to implement BFS , we need a queue
    q.push(1); // starting from 1
  
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(!visited[v]){
            path.push_back(v);
            visited[v] = 1;
            for(auto x : G[v]){
                if(!visited[x]){
                    q.push(x);
                }
            }
        }
    }
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
// time Complexity O(V + E)
// flood fill 
// level wise traversal
// shortest path from one to another node (if not weighted) 
