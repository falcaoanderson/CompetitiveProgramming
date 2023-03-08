// 29/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n;
vector<ll> v;

int check(ll maxi){ // retorna o minimo de divisões com esse maximo de soma de um subarray
    ll atual = 0LL;
    int k_atual = 1;

    for(int i=0; i<n; i++){
        if(atual+v[i]<=maxi){ // adiciono o no mesmo subarray
            atual += v[i];
        }
        else{
            if(v[i]<=maxi) atual = v[i]; // crio outro subarray
            else return INF; // impossivel
            k_atual++;
        }
    }

    return k_atual;
}

int main(){
    fast_io;

    int k;
    cin >> n >> k;

    ll sum = 0LL;
    v.resize(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }

    ll ini = 1LL, fim=sum, meio, resp = 0LL;

    while(ini<=fim){
        meio = (ini+fim)/2;
        
        // se a quantidade minima de subarrays com esse limite de soma eh menor ou igual a K, essa eh uma solve possivel
        if(check(meio)<=k){ 
            resp = meio; 
            fim = meio-1;       // tento diminuir a resposta
        }
        // se nao, aumento o limite de soma de um subarray
        else{
            ini = meio+1;
        }
    }
    
    cout << resp << endl;

    return 0;
}
