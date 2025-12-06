#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 2e5 + 10;
vector<int> G[N]; // adj_list of the graph
vector<int> path; // DFS traversal path
bitset<N> visited;//stores if the node is visited or not

// recursive implementation of DFS (pre-order)

void DFS_pre(int n){
    path.push_back(n); //the program is to print the path , can be changed due to the problem
    visited[n] = 1; // mark as visited
    for(auto x : G[n]){
        if(!visited[x]){
            DFS_pre(x); // call the DFS if not visited
        }
    }
}

// recursive implementation of DFS (post-order)

void DFS_post(int n){
    visited[n] = 1; // mark as visited
    for(auto x : G[n]){
        if(!visited[x]){
            DFS_post(x); // call the DFS if not visited
        }
    }
    path.push_back(n); // in post-order , just visit it after hitting a dead-end(no neighbours to include)
}

void solve(int test){

    int n , e; // number of nodes and edges
    cin >> n >> e;
    for(int i = 1; i <= e; i++){
        int x , y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    DFS_pre(1); // recursive starting from 1
    DFS_post(1);
  
    stack<int> st; // DFS can be iterative using stack
    st.push(1); // starting from 1
    // Iterative implementation of DFS
    while(!st.empty()){
        int v = st.top();
        st.pop();
        if(!visited[v]){
            path.push_back(v); // motive here is to see the path
            visited[v] = 1; // mark as visited
            for(auto x : G[v]){
                if(!visited[x]) // if not marked , then push on the stack
                st.push(x);
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
// time complexiti O(V + E)
// Cycle detection 
// Connected Components 
// topological sort - DFS post-order reversal
// Generating Maze

