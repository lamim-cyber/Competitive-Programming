#include <bits/stdc++.h>
#define ll long long
#define Will_of_D ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define nl '\n'
#define gap ' '
using namespace std;

int a , b , k;
vector<int> num;
ll dp[12][2][90][90];

void buil_num(int a){
    num.clear();
    while(a > 0){
        num.push_back(a % 10);
        a /= 10;
    }
    reverse(all(num));
}

ll digitdp(int pos , int t , int sum , int nmbr){
    if(pos == num.size()){
        if(sum % k == 0 and nmbr % k == 0)return 1;
        else return 0;
    }

    if(dp[pos][t][sum][nmbr] != -1){
        return dp[pos][t][sum][nmbr];
    }

    int lim = 0;

    if(t == 0){
        lim = num[pos];
    }else lim = 9;

    ll res = 0;

    for(int i = 0; i <= lim; i++){
        int nsum = sum ;
        int nnmbr = nmbr;
        int nt = t;

        if(t == 0 and i < lim)nt = 1;

        nsum += i;
        nsum %= k;
        nnmbr *= 10;
        nnmbr += i;
        nnmbr %= k;

        res += digitdp(pos + 1 , nt , nsum , nnmbr);
    }

    return dp[pos][t][sum][nmbr] = res;
}


void solve(int test){
    cin >> a >> b >> k;
    cout << "Case " << test << ": ";
    if(k > 90){
        cout << 0 << nl;
        return;
    }
    buil_num(b);
    memset(dp , -1 , sizeof(dp));

    ll val1 = digitdp(0 , 0 , 0 , 0);

    buil_num(a - 1);
    memset(dp , -1 , sizeof(dp));

    ll val2 = digitdp(0 , 0 , 0 , 0);

    cout << val1 - val2 << nl;
}

int main()
{
    Will_of_D
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
}
