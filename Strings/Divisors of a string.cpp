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

//hashing er madhome prottek ta substring dekhsi , eki jodi hoy tahole oitai divisors

const int N = 1e6 + 9;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll p1 = 211;
const ll p2 = 223;
ll ss1[N] , ss2[N];
ll pw1[N] , pw2[N] , inv_pw1[N] , inv_pw2[N];

ll binexp(int n , int p , int mod){
    if(p == 0) return 1;

    ll res = binexp(n , p / 2 , mod);

    if(p % 2){
        return ((res * res) % mod) * n % mod;
    }else {
        return (res * res) % mod;
    }
}


void prec(){
    pw1[0] = 1;
    pw2[0] = 1;

    for(int i = 1; i < N; i++){
        pw1[i] = pw1[i - 1] * p1 % mod1;
        pw2[i] = pw2[i - 1] * p2 % mod2;
    }

    ll inv_p1 = binexp(p1 , mod1 - 2 , mod1);
    ll inv_p2 = binexp(p2 , mod2 - 2 , mod2);

    inv_pw1[0] = 1;
    inv_pw2[0] = 1;

    for(int i = 1; i < N; i++){
        inv_pw1[i] = inv_pw1[i - 1] * inv_p1 % mod1;
        inv_pw2[i] = inv_pw2[i - 1] * inv_p2 % mod2;
    }
}

pair<ll , ll> hash_string(string s){
    int n = s.size();

    pair<ll , ll> hs = {0 , 0};

    for(int i = 0; i < n; i++){
        hs.F += (s[i] - 'a' + 1) * pw1[i] % mod1;
        hs.F %= mod1;
        hs.S += (s[i] - 'a' + 1) * pw2[i] % mod2;
        hs.S %= mod2;
    }

    return hs;
}

void hash_substring(string s){
    int n = s.size();

    for(int i = 0; i < n; i++){
        ss1[i] = (s[i] - 'a' + 1) * pw1[i] % mod1;
        ss2[i] = (s[i] - 'a' + 1) * pw2[i] % mod2;

        if(i){
            ss1[i] = (ss1[i] + ss1[i - 1]) % mod1;
            ss2[i] = (ss2[i] + ss2[i - 1]) % mod2;
        }
    }
}

pair<ll , ll> get_hash(int i , int j){
    assert(i <= j);
    pair<ll , ll> hs = {0 , 0};
    if(i == 0){
        hs.F = ss1[j] % mod1;
        hs.S = ss2[j] % mod2;
    }else {
        hs.F = ((ss1[j] - ss1[i - 1] + mod1) % mod1) * inv_pw1[i] % mod1;
        hs.S = ((ss2[j] - ss2[i - 1] + mod2) % mod2) * inv_pw2[i] % mod2;
        hs.F %= mod1;
        hs.S %= mod2;
    }

    return hs;
}



void solve(int test){
    prec();
    string s;
    cin >> s;

    int n = s.size();

    hash_substring(s);
    pair<ll , ll> p = hash_string(s);
    vector<int> div;

    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            div.push_back(i);

            if(n / i != i)div.push_back(n / i);
        }
    }
  
    for(auto x : div){
        int ok = 1;
        pair<ll , ll> hs = get_hash(0 , x - 1);

        for(int i = 0; i < n; i += x){
            if(hs != get_hash(i , i + x - 1)){
                ok = 0;
                break;
            }
        }

        if(ok){
            for(int i = 0 ; i < x; i++)cout << s[i];
            cout << nl;
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
