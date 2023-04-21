// 21/04/23 // estudo de algoritmos da teoria dos numeros
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = 1e6+5;

int sieve[MAXN];

vector<ll> prime_factors(ll n){
    vector<ll> v;

    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            v.PB(i);
            n /= i;
        }
    }
    if(n>1) v.PB(n);
    
    return v;
}

void init_sieve(int n){
    for(int i=2; i<=n; i++){
        if(sieve[i]) continue;
    
        for(int j=2*i; j<=n; j+=i) sieve[j] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    
    int total=0;
    for(int i=1; i<=n; i++){
        total += (n/i) * i;
    }
    cout << total << endl;

    /* imprime todos os numeros primos de "1" ate "n"
    init_sieve(n);
    for(int i=2; i<=n; i++){
        if(sieve[i]==0) cout << i << " ";
    }
    cout << endl;
    */

    /* imprime a fatoracao em primos do numero "n"
    vector<ll> v = prime_factors(n);
    
    for(ll i: v){
        cout << i << " ";
    }
    cout << endl;
    */

    return 0;
}