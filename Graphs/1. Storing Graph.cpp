#include <bits/stdc++.h>
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(int test){

    int n , e;
    cin >> n >> e; // n = number of nodes , e = number of edges
    
    vector<int> adj_list[n];
  //list : 1. memory optimization , just storing the neighbours not everyone
        // 2. better , 3 . list er moto store hobe , order doesnt matter
    int adj_matrix[n + 1][n + 1];
  //matrix : 1. directly duita node er connection jana jay , 1 hole connected , 0  hole disconnected
          // 2. memeory beshi lage , 3 . 2D matrix of 0 or 1

    for(int i = 0 ; i <= n; i++){
        for(int j = 0; j <= n; j++)a[i][j] = 0; // age shob kichu 0 diye initialized
    }

    for(int i = 1; i <= e; i++){
        int x , y;
        cin >> x >> y;
      //if undirected , mane x theke y te jawa jabe and y theke x a jawa jabe
      //mane holo x y er neighbour and y x er neighbour
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
        adj_matrix[x][y] = 1;
        adj_matrix[y][x] = 1;
      //if directed , mane shudhu x theke y te jawa jabe but y theke x a asha jabe na
      // just y holo x er neighbour
        adj_list[x].push_back(y);
        adj_matrix[x][y] = 1;
    }

}

int main()
{
    Will_of_D
    int test = 1;
    for(int i = 1; i <= test; i++)
        solve(i);
}
