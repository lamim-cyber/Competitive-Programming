const int N = 1e8 + 1;
vector<bool> vis(N);
vector<int> primes;

void sieve(){
    primes.push_back(2);
    //only iterating over odd number , because every even number except 2 is a composite number
    for(int i = 3; i < N; i += 2)vis[i] = 1;

    for(ll i = 3; i * i < N; i++){
        if(vis[i] == 1){
            for(ll j = i * i; j < N; j += (2 * i))vis[j] = 0;
        }
    } 
    for(int i = 3; i < N; i += 2){
        if(vis[i])primes.push_back(i);
    }
}
