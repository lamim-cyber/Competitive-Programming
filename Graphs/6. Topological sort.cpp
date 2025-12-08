#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl '\n'
#define gap ' '
using namespace std;

const int N = 2e5 + 10;

vector<int> G[N] ;
int indeg[N];
bitset<N> visited;

void solve(int test){

    int n , m;
    cin >> n >> m;
    while(m--){
        int x , y;
        cin >> x >> y;
        indeg[y]++; // y te ekta edge dhukse
        G[x].push_back(y); // jehetu directed graph tai just x theke y te jabe 
    }
    vector<int> ans , zero_indeg;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            zero_indeg.push_back(i); // 0 indegree wala gula age newa jabe
            visited[i] = true;
        }
    }
    while(ans.size() < n){
        if(zero_indeg.size() == 0){
            cout << "Not possible" << nl; // kono indegree 0 nai , tar mane directed cycle ache
            return;
        }
        int x = zero_indeg.back();
        zero_indeg.pop_back();
        ans.push_back(x);
        for(auto v : G[x]){
            indeg[v]--;
            if(!visited[v] and indeg[v] == 0){
                zero_indeg.push_back(v);
            }
        }
    }
    for(auto x : ans)cout << x << gap;
    cout << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
//complexity O(V + E)
// ekta node newar age jodi shorto thake arrekta nite hobe , tahole top sort korte hobe , tahole k age r k pore bujha jabe 
// Kahn's algorithm
